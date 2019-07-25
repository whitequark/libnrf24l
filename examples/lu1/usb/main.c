// A simple demonstration of using USB on nRF24LU1.
//
// Note that currently this example does not implement all required standard requests and
// so it is not USB-compliant.

#include <stdint.h>
#include <string.h>
#include <usb.h>
#include <nrf24lu1/regs.h>
#include <nrf24lu1/usb.h>

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
  .idVendor             = 0x1915,
  .idProduct            = 0x0101,
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

// Work around silicon issue fetching code at addresses 0-4 when using bootloader.
void dummy() __interrupt(0) {}

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

  uint8_t config = 0;
  while(1) {
    if(EP0CS & 0x02) {
      __xdata struct usb_req_setup *setup = (__xdata struct usb_req_setup *)SETUPBUF;
      usb_buf_len = EP0BUF_LEN;
      switch(setup->bmRequestType|(setup->bRequest<<8)) {
        // Set Address
        case USB_RECIP_DEVICE|USB_TYPE_STANDARD|USB_DIR_OUT|(USB_REQ_SET_ADDRESS<<8):
          goto setup_ack; // Handled by hardware
        // Get Descriptor
        case USB_RECIP_DEVICE|USB_TYPE_STANDARD|USB_DIR_IN|(USB_REQ_GET_DESCRIPTOR<<8): {
          switch(setup->wValue>>8) {
            // Get Descriptor - Device
            case USB_DESC_DEVICE: {
              usb_xfer_ptr = (__xdata uint8_t *)usb_device;
              usb_xfer_len = sizeof(usb_device);
              goto desc_in;
            }
            // Get Descriptor - Configuration
            case USB_DESC_CONFIGURATION: {
              usb_xfer_ptr = (__xdata uint8_t *)usb_config;
              usb_xfer_len = sizeof(usb_config);
              goto desc_in;
            }
          }
          break;

        desc_in:
          if(usb_xfer_len > setup->wLength)
            usb_xfer_len = setup->wLength;
          while(usb_xfer_len > 0) {
            IN0BC = usb_copy_packet_to(IN0BUF);
            while(EP0CS & 4);
          }
          goto setup_ack;
        }
        // Set Configuration
        case USB_RECIP_DEVICE|USB_TYPE_STANDARD|USB_DIR_OUT|(USB_REQ_SET_CONFIGURATION<<8): {
          if(setup->wValue <= 1) {
            config = setup->wValue;
            goto setup_ack;
          }
        }
        // Get Configuration
        case USB_RECIP_DEVICE|USB_TYPE_STANDARD|USB_DIR_IN|(USB_REQ_GET_CONFIGURATION<<8): {
          IN0BUF[0] = config;
          IN0BC = 1;
          goto setup_ack;
        }
      }

    setup_stall:
      EP0CS = 0x11;
      continue;

    setup_ack:
      EP0CS = 0x02;
    }
  }
}
