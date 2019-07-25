#include <stdint.h>
#include <string.h>
#include <usb.h>
#include <nrf24lu1/regs.h>

enum boot_request {
  BOOT_REQ_READ    = 0x10,
  BOOT_REQ_WRITE   = 0x11,
  BOOT_REQ_ERASE   = 0x12,
  BOOT_REQ_ENABLE  = 0x13,
  BOOT_REQ_EXECUTE = 0x14,
  BOOT_REQ_RUN_APP = 0x15,
};

#define EP0BUF_LEN 64

_IOR(0xc700) IN0BUF[EP0BUF_LEN];
_IOR(0xc6c0) OUT0BUF[EP0BUF_LEN];

usb_desc_device_c usb_device = {
  .bLength              = sizeof(struct usb_desc_device),
  .bDescriptorType      = USB_DESC_DEVICE,
  .bcdUSB               = 0x0200,
  .bDeviceClass         = USB_DEV_CLASS_VENDOR,
  .bDeviceSubClass      = USB_DEV_SUBCLASS_VENDOR,
  .bDeviceProtocol      = USB_DEV_PROTOCOL_VENDOR,
  .bMaxPacketSize0      = EP0BUF_LEN,
  .idVendor             = BOOT_VID,
  .idProduct            = BOOT_PID,
  .bcdDevice            = 0x0000,
  .iManufacturer        = 0,
  .iProduct             = 0,
  .iSerialNumber        = 0,
  .bNumConfigurations   = 1,
};

__code struct {
  struct usb_desc_configuration config;
  struct usb_desc_interface interface;
} usb_config = {
  .config = {
    .bLength              = sizeof(struct usb_desc_configuration),
    .bDescriptorType      = USB_DESC_CONFIGURATION,
    .wTotalLength         = sizeof(usb_config),
    .bNumInterfaces       = 1,
    .bConfigurationValue  = 1,
    .iConfiguration       = 0,
    .bmAttributes         = USB_ATTR_RESERVED_1,
    .bMaxPower            = 50,
  },
  .interface = {
    .bLength              = sizeof(struct usb_desc_interface),
    .bDescriptorType      = USB_DESC_INTERFACE,
    .bInterfaceNumber     = 0,
    .bAlternateSetting    = 0,
    .bNumEndpoints        = 0,
    .bInterfaceClass      = USB_IFACE_CLASS_VENDOR,
    .bInterfaceSubClass   = USB_IFACE_SUBCLASS_VENDOR,
    .bInterfaceProtocol   = USB_IFACE_PROTOCOL_VENDOR,
    .iInterface           = 0,
  },
};

// Source or destination in XRAM, register-pinned to DPTR1.
_SFR16(0x8584) ep0_ptr;
// Total remaining bytes to transfer in current transaction.
uint16_t ep0_len;
// Total number of bytes in a descriptor (if any). Must be less than EP0BUF_LEN for descriptors,
// and exactly EP0BUF_LEN otherwise.
uint8_t  ep0_lim;
// Number of bytes copied to/from current packet.
uint8_t  ep0_pkt;

void copy_packet() __naked {
__asm
  mov   _ep0_pkt, #0
00001$:
  mov   a, #0xff
  dec   (_ep0_len+0)
  cjne  a, (_ep0_len+0), 00002$
  dec   (_ep0_len+1)
  cjne  a, (_ep0_len+1), 00002$
  xrl   (_ep0_len+0), a
  xrl   (_ep0_len+1), a
  ret ; reached transfer length
00002$:
  ; Copy byte
  movx  a, @dptr
  inc   dptr
  inc   _DPS
  movx  @dptr, a
  inc   dptr
  inc   _DPS
  ; In case this was a write to flash, wait until completion
00003$:
  jb    _RDYN, 00003$
  ; Increment packet size tally
  inc   _ep0_pkt
  mov   a, _ep0_pkt
  cjne  a, _ep0_lim, 00001$
  ret ; reached packet length
__endasm;
}

void copy_to_EP0() __naked {
__asm
  mov   dptr, #_IN0BUF
  inc   _DPS
  acall _copy_packet
  inc   _DPS
  ret
__endasm;
}

void copy_from_EP0() __naked {
__asm
  mov   dptr, #_OUT0BUF
  ajmp  _copy_packet
__endasm;
}

void run_app() __naked {
__asm
  ; jump to address 0 needs emulation
  mov   a, _DPH1
  orl   a, _DPL1
  cjne  a, #0, 00011$

00010$: ; jumping to address == 0 (in DPTR1)
  inc   _DPS
  movx  a, @dptr
  cjne  a, #0x02, 00013$ ; is it an ljmp?
  ; it is an ljmp; emulate its behavior
  inc   dptr
  movx  a, @dptr
  mov   _DPH0, a
  inc   dptr
  movx  a, @dptr
  mov   _DPL0, a
  inc   _DPS
  sjmp  00012$

00011$: ; jumping to address <> 0 (in DPTR1)
  mov   _DPH0, _DPH1
  mov   _DPL0, _DPL1

00012$: ; jumping to address <> 0 (in DPTR0)
  clr   _WEN
  clr   a
  jmp   @a+dptr

00013$: ; no valid ljmp
  inc   _DPS
  ret
__endasm;
}

void main() {
  USB_SWRST = 1;
  USB_SWRST = 0;
  USBCS = 8;

  BOUT1ADDR  = EP0BUF_LEN >> 1;
  BIN1ADDR   = EP0BUF_LEN >> 1;
  BINSTADDR  = EP0BUF_LEN >> 2;
  OUTBULKVAL = 1;
  INBULKVAL  = 1;

  // 50 ms delay, to re-enumerate
  TMOD = 0x01;
  T0   = 0;
  TF0  = 0;
  TR0  = 1;
  while(!TF0);
  USBCS = 0;

  // 4 s delay, to run user application
  uint8_t delay = 0;
  while(1) {
    if(TF0) {
      TF0 = 0;

      if(++delay == 80) {
        ep0_ptr = 0;
        run_app();
        // no application, stop trying
        TR0 = 0;
      }
    }

    if(EP0CS & 0x02) {
      __xdata struct usb_req_setup *setup = (__xdata struct usb_req_setup *)SETUPBUF;
      ep0_ptr = setup->wIndex;
      ep0_len = setup->wLength;
      ep0_lim = EP0BUF_LEN;
      uint8_t requestType = setup->bmRequestType;
      // Stop the timer if someone's talking to us.
      if(requestType & (USB_RECIP_DEVICE|USB_TYPE_VENDOR))
        TF0 = TR0 = 0;
      switch(requestType|(setup->bRequest<<8)) {
        // Set Address
        case USB_RECIP_DEVICE|USB_TYPE_STANDARD|USB_DIR_OUT|(USB_REQ_SET_ADDRESS<<8):
          goto setup_ack; // Handled by hardware
        // Get Descriptor
        case USB_RECIP_DEVICE|USB_TYPE_STANDARD|USB_DIR_IN|(USB_REQ_GET_DESCRIPTOR<<8): {
          switch(SETUPBUF[3] /* setup->wValue>>8 */) {
            // Get Descriptor - Device
            case USB_DESC_DEVICE: {
              ep0_ptr = (uint16_t)usb_device;
              ep0_lim = sizeof(usb_device);
              goto setup_in;
            }
            // Get Descriptor - Configuration
            case USB_DESC_CONFIGURATION: {
              ep0_ptr = (uint16_t)usb_config;
              ep0_lim = sizeof(usb_config);
              goto setup_in;
            }
          }
          break;
        }
        // Set Configuration
        case USB_RECIP_DEVICE|USB_TYPE_STANDARD|USB_DIR_OUT|(USB_REQ_SET_CONFIGURATION<<8):
          goto setup_ack; // We just pretend to implement it
        // Vendor - Read
        case USB_RECIP_DEVICE|USB_TYPE_VENDOR|USB_DIR_IN|(BOOT_REQ_READ<<8):
          goto setup_in;
        // Vendor - Write
        case USB_RECIP_DEVICE|USB_TYPE_VENDOR|USB_DIR_OUT|(BOOT_REQ_WRITE<<8):
          goto setup_out;
        // Vendor - Erase
        case USB_RECIP_DEVICE|USB_TYPE_VENDOR|USB_DIR_OUT|(BOOT_REQ_ERASE<<8): {
          FCR = DPH1 >> 1; // wIndex in DPTR1, shift by page size
          while(RDYN);
          goto setup_ack;
        }
        // Vendor - Enable
        case USB_RECIP_DEVICE|USB_TYPE_VENDOR|USB_DIR_OUT|(BOOT_REQ_ENABLE<<8): {
          WEN = 0;
          FCR = DPL1; // needs to be 0xAA
          FCR = DPH1; // needs to be 0x55
          WEN = 1;
          goto setup_ack;
        }
        // Vendor - Execute
        case USB_RECIP_DEVICE|USB_TYPE_VENDOR|USB_DIR_OUT|(BOOT_REQ_EXECUTE<<8):
          run_app();
      }

    setup_stall:
      EP0CS = 0x11;
      continue;

    setup_in:
      while(ep0_len) {
        copy_to_EP0();
        IN0BC = ep0_pkt;
        while(EP0CS & 4);
        if(ep0_lim != EP0BUF_LEN)
          break;
      }
      goto setup_ack;

    setup_out:
      while(ep0_len) {
        OUT0BC = 0;
        while(EP0CS & 8);
        copy_from_EP0();
      }
      goto setup_ack;

    setup_ack:
      EP0CS = 0x02;
      continue;
    }
  }
}
