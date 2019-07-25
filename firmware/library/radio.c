#include <nrf24l/radio.h>

extern __sbit _rf_RFCSN;

uint8_t rf_status() {
  uint8_t status;
  _rf_RFCSN = 0;
  status = rf_spi_xfer(RF_CMD_NOP);
  _rf_RFCSN = 1;
  return status;
}

uint8_t rf_cmd_read1(uint8_t cmd) {
  uint8_t data;
  _rf_RFCSN = 0;
  rf_spi_xfer(cmd);
  data = rf_spi_xfer(0xFF);
  _rf_RFCSN = 1;
  return data;
}

void rf_cmd_write1(uint8_t cmd, uint8_t data) {
  _rf_RFCSN = 0;
  rf_spi_xfer(cmd);
  rf_spi_xfer(data);
  _rf_RFCSN = 1;
}

void rf_cmd_readN(uint8_t cmd, uint8_t width, uint8_t *data) {
  _rf_RFCSN = 0;
  rf_spi_xfer(cmd);
  while(width--)
    *data++ = rf_spi_xfer(0xFF);
  _rf_RFCSN = 1;
}

void rf_cmd_writeN(uint8_t cmd, uint8_t width, const uint8_t *data) {
  _rf_RFCSN = 0;
  rf_spi_xfer(cmd);
  while(width--)
    rf_spi_xfer(*data++);
  _rf_RFCSN = 1;
}
