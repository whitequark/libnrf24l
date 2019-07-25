  .area HOME    (CODE)
  .area CSEG    (CODE)
  .area GSINIT0 (CODE)
  .area GSINIT1 (CODE)
  .area GSINIT2 (CODE)
  .area GSINIT3 (CODE)
  .area GSINIT4 (CODE)
  .area GSINIT5 (CODE)
  .area GSINIT  (CODE)
  .area GSFINAL (CODE)

  .globl __start__stack

  .area RSEG    (ABS,DATA)
  .org 0x0000
_DPL0 = 0x0082
_DPH0 = 0x0083
_DPL1 = 0x0084
_DPH1 = 0x0085
_DPS  = 0x0092
_STP  = 0x00FE

  .area GSINIT0 (CODE)

__sdcc_gsinit_startup::
  mov   sp, #(__start__stack-1)

  .area GSINIT1 (CODE)

  ; If we're running from unprotected flash, then relocate ourselves, so that the bootloader
  ; itself may be overwritten. (Careful!)
  ; If, however, we're running from protected flash, then run directly from ROM, which allows
  ; using the entire XDATA RAM area (2K) for non-volatile user firmware.
  jb    _STP, __startup

  ; The relocation process itself is quite cursed. 8051 does not have a way to read PC, nor
  ; does it usefully admit position-independent code; by using acall/ajmp (which take the top
  ; 5 bits from current PC) instead of lcall/ljmp and eliminating variables in PDATA/XDATA
  ; our code becomes relocatable by any offset that's a multiple of 2 KB. Because nRF24LU1
  ; has exactly 2 KB of RAM, we can relocate ourselves somewhere inside that block no matter
  ; which flash page we find ourselves in.

  ; Set DPTR0 to current PC, DPTR1 to relocation target, r1:r0 to firmware size.
  acall __relocate
__relocate::
  ; high bytes
  pop   _DPH0
  mov   a, _DPH0
  anl   a, #0x07
  orl   a, #0x80
  mov   _DPH1, a
  mov   r7, a ; remember DPH1
  mov   r1, #(0x200>>8)
  ; low bytes
  clr   a
  mov   _DPL0, a
  mov   _DPL1, a
  mov   r0, a

  ; Relocate!
00001$:
  movx  a, @dptr
  inc   dptr
  inc   _DPS
  movx  @dptr, a
  inc   dptr
  inc   _DPS
  djnz  r0, 00001$
  djnz  r1, 00001$

  ; Run!
  mov   _DPH0, r7
  mov   _DPL0, #__startup
  clr   a
  jmp   @a+dptr

__startup::

  .area GSINIT4 (CODE)

__mcs51_genRAMCLEAR::
  clr   a
  mov   r0, a
00010$:
  mov   @r0, a
  djnz  r0, 00010$
