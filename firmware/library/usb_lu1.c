#include <nrf24lu1/regs.h>

// Helper variables for usb_copy_packet().
__xdata uint8_t *usb_xfer_ptr;
uint16_t usb_xfer_len;
uint8_t  usb_buf_len;

// Copy bytes between XRAM and an USB buffer.
//
// This function copies up to `usb_xfer_len` or `usb_buf_len` bytes, whichever
// is smaller, between `usb_xfer_ptr` and `usb_buf_ptr`, with direction set by `DPS`.
// If `DPS` is 0, it reads from `usb_buf_ptr` and writes to `usb_xfer_ptr`;
// if `DPS` is 1, it reads from `usb_xfer_ptr` and writes to `usb_buf_ptr`.
//
// It returns the amount of bytes copied, to be written into the byte count register.
// After it returns, `usb_xfer_ptr` is incremented by the amount of bytes copied, and
// `usb_xfer_len` is decremented by the same amount.
uint8_t usb_copy_packet(__xdata uint8_t *usb_buf_ptr) __naked {
  usb_buf_ptr;
__asm
  ar0 = 0x0

  push  ar0
  mov   _DPL1, (_usb_xfer_ptr+0)
  mov   _DPH1, (_usb_xfer_ptr+1)
  ; Initialize packet size tally
  mov   r0, #0
00001$:
  mov   a, #0xff
  dec   (_usb_xfer_len+0)
  cjne  a, (_usb_xfer_len+0), 00002$
  dec   (_usb_xfer_len+1)
  cjne  a, (_usb_xfer_len+1), 00002$
  xrl   (_usb_xfer_len+0), a
  xrl   (_usb_xfer_len+1), a
  sjmp  00003$ ; reached xfer length
00002$:
  ; Copy byte
  movx  a, @dptr
  inc   dptr
  inc   _DPS
  movx  @dptr, a
  inc   dptr
  inc   _DPS
  ; Increment packet size tally
  inc   r0
  mov   a, r0
  cjne  a, _usb_buf_len, 00001$
  ; reached packet length
00003$:
  ; Return packet size
  mov   _DPS, #0
  mov   dpl, r0
  pop   ar0
  ret
__endasm;
}

uint8_t usb_copy_packet_from(__xdata uint8_t *usb_buf_ptr) __naked {
  usb_buf_ptr;
__asm
  sjmp  _usb_copy_packet
__endasm;
}

uint8_t usb_copy_packet_to(__xdata uint8_t *usb_buf_ptr) __naked {
  usb_buf_ptr;
__asm
  inc   _DPS
  sjmp  _usb_copy_packet
__endasm;
}
