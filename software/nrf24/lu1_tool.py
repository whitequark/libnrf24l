import re
import argparse
import collections
import usb1

from . import ihex


DEFAULT_VID = 0x1915
DEFAULT_PID = 0x0101

REQ_READ    = 0x10
REQ_WRITE   = 0x11
REQ_ERASE   = 0x12
REQ_ENABLE  = 0x13
REQ_EXECUTE = 0x14

PAGE_SIZE   = 0x200

TIMEOUT_MS  = 1000


class VID_PID(collections.namedtuple("VID_PID", "vid pid")):
    @classmethod
    def parse(cls, s):
        match = re.match(r"^([0-9a-f]{1,4}):([0-9a-f]{1,4})$", s, re.I)
        if not match:
            raise ValueError("{} is not a VID:PID pair".format(s))
        vid = int(match.group(1), 16)
        pid = int(match.group(2), 16)
        return cls(vid, pid)

    def __str__(self):
        return "{:04x}:{:04x}".format(self.vid, self.pid)


def get_argparser():
    def vid_pid(arg):
        try:
            return VID_PID.parse(arg)
        except ValueError:
            raise argparse.ArgumentTypeError("{} is not a VID:PID pair".format(arg))

    def int_with_base(arg):
        try:
            return int(arg, 0)
        except ValueError:
            raise argparse.ArgumentTypeError("{} is not an integer".format(arg))

    def hex_bytes(arg):
        return bytes.fromhex(arg)

    parser = argparse.ArgumentParser(description="""
    nRF24LU1(+) bootloader tool
    """)
    parser.add_argument(
        "-d", "--device", type=vid_pid, default=VID_PID(DEFAULT_VID, DEFAULT_PID),
        help="device VID:PID pair (default: %(default)s)")
    parser.add_argument(
        "-w", "--wait", default=False, action="store_true",
        help="wait until device is connected")

    subparsers = parser.add_subparsers(dest="action", metavar="COMMAND")

    p_read = subparsers.add_parser(
        "read", help="read a region of Flash ROM or RAM")
    p_read.add_argument(
        "address", metavar="ADDRESS", type=int_with_base,
        help="starting address")
    p_read.add_argument(
        "length", metavar="LENGTH", type=int_with_base,
        help="amount of bytes to read")
    p_read.add_argument(
        "file", metavar="FILENAME", type=argparse.FileType("wb"), nargs="?",
        help="read data to FILENAME")

    p_write = subparsers.add_parser(
        "write", help="write a region of Flash ROM or RAM")
    p_write.add_argument(
        "address", metavar="ADDRESS", type=int_with_base,
        help="starting address")
    g_write_data = p_write.add_mutually_exclusive_group(required=True)
    g_write_data.add_argument(
        "-f", "--file", metavar="FILENAME", type=argparse.FileType("rb"),
        help="write data from FILENAME")
    g_write_data.add_argument(
        "-d", "--data", metavar="DATA", type=hex_bytes,
        help="write hexadecimal bytes DATA")

    p_erase = subparsers.add_parser(
        "erase", help="erase a region of Flash ROM")
    p_erase.add_argument(
        "address", metavar="ADDRESS", type=int_with_base,
        help="starting address")
    p_erase.add_argument(
        "length", metavar="LENGTH", type=int_with_base, nargs="?", default=1,
        help="amount of bytes to erase")

    p_program = subparsers.add_parser(
        "program", help="program Intel HEX file to Flash ROM or RAM")
    p_program.add_argument(
        "file", metavar="FILENAME", type=argparse.FileType("r"),
        help="program Intel HEX file FILENAME")
    p_program.add_argument(
        "-r", "--run", default=False, action="store_true",
        help="run application after programming")

    p_execute = subparsers.add_parser(
        "execute", help="transfer control to specific address")
    p_execute.add_argument(
        "address", metavar="ADDRESS", type=int_with_base,
        help="jump to address ADDRESS")

    return parser


def wait_for_device(context, vid, pid):
    device = None
    def on_hotplug(context, event_device, event):
        nonlocal device
        if event == usb1.HOTPLUG_EVENT_DEVICE_ARRIVED:
            if event_device.getVendorID() == vid and event_device.getProductID() == pid:
                device = event_device
                return True
        return False

    callback = context.hotplugRegisterCallback(on_hotplug)
    while device is None:
        context.handleEvents()

    return device


def main():
    args = get_argparser().parse_args()

    try:
        with usb1.USBContext() as context:
            if args.wait:
                device = wait_for_device(context, *args.device)
            else:
                device = context.getByVendorIDAndProductID(*args.device)
            if device is None:
                raise SystemExit("Device not found")

            handle = device.open()
            handle.controlWrite(usb1.REQUEST_TYPE_VENDOR,
                REQ_ENABLE, 0, 0x55AA, b"", TIMEOUT_MS)

            if args.action == "read":
                data = handle.controlRead(usb1.REQUEST_TYPE_VENDOR,
                    REQ_READ, 0, args.address, args.length, TIMEOUT_MS)
                if args.file:
                    args.file.write(data)
                else:
                    print(data.hex())

            elif args.action == "write":
                if args.file:
                    data = args.file.read()
                else:
                    data = args.data
                handle.controlWrite(usb1.REQUEST_TYPE_VENDOR,
                    REQ_WRITE, 0, args.address, data, TIMEOUT_MS)

            elif args.action == "erase":
                for address in range(args.address, args.address + args.length, PAGE_SIZE):
                    handle.controlWrite(usb1.REQUEST_TYPE_VENDOR,
                        REQ_ERASE, 0, address, b"", TIMEOUT_MS)

            elif args.action == "program":
                erased = set()
                for address, chunk in ihex.read(args.file):
                    start_page = address & ~(PAGE_SIZE - 1)
                    end_page   = (address + len(chunk) + (PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1)
                    for page_address in range(start_page, end_page, PAGE_SIZE):
                        if page_address in erased:
                            continue
                        handle.controlWrite(usb1.REQUEST_TYPE_VENDOR,
                            REQ_ERASE, 0, page_address, b"", TIMEOUT_MS)
                        erased.add(page_address)

                    while len(chunk) > 0:
                        handle.controlWrite(usb1.REQUEST_TYPE_VENDOR,
                            REQ_WRITE, 0, address, chunk[:1024], TIMEOUT_MS)
                        address += 1024
                        chunk = chunk[1024:]

                if args.run:
                    try:
                        handle.controlWrite(usb1.REQUEST_TYPE_VENDOR,
                            REQ_EXECUTE, 0, 0, b"", 10)
                    except usb1.USBErrorTimeout:
                        pass # timeout means success here

            elif args.action == "execute":
                handle.controlWrite(usb1.REQUEST_TYPE_VENDOR,
                    REQ_EXECUTE, 0, args.address, b"", TIMEOUT_MS)

    except ValueError as e:
        raise SystemExit(str(e))

    except usb1.USBErrorPipe:
        raise SystemExit("Command failed")


if __name__ == "__main__":
    main()
