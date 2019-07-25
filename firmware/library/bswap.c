#include <stdint.h>

uint16_t bswap16(uint16_t value) __naked {
  value;
__asm;
  xch  a, dpl   ; 2c
  xch  a, dph   ; 2c
  xch  a, dpl   ; 2c
  ret           ; 4c
__endasm;
}

uint32_t bswap32(uint32_t value) __naked {
  value;
__asm;
  xch  a, dpl   ; 2c
  xch  a, b     ; 2c
  xch  a, dph   ; 2c
  xch  a, b     ; 2c
  ret           ; 4c
__endasm;
}
