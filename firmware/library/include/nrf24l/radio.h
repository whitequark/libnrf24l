#ifndef NRF24L_RADIO_H
#define NRF24L_RADIO_H

#include <stdint.h>

/**
 * \name RF transceiver commands
 * @{
 */
#define RF_CMD_R_REGISTER(n)       (0b00000000|(n))
#define RF_CMD_W_REGISTER(n)       (0b00100000|(n))
#define RF_CMD_R_RX_PL_WID          0b01100000
#define RF_CMD_R_RX_PAYLOAD         0b01100001
#define RF_CMD_W_TX_PAYLOAD         0b10100000
#define RF_CMD_W_ACK_PAYLOAD        0b10101000
#define RF_CMD_W_TX_PAYLOAD_NOACK   0b10110000
#define RF_CMD_FLUSH_TX             0b11100001
#define RF_CMD_FLUSH_RX             0b11100010
#define RF_CMD_REUSE_TX_PL          0b11100011
#define RF_CMD_NOP                  0b11111111
/**@}*/

/**
 * \name RF transceiver registers
 * @{
 */
#define RF_REG_CONFIG               0x00
#define RF_REG_EN_AA                0x01
#define RF_REG_EN_RXADDR            0x02
#define RF_REG_SETUP_AW             0x03
#define RF_REG_SETUP_RETR           0x04
#define RF_REG_RF_CH                0x05
#define RF_REG_RF_SETUP             0x06
#define RF_REG_STATUS               0x07
#define RF_REG_OBSERVE_TX           0x08
#define RF_REG_RPD                  0x09
#define RF_REG_RX_ADDR_P(n)        (0x0a+(n))
#define RF_REG_TX_ADDR              0x10
#define RF_REG_RX_PW_P(n)          (0x11+(n))
#define RF_REG_FIFO_STATUS          0x17
#define RF_REG_DYNPD                0x1c
#define RF_REG_FEATURE              0x1d
/**@}*/

/**
 * \name Bits from register RF_REG_CONFIG
 * @{
 */
#define RF_PRIM_RX        (1<<0)
#define RF_PWR_UP         (1<<1)
#define RF_CRCO           (1<<2)
#define RF_EN_CRC         (1<<3)
#define RF_MASK_MAX_RT    (1<<4)
#define RF_MASK_TX_DS     (1<<5)
#define RF_MASK_RX_DR     (1<<6)
/**@}*/

/**
 * \name Bits from register RF_REG_EN_AA
 * @{
 */
#define RF_ENAA_P0        (1<<0)
#define RF_ENAA_P1        (1<<1)
#define RF_ENAA_P2        (1<<2)
#define RF_ENAA_P3        (1<<3)
#define RF_ENAA_P4        (1<<4)
#define RF_ENAA_P5        (1<<5)
/**@}*/

/**
 * \name Bits from register RF_REG_EN_RXADDR
 * @{
 */
#define RF_ERX_P0         (1<<0)
#define RF_ERX_P1         (1<<1)
#define RF_ERX_P2         (1<<2)
#define RF_ERX_P3         (1<<3)
#define RF_ERX_P4         (1<<4)
#define RF_ERX_P5         (1<<5)
/**@}*/

/**
 * \name Fields from register RF_REG_SETUP_AW
 * @{
 */
#define RF_AW_2_BYTES     0b00
#define RF_AW_3_BYTES     0b01
#define RF_AW_4_BYTES     0b10
#define RF_AW_5_BYTES     0b11
/**@}*/

/**
 * \name Fields from register RF_REG_SETUP_RETR
 * @{
 */
#define RF_ARC(n)         (((n)&0b1111)<<0)
#define RF_ARD(n)         (((n)&0b1111)<<4)
/**@}*/

/**
 * \name Bits and fields from register RF_REG_RF_SETUP
 * @{
 */
#define RF_PWR_M18_DBM    (0b00<<1)
#define RF_PWR_M12_DBM    (0b01<<1)
#define RF_PWR_M6_DBM     (0b10<<1)
#define RF_PWR_0_DBM      (0b11<<1)

#define RF_DR_1_MBPS      ((0b0<<3)|(0b0<<5))
#define RF_DR_2_MBPS      ((0b1<<3)|(0b0<<5))
#define RF_DR_250_KBPS    ((0b0<<3)|(0b1<<5))

#define RF_PLL_LOCK       (1<<4)
#define RF_CONT_WAVE      (1<<7)
/**@}*/

/**
 * \name Bits and fields from register RF_REG_STATUS
 * @{
 */
#define RF_TX_FULL        (1<<0)
#define RF_RX_P_NO(v)     (((v)>>1)&0b111)
#define RF_MAX_RT         (1<<4)
#define RF_TX_DS          (1<<5)
#define RF_RX_DR          (1<<6)
/**@}*/

/**
 * \name Bits from register RF_REG_OBSERVE_TX
 * @{
 */
#define RF_ARC_CNT(v)     (((n)>>0)&0b1111)
#define RF_PLOS_CNT(v)    (((n)>>4)&0b1111)
/**@}*/

/**
 * \name Bits from register RF_REG_RPD
 * @{
 */
#define RF_RPD            (1<<0)
/**@}*/

/**
 * \name Bits from register RF_REG_FIFO_STATUS
 * @{
 */
#define RF_FIFO_RX_EMPTY  (1<<0)
#define RF_FIFO_RX_FULL   (1<<1)
#define RF_FIFO_TX_EMPTY  (1<<4)
#define RF_FIFO_TX_FULL   (1<<5)
#define RF_FIFO_TX_REUSE  (1<<6)
/**@}*/

/**
 * \name Bits from register RF_REG_DYNPD
 * @{
 */
#define RF_DPL_P0         (1<<0)
#define RF_DPL_P1         (1<<1)
#define RF_DPL_P2         (1<<2)
#define RF_DPL_P3         (1<<3)
#define RF_DPL_P4         (1<<4)
#define RF_DPL_P5         (1<<5)
/**@}*/

/**
 * \name Bits from register RF_REG_FEATURE
 * @{
 */
#define RF_EN_DYN_ACK     (1<<0)
#define RF_EN_ACK_PAY     (1<<1)
#define RF_EN_DPL         (1<<2)
/**@}*/

#pragma callee_saves rf_spi_xfer
#pragma callee_saves rf_read_status
#pragma callee_saves rf_read_reg
#pragma callee_saves rf_write_reg
#pragma callee_saves rf_write_addr

/**
 * Exchange a byte with RF transceiver via RF SPI bus.
 */
uint8_t rf_spi_xfer(uint8_t data);

/**
 * Read RF transceiver status register.
 *
 * Equivalent to `rf_reg_read1(RF_REG_STATUS)`, but faster.
 */
uint8_t rf_status();

/**
 * Read RF transceiver 1-byte command.
 */
uint8_t rf_cmd_read1(uint8_t cmd);

/**
 * Write RF transceiver 1-byte command.
 */
void rf_cmd_write1(uint8_t cmd, uint8_t value);

/**
 * Write RF transceiver arbitrary width command.
 */
void rf_cmd_readN(uint8_t cmd, uint8_t length, uint8_t *value);

/**
 * Write RF transceiver arbitrary width command.
 */
void rf_cmd_writeN(uint8_t cmd, uint8_t length, const uint8_t *value);

/**
 * Read RF transceiver 1-byte register.
 */
#define rf_reg_read1(reg) rf_cmd_read1(RF_CMD_R_REGISTER(reg))

/**
 * Write RF transceiver 1-byte register.
 */
#define rf_reg_write1(reg, value) rf_cmd_write1(RF_CMD_W_REGISTER(reg), value)

/**
 * Read RF transceiver arbitrary width register.
 */
#define rf_reg_readN(reg, length, value) rf_cmd_readN(RF_CMD_R_REGISTER(reg), length, value)

/**
 * Write RF transceiver arbitrary width register.
 */
#define rf_reg_writeN(reg, length, value) rf_cmd_writeN(RF_CMD_W_REGISTER(reg), length, value)

#endif
