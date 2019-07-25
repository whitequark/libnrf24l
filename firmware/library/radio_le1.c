#include <nrf24le1/regs.h>
#include <nrf24l/radio.h>

// exported for radio.c
__sbit __at(0xe8 + 1) _rf_RFCSN;

uint8_t rf_spi_xfer(uint8_t data) {
  SPIRDAT = data;
  while(!(SPIRSTAT & 0x2));
  return SPIRDAT;
}
