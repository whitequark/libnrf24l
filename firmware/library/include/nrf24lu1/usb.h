#ifndef NRF24LU1_USB_H
#define NRF24LU1_USB_H

#include <stdint.h>

// Helper variables for usb_copy_packet().
extern __xdata uint8_t *usb_xfer_ptr;
extern uint16_t usb_xfer_len;
extern uint8_t  usb_buf_len;

// Copy bytes from XRAM to an USB buffer.
//
// This function copies up to `usb_xfer_len` or `usb_buf_len` bytes, whichever is smaller,
// from `usb_xfer_ptr` to `usb_buf_ptr`. It returns the amount of bytes copied, to be written
// into the `IN` byte count register. After it returns, `usb_xfer_ptr` is incremented by
// the amount of bytes copied, and `usb_xfer_len` is decremented by the same amount.
uint8_t usb_copy_packet_from(__xdata uint8_t *usb_buf_ptr) __naked;

// Copy bytes from an USB buffer to XRAM.
//
// This function copies up to `usb_xfer_len` or `usb_buf_len` bytes, whichever is smaller,
// from `usb_buf_ptr` to `usb_xfer_ptr`. It returns the amount of bytes copied, to be written
// into the `OUT` byte count register. After it returns, `usb_xfer_ptr` is incremented by
// the amount of bytes copied, and `usb_xfer_len` is decremented by the same amount.
uint8_t usb_copy_packet_to(__xdata uint8_t *usb_buf_ptr) __naked;

#endif
