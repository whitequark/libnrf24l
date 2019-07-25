#include <nrf24lu1/regs.h>
#include <nrf24l/radio.h>

// exported for radio.c
__sbit __at(0x90 + 1) _rf_RFCSN;

uint8_t rf_spi_xfer(uint8_t data) {
  RFDAT = data;
  IRFRDY = 0;
  while(!IRFRDY);
  return RFDAT;
}
