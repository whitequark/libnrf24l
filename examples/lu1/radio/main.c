#include <stdint.h>
#include <nrf24lu1/regs.h>
#include <nrf24l/radio.h>

// Work around silicon issue fetching code at addresses 0-4 when using bootloader.
void dummy() __interrupt(0) {}

int main() {
  P0DIR &= ~(1<<5);
  P0_5 = 0;

  // Enable the transceiver.
  RFCKEN = 1;
  RFCTL  = 0x10;

  // Configure the transceiver. All of the following matches reset values.
  rf_reg_write1(RF_REG_RF_SETUP, RF_PWR_0_DBM|RF_DR_2_MBPS);
  rf_reg_write1(RF_REG_RF_CH, 2);
  rf_reg_write1(RF_REG_SETUP_AW, RF_AW_5_BYTES);
  const uint8_t addr[] = {0xE7,0xE7,0xE7,0xE7,0xE7};
  rf_reg_writeN(RF_REG_TX_ADDR, 5, addr);
  rf_reg_write1(RF_REG_CONFIG, RF_PWR_UP);

  // Write the payload.
  const uint8_t data[] = {0x01,0x02,0x03,0x04};
  rf_cmd_writeN(RF_CMD_W_TX_PAYLOAD, 4, data);

  // Transmit the payload.
  rf_reg_write1(RF_REG_STATUS, RF_MAX_RT|RF_TX_DS);
  RFCE = 1;
  while(!(rf_status() & RF_TX_DS));
  P0_5 = 1; // done!

  while(1);
}
