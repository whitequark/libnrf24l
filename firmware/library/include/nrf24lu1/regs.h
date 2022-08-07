#ifndef NRF24LU1_REGS_H
#define NRF24LU1_REGS_H

#include <stdint.h>

#ifndef DOXYGEN
#define _SFR(addr)   static __sfr __at (addr)
#define _SFR16(addr) static __sfr16 __at (addr)
#define _SBIT(addr)  static __sbit __at (addr)
#define _IOR(addr)   static __xdata __at (addr) volatile uint8_t
#define _IOR16(addr) static __xdata __at (addr) volatile uint16_t
#endif

_SFR(0x80) P0; ///< Port 0 Value
    _SBIT(0x80 + 0) P0_0; ///< Port 0 Value, bit 0
    _SBIT(0x80 + 1) P0_1; ///< Port 0 Value, bit 1
    _SBIT(0x80 + 2) P0_2; ///< Port 0 Value, bit 2
    _SBIT(0x80 + 3) P0_3; ///< Port 0 Value, bit 3
    _SBIT(0x80 + 4) P0_4; ///< Port 0 Value, bit 4
    _SBIT(0x80 + 5) P0_5; ///< Port 0 Value, bit 5
    _SBIT(0x80 + 6) P0_6; ///< Port 0 Value, bit 6
    _SBIT(0x80 + 7) P0_7; ///< Port 0 Value, bit 7
_SFR(0x81) SP; ///< Stack Pointer
_SFR(0x82) DPL0; ///< Data Pointer Low 0
_SFR(0x83) DPH0; ///< Data Pointer High 0
_SFR16(0x8382) DP0; //< Data Pointer 0
_SFR(0x84) DPL1; ///< Data Pointer Low 1
_SFR(0x85) DPH1; ///< Data Pointer High 1
_SFR16(0x8584) DP1; //< Data Pointer 1
_SFR(0x87) PCON; ///< Power Control Register
_SFR(0x88) TCON; ///< Timer/Counter Control Register
    _SBIT(0x88 + 0) IT0; ///< Timer/Counter Control Register, bit External Int0 Type Control
    _SBIT(0x88 + 1) IE0; ///< Timer/Counter Control Register, bit External Int0 Flag
    _SBIT(0x88 + 2) IT1; ///< Timer/Counter Control Register, bit External Int1 Type Control
    _SBIT(0x88 + 3) IE1; ///< Timer/Counter Control Register, bit External Int1 Flag
    _SBIT(0x88 + 4) TR0; ///< Timer/Counter Control Register, bit Timer0 Run Control
    _SBIT(0x88 + 5) TF0; ///< Timer/Counter Control Register, bit Timer0 Overflow Flag
    _SBIT(0x88 + 6) TR1; ///< Timer/Counter Control Register, bit Timer1 Run Control
    _SBIT(0x88 + 7) TF1; ///< Timer/Counter Control Register, bit Timer1 Overflow Flag
_SFR(0x89) TMOD; ///< Timer Mode Register
_SFR(0x8a) TL0; ///< Timer 0 Reload Register, low byte
_SFR(0x8b) TL1; ///< Timer 1 Reload Register, low byte
_SFR(0x8c) TH0; ///< Timer 0 Reload Register, high byte
_SFR(0x8d) TH1; ///< Timer 1 Reload Register, high byte
_SFR16(0x8c8a) T0; ///< Timer 0 Reload Register
_SFR16(0x8d8b) T1; ///< Timer 1 Reload Register
_SFR(0x8e) CKCON; ///< Cycle Control Register
_SFR(0x90) RFCON; ///< RF Transceiver Control Register
    _SBIT(0x90 + 0) RFCE; ///< RF Transceiver Control Register, bit Enable RF Transceiver
    _SBIT(0x90 + 1) RFCSN; ///< RF Transceiver Control Register, bit Enable RF Command
    _SBIT(0x90 + 2) RFCKEN; ///< RF Transceiver Control Register, bit Enable RF Clock
    // Unused bits 3:7
_SFR(0x92) DPS; ///< Data Pointer Select Register
_SFR(0x94) P0DIR; ///< Port 0 Pin Direction Control Register
_SFR(0x95) P0ALT; ///< Port 0 Pin Alternate Function Control Register
_SFR(0x98) S0CON; ///< Serial Port 0 Control Register
    _SBIT(0x98 + 0) RI0; ///< Serial Port 0 Control Register, bit Receive Interrupt Flag
    _SBIT(0x98 + 1) TI0; ///< Serial Port 0 Control Register, bit Transmit Interrupt Flag
    _SBIT(0x98 + 2) RB80; ///< Serial Port 0 Control Register, bit Receiver Bit 8
    _SBIT(0x98 + 3) TB80; ///< Serial Port 0 Control Register, bit Transmitter Bit 8
    _SBIT(0x98 + 4) REN0; ///< Serial Port 0 Control Register, bit Reception Enable
    _SBIT(0x98 + 5) SM20; ///< Serial Port 0 Control Register, bit Mode Select 2
    _SBIT(0x98 + 6) SM10; ///< Serial Port 0 Control Register, bit Mode Select 1
    _SBIT(0x98 + 7) SM00; ///< Serial Port 0 Control Register, bit Mode Select 0
_SFR(0x99) S0BUF; ///< Serial Port 0 Data Buffer
_SFR(0xa0) USBCON; ///< USB Control Register
    _SBIT(0xa0 + 5) USB_SUSPEND; ///< USB Control Register, bit USB Suspended
    _SBIT(0xa0 + 6) USB_WU; ///< USB Control Register, bit USB Wakeup
    _SBIT(0xa0 + 7) USB_SWRST; ///< USB Control Register, bit USB Reset
_SFR(0xa3) CLKCTL; ///< Clock Control Register
_SFR(0xa4) PWRDWN; ///< Power Down Control Register
_SFR(0xa5) WUCONF; ///< Wakeup Configuration Register
_SFR(0xa6) INTEXP; ///< Interrupt Expander Register
_SFR(0xa8) IEN0; ///< Interrupt Enable Register 0
    _SBIT(0xa8 + 0) EIFP; ///< Interrupt Enable Register 0, bit Enable Pin P0.3
    _SBIT(0xa8 + 1) ETF0; ///< Interrupt Enable Register 0, bit Enable Timer0 Overflow Interrupt
    _SBIT(0xa8 + 2) EPOF; ///< Interrupt Enable Register 0, bit Enable Pin P0.4 Interrupt
    _SBIT(0xa8 + 3) ETF1; ///< Interrupt Enable Register 0, bit Enable Timer1 Overflow Interrupt
    _SBIT(0xa8 + 4) ES0; ///< Interrupt Enable Register 0, Enable bit Serial Port 0 Interrupt
    _SBIT(0xa8 + 5) ETF2; ///< Interrupt Enable Register 0, bit Enable Timer2 Overflow Interrupt
    // Unused bit 6
    _SBIT(0xa8 + 7) EA; ///< Interrupt Enable Register 0, bit Enable Interrupts
_SFR(0xa9) IP0; ///< Interrupt Priority Register 0
_SFR(0xaa) S0RELL; ///< Serial Port 0 Reload Register, low byte
_SFR(0xab) REGXH; ///< Watchdog Data Register, low byte
_SFR(0xac) REGXL; ///< Watchdog Data Register, high byte
_SFR16(0xabac) REGX;  ///< Watchdog Data Register
_SFR(0xad) REGXC;  ///< Watchdog Control Register
_SFR(0xb1) RSTRES; ///< Reset Result Register
_SFR(0xb2) SMDAT; ///< SPI Master Data Register
_SFR(0xb3) SMCTRL; ///< SPI Master Control Register
_SFR(0xb5) TICKDV; ///< Tick Calibration Register
_SFR(0xb8) IEN1; ///< Interrupt Enable Register 1
    _SBIT(0xb8 + 0) ERFRDY; ///< Interrupt Enable Register 1, bit Enable RF SPI Ready Interrupt
    _SBIT(0xb8 + 1) ERFIRQ; ///< Interrupt Enable Register 1, bit Enable RF IRQ Interrupt
    _SBIT(0xb8 + 2) ESPI; ///< Interrupt Enable Register 1, bit Enable SPI Interrupt
    _SBIT(0xb8 + 3) EUSBWU; ///< Interrupt Enable Register 1, bit Enable USB Wakeup Interrupt
    _SBIT(0xb8 + 4) EUSB; ///< Interrupt Enable Register 1, bit Enable USB Interrupt
    _SBIT(0xb8 + 5) EWU; ///< Interrupt Enable Register 1, bit Enable Wakeup Interrupt
    // Unused bit 6
    _SBIT(0xb8 + 7) EEXF2; ///< Interrupt Enable Register 1, bit Enable Timer2 External Reload Int.
_SFR(0xb9) IP1; ///< Interrupt Priority Register 1
_SFR(0xba) S0RELH; ///< Serial Port 0 Reload Register, high byte
_SFR16(0xbaaa) S0REL; ///< Serial Port 0 Reload Register
_SFR(0xbc) SSCONF; ///< Slave SPI Configuration Register
_SFR(0xbd) SSDAT; ///< Slave SPI Data Register
_SFR(0xbe) SSSTAT; ///< Slave SPI Status Register
_SFR(0xc0) IRCON; ///< Interrupt Request Control Register
    _SBIT(0xc0 + 0) IRFRDY; ///< Interrupt Request Ctrl. Reg., bit RF SPI Ready Interrupt Flag
    _SBIT(0xc0 + 1) IRFIRQ; ///< Interrupt Request Ctrl. Reg., bit RF IRQ Interrupt Flag
    _SBIT(0xc0 + 2) ISPI; ///< Interrupt Request Ctrl. Reg., bit SPI Interrupt Flag
    _SBIT(0xc0 + 3) IUSBWU; ///< Interrupt Request Ctrl. Reg., bit USB Wakeup Interrupt Flag
    _SBIT(0xc0 + 4) IUSB; ///< Interrupt Request Ctrl. Reg., bit USB Interrupt Flag
    _SBIT(0xc0 + 5) IWU; ///< Interrupt Request Ctrl. Reg., bit Wakeup Interrupt Flag
    _SBIT(0xc0 + 6) ITF2; ///< Interrupt Request Ctrl. Reg., bit Timer2 Overflow Interrupt Flag
    _SBIT(0xc0 + 7) IEXF2; ///< Interrupt Request Ctrl. Reg., bit Timer2 External Reload Int. Flag
_SFR(0xc1) CCEN; ///< Compare/Capture Enable Register
_SFR(0xc2) CCL1; ///< Compare/Capture Register 1, low byte
_SFR(0xc3) CCH1; ///< Compare/Capture Register 1, high byte
_SFR16(0xc3c2) CC1; ///< Compare/Capture Register 1
_SFR(0xc4) CCL2; ///< Compare/Capture Register 2, low byte
_SFR(0xc5) CCH2; ///< Compare/Capture Register 2, high byte
_SFR16(0xc5c4) CC2; ///< Compare/Capture Register 2
_SFR(0xc6) CCL3; ///< Compare/Capture Register 3, low byte
_SFR(0xc7) CCH3; ///< Compare/Capture Register 3, high byte
_SFR16(0xc7c6) CC3; ///< Compare/Capture Register 3
_SFR(0xc8) T2CON; ///< Timer 2 Control Register
    _SBIT(0xc8 + 0) T2I0; ///< Timer 2 Control Register, bit Timer2 Input Select 0
    _SBIT(0xc8 + 1) T2I1; ///< Timer 2 Control Register, bit Timer2 Input Select 1
    _SBIT(0xc8 + 2) T2CM; ///< Timer 2 Control Register, bit Timer2 Compare Mode
    _SBIT(0xc8 + 3) T2R0; ///< Timer 2 Control Register, bit Timer2 Reload Mode 0
    _SBIT(0xc8 + 4) T2R1; ///< Timer 2 Control Register, bit Timer2 Reload Mode 1
    _SBIT(0xc8 + 5) I2FR; ///< Timer 2 Control Register, bit Interrupt2 Edge Select
    _SBIT(0xc8 + 6) I3FR; ///< Timer 2 Control Register, bit Interrupt3 Edge Select
    _SBIT(0xc8 + 7) T2PS; ///< Timer 2 Control Register, bit Timer2 Prescaler Select
_SFR(0xc9) P0EXP; ///< Port 0 Pin Expanded Function Control Register
_SFR(0xca) CRCL; ///< Compare/Reload/Capture Register, low byte
_SFR(0xcb) CRCH; ///< Compare/Reload/Capture Register, high byte
_SFR16(0xcbca) CRC; ///< Compare/Reload/Capture Register
_SFR(0xcc) TL2; ///< Timer 2 Reload Register, low byte
_SFR(0xcd) TH2; ///< Timer 2 Reload Register, high byte
_SFR16(0xcdcc) T2; ///< Timer 2 Reload Register
_SFR(0xd0) PSW; ///< Program Status Word
    _SBIT(0xd0 + 0) P; ///< Program Status Word, bit P
    _SBIT(0xd0 + 1) F1; ///< Program Status Word, bit F1
    _SBIT(0xd0 + 2) OV; ///< Program Status Word, bit OV
    _SBIT(0xd0 + 3) RS0; ///< Program Status Word, bit RS0
    _SBIT(0xd0 + 4) RS1; ///< Program Status Word, bit RS1
    _SBIT(0xd0 + 5) F0; ///< Program Status Word, bit F0
    _SBIT(0xd0 + 6) AC; ///< Program Status Word, bit AC
    _SBIT(0xd0 + 7) CY; ///< Program Status Word, bit CY
_SFR(0xd8) WDCON; ///< Serial Port 0 Baud Rate Select Register
    // Unused bits 0:6
    _SBIT(0xd8 + 7) BD; ///< Serial Port 0 Baud Rate Select Register, bit Use Internal Baud Rate
_SFR(0xd9) USBSLP; ///< USB Sleep Register
_SFR(0xe0) ACC; ///< Accumulator
    _SBIT(0xe0 + 0) ACC0; ///< Accumulator, bit 0
    _SBIT(0xe0 + 1) ACC1; ///< Accumulator, bit 1
    _SBIT(0xe0 + 2) ACC2; ///< Accumulator, bit 2
    _SBIT(0xe0 + 3) ACC3; ///< Accumulator, bit 3
    _SBIT(0xe0 + 4) ACC4; ///< Accumulator, bit 4
    _SBIT(0xe0 + 5) ACC5; ///< Accumulator, bit 5
    _SBIT(0xe0 + 6) ACC6; ///< Accumulator, bit 6
    _SBIT(0xe0 + 7) ACC7; ///< Accumulator, bit 7
_SFR(0xe5) RFDAT; ///< RF Transceiver SPI Interface Data Register
_SFR(0xe6) RFCTL; ///< RF Transceiver SPI Interface Control Register
_SFR(0xe8) AESCS; ///< AES Command/Status Register
    _SBIT(0xe8 + 0) AES_GO; ///< AES Command/Status Register, bit Start Operation
    _SBIT(0xe8 + 1) AES_DECR; ///< AES Command/Status Register, bit Decrypt
    _SBIT(0xe8 + 2) AES_MODE0; ///< AES Command/Status Register, bit AES Mode 0
    _SBIT(0xe8 + 3) AES_MODE1; ///< AES Command/Status Register, bit AES Mode 1
    _SBIT(0xe8 + 4) AES_MODE2; ///< AES Command/Status Register, bit AES Mode 2
_SFR(0xe9) MD0; ///< Multiplication/Division Register 0
_SFR(0xea) MD1; ///< Multiplication/Division Register 1
_SFR(0xeb) MD2; ///< Multiplication/Division Register 2
_SFR(0xec) MD3; ///< Multiplication/Division Register 3
_SFR(0xed) MD4; ///< Multiplication/Division Register 4
_SFR(0xee) MD5; ///< Multiplication/Division Register 5
_SFR(0xef) ARCON; ///< Arithmetic Control Register
_SFR(0xf0) B; ///< B Register
    _SBIT(0xf0 + 0) B0; ///< B Register, bit 0
    _SBIT(0xf0 + 1) B1; ///< B Register, bit 1
    _SBIT(0xf0 + 2) B2; ///< B Register, bit 2
    _SBIT(0xf0 + 3) B3; ///< B Register, bit 3
    _SBIT(0xf0 + 4) B4; ///< B Register, bit 4
    _SBIT(0xf0 + 5) B5; ///< B Register, bit 5
    _SBIT(0xf0 + 6) B6; ///< B Register, bit 6
    _SBIT(0xf0 + 7) B7; ///< B Register, bit 7
_SFR(0xf1) AESKIN; ///< AES Key In Register
_SFR(0xf2) AESIV; ///< AES Initialization Vector Register
_SFR(0xf3) AESD; ///< AES Data In/Out Register
_SFR(0xf5) AESIA1; ///< AES Indirect Address Register 1
_SFR(0xf6) AESIA2; ///< AES Indirect Address Register 2
_SFR(0xf8) FSR; ///< Flash Status Register
    _SBIT(0xf8 + 1) RDISIP; ///< Flash Status Register, bit Flash IP Readback Protection Enabled
    _SBIT(0xf8 + 2) RDISMB; ///< Flash Status Register, bit Flash MB Readback Protection Enabled
    _SBIT(0xf8 + 3) INFEN; ///< Flash Status Register, bit Flash IP Enable
    _SBIT(0xf8 + 4) RDYN; ///< Flash Status Register, bit Flash Ready Flag
    _SBIT(0xf8 + 5) WEN; ///< Flash Status Register, bit Flash Write Enable Latch
    _SBIT(0xf8 + 6) STP; ///< Flash Status Register, bit Start From Protected Area
    _SBIT(0xf8 + 7) DBG; ///< Flash Status Register, bit Hardware Debug Features Enabled
_SFR(0xf9) FPCR; ///< Flash Protect Configuration Register
_SFR(0xfa) FCR; ///< Flash Command Register

/**
 * \name Bits from register PCON
 * @{
 */
#define _IDLE       (1u<<0) ///< Power Control Register, bit Idle Mode Control
#define _STOP       (1u<<1) ///< Power Control Register, bit Stop Mode Control
#define _GF0        (1u<<2) ///< Power Control Register, bit General Purpose Flag 0
#define _GF1        (1u<<3) ///< Power Control Register, bit General Purpose Flag 1
#define _PMW        (1u<<4) ///< Power Control Register, bit Program Memory Write Mode
#define _GF2        (1u<<5) ///< Power Control Register, bit General Purpose Flag 2
#define _GF3        (1u<<6) ///< Power Control Register, bit General Purpose Flag 3
#define _SMOD       (1u<<7) ///< Power Control Register, bit Serial Port 0 Baud Rate Select
/**@}*/

/**
 * \name Bits from register TMOD
 * @{
 */
#define _MODE0_0    (1u<<0) ///< Timer Mode Register, bit Timer 0 Mode 0
#define _MODE0_1    (1u<<1) ///< Timer Mode Register, bit Timer 0 Mode 1
#define _CT0        (1u<<2) ///< Timer Mode Register, bit Timer 0 Counter/Timer Select
#define _GATE0      (1u<<3) ///< Timer Mode Register, bit Timer 0 Gate Control
#define _MODE1_0    (1u<<4) ///< Timer Mode Register, bit Timer 1 Mode 0
#define _MODE1_1    (1u<<5) ///< Timer Mode Register, bit Timer 1 Mode 1
#define _CT1        (1u<<6) ///< Timer Mode Register, bit Timer 1 Counter/Timer Select
#define _GATE1      (1u<<7) ///< Timer Mode Register, bit Timer 1 Gate Control
/**@}*/

/**
 * \name Bits from register P0DIR
 * @{
 */
#define _P0DIR_0    (1u<<0) ///< P0DIR Register, bit Pin P0.0 Direction
#define _P0DIR_1    (1u<<1) ///< P0DIR Register, bit Pin P0.1 Direction
#define _P0DIR_2    (1u<<2) ///< P0DIR Register, bit Pin P0.2 Direction
#define _P0DIR_3    (1u<<3) ///< P0DIR Register, bit Pin P0.3 Direction
#define _P0DIR_4    (1u<<4) ///< P0DIR Register, bit Pin P0.4 Direction
#define _P0DIR_5    (1u<<5) ///< P0DIR Register, bit Pin P0.5 Direction
/**@}*/

/**
 * \name Bits from register P0ALT
 * @{
 */
#define _P0ALT_0    (1u<<0) ///< P0ALT Register, bit Alternate Function 0
#define _P0ALT_1    (1u<<1) ///< P0ALT Register, bit Alternate Function 1
#define _P0ALT_2    (1u<<2) ///< P0ALT Register, bit Alternate Function 2
#define _P0ALT_3    (1u<<3) ///< P0ALT Register, bit Alternate Function 3
#define _P0ALT_4    (1u<<4) ///< P0ALT Register, bit Alternate Function 4
#define _P0ALT_5    (1u<<5) ///< P0ALT Register, bit Alternate Function 5
/**@}*/

/**
 * \name Bits from register CLKCTL
 * @{
 */
#define _PLL0_0     (1u<<0) ///< CLKCTL Register, bit Set MCU Clock When PLL Is Off 0
#define _PLL0_1     (1u<<1) ///< CLKCTL Register, bit Set MCU Clock When PLL Is Off 1
#define _PLL1_0     (1u<<4) ///< CLKCTL Register, bit Set MCU Clock When PLL Is On 0
#define _PLL1_1     (1u<<5) ///< CLKCTL Register, bit Set MCU Clock When PLL Is On 1
#define _PLL1_2     (1u<<6) ///< CLKCTL Register, bit Set MCU Clock When PLL Is On 2
#define _PLLEN      (1u<<7) ///< CLKCTL Register, bit Enable PLL
/**@}*/

/**
 * \name Bits from register PWRDWN
 * @{
 */
#define _MCUSTBY_0  (1u<<0) ///< PWRDWN Register, bit Set MCU To Standby 0
#define _MCUSTBY_1  (1u<<1) ///< PWRDWN Register, bit Set MCU To Standby 1
#define _MCUSTBY_2  (1u<<2) ///< PWRDWN Register, bit Set MCU To Standby 2
#define _CKLFRD     (1u<<3) ///< PWRDWN Register, bit Read CKLF Clock
/**@}*/

/**
 * \name Bits from register WUCONF
 * @{
 */
#define _ENUSBWU_0  (1u<<0) ///< WUCONF Register, bit Enable Wakeup On USBWU 0
#define _ENUSBWU_1  (1u<<1) ///< WUCONF Register, bit Enable Wakeup On USBWU 1
#define _ENUSBIRQ_0 (1u<<2) ///< WUCONF Register, bit Enable Wakeup On USBIRQ 0
#define _ENUSBIRQ_1 (1u<<3) ///< WUCONF Register, bit Enable Wakeup On USBIRQ 1
#define _ENWU_0     (1u<<4) ///< WUCONF Register, bit Enable Wakeup On WU 0
#define _ENWU_1     (1u<<5) ///< WUCONF Register, bit Enable Wakeup On WU 1
#define _ENRFIRQ_0  (1u<<6) ///< WUCONF Register, bit Enable Wakeup On RFIRQ 0
#define _ENRFIRQ_1  (1u<<7) ///< WUCONF Register, bit Enable Wakeup On RFIRQ 1
/**@}*/

/**
 * \name Bits from register INTEXP
 * @{
 */
#define _SPIMASEN   (1u<<0) ///< INTEXP Register, bit Enable Master SPI Interrupt
#define _SPISLVEN   (1u<<1) ///< INTEXP Register, bit Enable Slave SPI Interrupt
/**@}*/

/**
 * \name Bits from register REGXC
 * @{
 */
#define _REGXIA_0   (1u<<0) ///< REGXC Register, bit Indirect Address 0
#define _REGXIA_1   (1u<<1) ///< REGXC Register, bit Indirect Address 1
#define _REGXIA_2   (1u<<2) ///< REGXC Register, bit Indirect Address 2
#define _REGXRW     (1u<<3) ///< REGXC Register, bit Read/Write
#define _REGXSTAT   (1u<<4) ///< REGXC Register, bit Last REGXC Write Access Status
/**@}*/

/**
 * \name Bits from register SMCTRL
 * @{
 */
#define _SPICKDIV_0 (1u<<0) ///< SMCTRL Register, bit SPI Clock Divider Factor 0
#define _SPICKDIV_1 (1u<<1) ///< SMCTRL Register, bit SPI Clock Divider Factor 1
#define _SPICKDIV_2 (1u<<2) ///< SMCTRL Register, bit SPI Clock Divider Factor 2
#define _SPICKDIV_3 (1u<<3) ///< SMCTRL Register, bit SPI Clock Divider Factor 3
#define _SPIEN      (1u<<4) ///< SMCTRL Register, bit Enable SPI
/**@}*/

/**
 * \name Bits from register IP0
 * @{
 */
#define _IP0_0      (1u<<0) ///< IP0 Register, bit Interrupt Priority Group 0 Priority 0
#define _IP0_1      (1u<<1) ///< IP0 Register, bit Interrupt Priority Group 1 Priority 0
#define _IP0_2      (1u<<2) ///< IP0 Register, bit Interrupt Priority Group 2 Priority 0
#define _IP0_3      (1u<<3) ///< IP0 Register, bit Interrupt Priority Group 3 Priority 0
#define _IP0_4      (1u<<4) ///< IP0 Register, bit Interrupt Priority Group 4 Priority 0
#define _IP0_5      (1u<<5) ///< IP0 Register, bit Interrupt Priority Group 5 Priority 0
/**@}*/

/**
 * \name Bits from register IP1
 * @{
 */
#define _IP1_0      (1u<<0) ///< IP1 Register, bit Interrupt Priority Group 0 Priority 1
#define _IP1_1      (1u<<1) ///< IP1 Register, bit Interrupt Priority Group 1 Priority 1
#define _IP1_2      (1u<<2) ///< IP1 Register, bit Interrupt Priority Group 2 Priority 1
#define _IP1_3      (1u<<3) ///< IP1 Register, bit Interrupt Priority Group 3 Priority 1
#define _IP1_4      (1u<<4) ///< IP1 Register, bit Interrupt Priority Group 4 Priority 1
#define _IP1_5      (1u<<5) ///< IP1 Register, bit Interrupt Priority Group 5 Priority 1
/**@}*/

/**
 * \name Bits from register SSCONF
 * @{
 */
#define _SSPIEN     (1u<<0) ///< SSCONF Register, bit Enable Slave SPI
#define _SSPIIRQ    (1u<<3) ///< SSCONF Register, bit Disable Slave SPI Interrupts
#define _SSPIIRQCSL (1u<<4) ///< SSCONF Register, bit Disable Interrupt When SCSN Goes Low
#define _SSPIIRQCSH (1u<<5) ///< SSCONF Register, bit Disable Interrupt When SCSN Goes High
/**@}*/

/**
 * \name Bits from register SSSTAT
 * @{
 */
#define _IRQSTATDB  (1u<<0) ///< SSSTAT Register, bit Interrupt Caused By Data Byte
#define _IRQSTATNE  (1u<<1) ///< SSSTAT Register, bit Interrupt Caused By SCSN Negative Edge
#define _IRQSTATPE  (1u<<2) ///< SSSTAT Register, bit Interrupt Caused By SCSN Positive Edge
/**@}*/

/**
 * \name Bits from register CCEN
 * @{
 */
#define _CCENCOCA00 (1u<<0) ///< CCEN Register, bit Compare/Capture Mode For CRC Register 0
#define _CCENCOCA01 (1u<<1) ///< CCEN Register, bit Compare/Capture Mode For CRC Register 1
#define _CCENCOCA10 (1u<<2) ///< CCEN Register, bit Compare/Capture Mode For CC1 Register 0
#define _CCENCOCA11 (1u<<3) ///< CCEN Register, bit Compare/Capture Mode For CC1 Register 1
#define _CCENCOCA20 (1u<<4) ///< CCEN Register, bit Compare/Capture Mode For CC2 Register 0
#define _CCENCOCA21 (1u<<5) ///< CCEN Register, bit Compare/Capture Mode For CC2 Register 1
#define _CCENCOCA30 (1u<<6) ///< CCEN Register, bit Compare/Capture Mode For CC3 Register 0
#define _CCENCOCA31 (1u<<7) ///< CCEN Register, bit Compare/Capture Mode For CC3 Register 1
/**@}*/

/**
 * \name Bits from register P0EXP
 * @{
 */
#define _P0EXP03_0  (1u<<0) ///< P0EXP Register, bit Pin P0.0-P0.3 Control 0
#define _P0EXP03_1  (1u<<1) ///< P0EXP Register, bit Pin P0.0-P0.3 Control 1
#define _P0EXP4_0   (1u<<4) ///< P0EXP Register, bit Pin P0.4 Control 0
#define _P0EXP4_1   (1u<<5) ///< P0EXP Register, bit Pin P0.4 Control 1
#define _P0EXP5_0   (1u<<6) ///< P0EXP Register, bit Pin P0.5 Control 0
#define _P0EXP5_1   (1u<<7) ///< P0EXP Register, bit Pin P0.5 Control 1
/**@}*/

/**
 * \name Bits from register RFCTL
 * @{
 */
#define _RFCTL0     (1u<<0) ///< RFCTL Register, bit MCU To SPI Clock Divider Factor 0
#define _RFCTL1     (1u<<1) ///< RFCTL Register, bit MCU To SPI Clock Divider Factor 1
#define _RFCTL2     (1u<<2) ///< RFCTL Register, bit MCU To SPI Clock Divider Factor 2
#define _RFCTL3     (1u<<3) ///< RFCTL Register, bit MCU To SPI Clock Divider Factor 3
#define _SS         (1u<<4) ///< RFCTL Register, bit SPI Enable
/**@}*/

/**
 * \name Bits from register ARCON
 * @{
 */
#define _SC0        (1u<<0) ///< ARCON Register, bit Shift Counter 0
#define _SC1        (1u<<1) ///< ARCON Register, bit Shift Counter 1
#define _SC2        (1u<<2) ///< ARCON Register, bit Shift Counter 2
#define _SC3        (1u<<3) ///< ARCON Register, bit Shift Counter 3
#define _SC4        (1u<<4) ///< ARCON Register, bit Shift Counter 4
#define _SLR        (1u<<5) ///< ARCON Register, bit Shift Direction
#define _MDOV       (1u<<6) ///< ARCON Register, bit MDU Overflow Flag
#define _MDEF       (1u<<7) ///< ARCON Register, bit MDU Error Flag
/**@}*/

/**
 * \name Bits from register FPCR
 * @{
 */
#define _DAEN       (1u<<7) ///< FPCR Register, bit Two Pages Of Data Memory Enabled
/**@}*/

_IOR(0xc440) USBBUF[768]; ///< Combined USB Buffers
_IOR(0xc760) OUT8DATA; ///< ISO OUT endpoint 8 data FIFO register
_IOR(0xc768) IN8DATA; ///< ISO IN endpoint 8 data FIFO register
_IOR(0xc770) OUT8BCH; ///< ISO OUT received byte count register high
_IOR(0xc771) OUT8BCL; ///< ISO OUT received byte count register low
_IOR(0xc781) BOUT1ADDR; ///< Bulk OUT endpoint 1 size register
_IOR(0xc782) BOUT2ADDR; ///< Bulk OUT endpoint 2 size register
_IOR(0xc783) BOUT3ADDR; ///< Bulk OUT endpoint 3 size register
_IOR(0xc784) BOUT4ADDR; ///< Bulk OUT endpoint 4 size register
_IOR(0xc785) BOUT5ADDR; ///< Bulk OUT endpoint 5 size register
_IOR(0xc788) BINSTADDR; ///< Bulk IN buffers starting address
_IOR(0xc789) BIN1ADDR; ///< Bulk IN endpoint 1 size register
_IOR(0xc78a) BIN2ADDR; ///< Bulk IN endpoint 2 size register
_IOR(0xc78b) BIN3ADDR; ///< Bulk IN endpoint 3 size register
_IOR(0xc78c) BIN4ADDR; ///< Bulk IN endpoint 4 size register
_IOR(0xc78d) BIN5ADDR; ///< Bulk IN endpoint 5 size register
_IOR(0xc7a0) ISOERR; ///< ISO OUT 8 endpoint CRC error register
_IOR(0xc7a2) ZBCOUT; ///< ISO OUT 8 endpoint zero byte data packet register
_IOR(0xc7a8) IVEC; ///< IRQ vector of the active interrupt register
_IOR(0xc7a9) IN_IRQ; ///< IRQ IN interrupt request register
_IOR(0xc7aa) OUT_IRQ; ///< IRQ OUT interrupt request register
_IOR(0xc7ab) USBIRQ; ///< IRQ interrupt request register
_IOR(0xc7ac) IN_IEN; ///< IRQ IN interrupt enable register
_IOR(0xc7ad) OUT_IEN; ///< IRQ OUT interrupt enable register
_IOR(0xc7ae) USBIEN; ///< USB interrupt enable register
_IOR(0xc7af) USBBAV; ///< USB autovector interrupt enable register
_IOR(0xc7b4) EP0CS; ///< IN 0 endpoint control and status register
_IOR(0xc7b5) IN0BC; ///< IN 0 endpoint byte count register
_IOR(0xc7b6) IN1CS; ///< IN 1 endpoint control and status register
_IOR(0xc7b7) IN1BC; ///< IN 1 endpoint byte count register
_IOR(0xc7b8) IN2CS; ///< IN 2 endpoint control and status register
_IOR(0xc7b9) IN2BC; ///< IN 2 endpoint byte count register
_IOR(0xc7ba) IN3CS; ///< IN 3 endpoint control and status register
_IOR(0xc7bb) IN3BC; ///< IN 3 endpoint byte count register
_IOR(0xc7bc) IN4CS; ///< IN 4 endpoint control and status register
_IOR(0xc7bd) IN4BC; ///< IN 4 endpoint byte count register
_IOR(0xc7be) IN5CS; ///< IN 5 endpoint control and status register
_IOR(0xc7bf) IN5BC; ///< IN 5 endpoint byte count register
_IOR(0xc7c5) OUT0BC; ///< OUT 0 endpoint byte count register
_IOR(0xc7c6) OUT1CS; ///< OUT 1 endpoint control and status register
_IOR(0xc7c7) OUT1BC; ///< OUT 1 endpoint byte count register
_IOR(0xc7c8) OUT2CS; ///< OUT 2 endpoint control and status register
_IOR(0xc7c9) OUT2BC; ///< OUT 2 endpoint byte count register
_IOR(0xc7ca) OUT3CS; ///< OUT 3 endpoint control and status register
_IOR(0xc7cb) OUT3BC; ///< OUT 3 endpoint byte count register
_IOR(0xc7cc) OUT4CS; ///< OUT 4 endpoint control and status register
_IOR(0xc7cd) OUT4BC; ///< OUT 4 endpoint byte count register
_IOR(0xc7ce) OUT5CS; ///< OUT 5 endpoint control and status register
_IOR(0xc7cf) OUT5BC; ///< OUT 5 endpoint byte count register
_IOR(0xc7d6) USBCS; ///< USB control and status register
_IOR(0xc7d7) TOGCTL; ///< USB data toggle control register
_IOR(0xc7d8) USBFRML; ///< USB current frame number register, low byte
_IOR(0xc7d9) USBFRMH; ///< USB current frame number register, high byte
_IOR(0xc7db) FNADDR; ///< USB function address register
_IOR(0xc7dd) USBPAIR; ///< USB endpoint pairing register
_IOR(0xc7de) INBULKVAL; ///< IN endpoints 0 to 5 valid bits register
_IOR(0xc7df) OUTBULKVAL; ///< IN endpoints 0 to 5 valid bits register
_IOR(0xc7e0) INISOVAL; ///< ISO IN endpoint valid bit register
_IOR(0xc7e1) OUTISOVAL; ///< ISO OUT endpoint valid bit register
_IOR(0xc7e2) ISOSTADDR; ///< ISO buffers starting address register
_IOR(0xc7e3) ISOSIZE; ///< ISO buffer size register
_IOR(0xc7e8) SETUPBUF[8]; ///< SETUP data buffer
_IOR(0xc7f0) OUT8ADDR; ///< ISO OUT endpoint start address
_IOR(0xc7f8) IN8ADDR; ///< ISO IN endpoint start address

/**
 * \name Bits from register USBIRQ
 * @{
 */
#define _SUDAVIR    (1u<<0) ///< USBIRQ Register, bit SETUP data valid interrupt request
#define _SOFIR      (1u<<1) ///< USBIRQ Register, bit Start of frame interrupt request
#define _SUTOKIR    (1u<<2) ///< USBIRQ Register, bit SETUP token interrupt request
#define _SUSPIR     (1u<<3) ///< USBIRQ Register, bit USB suspend interrupt request
#define _URESIR     (1u<<4) ///< USBIRQ Register, bit USB reset interrupt request
/**@}*/

/**
 * \name Bits from register USBIEN
 * @{
 */
#define _SUDAVIE    (1u<<0) ///< USBIEN Register, bit SETUP data valid to enable interrupt
#define _SOFIE      (1u<<1) ///< USBIEN Register, bit Start of frame to enable interrupt
#define _SUTOKIE    (1u<<2) ///< USBIEN Register, bit SETUP token to enable interrupt
#define _SUSPIE     (1u<<3) ///< USBIEN Register, bit USB suspend to enable interrupt
#define _URESIE     (1u<<4) ///< USBIEN Register, bit USB reset to enable interrupt
/**@}*/

/**
 * \name Bits from register EP0CS
 * @{
 */
#define _EP0STALL   (1u<<0) ///< EP0CS Register, bit Endpoint 0 stall
#define _HSNAK      (1u<<1) ///< EP0CS Register, bit Send NAK Handshake in status stage
#define _INBSY      (1u<<2) ///< EP0CS Register, bit IN0 endpoint busy
#define _OUTBSY     (1u<<3) ///< EP0CS Register, bit OUT0 endpoint busy
#define _DSTALL     (1u<<4) ///< EP0CS Register, bit Send STALL handshake in data stage
#define _CHGSET     (1u<<6) ///< EP0CS Register, bit SETUP buffer changed
/**@}*/

/**
 * \name Bits from registers IN1CS-IN5CS
 * @{
 */
#define _INXSTL     (1u<<0) ///< INxCS register, bit INx endpoint stall
#define _INXBSY     (1u<<1) ///< INxCS register, bit INx endpoint busy
/**@}*/

/**
 * \name Bits from registers OUT1CS-OUT5CS
 * @{
 */
#define _OUTXSTL    (1u<<0) ///< OUTxCS register, bit OUTx endpoint stall
#define _OUTXBSY    (1u<<1) ///< OUTxCS register, bit OUTx endpoint busy
/**@}*/

/**
 * \name Bits from register USBCS
 * @{
 */
#define _SIGRSUME   (1u<<0) ///< USBCS register, bit Signal remote device resume
#define _FORCEJ     (1u<<1) ///< USBCS register, bit Force J state
#define _DISCON     (1u<<3) ///< USBCS register, bit Disconnect D+ line internal pull-up resistor
#define _SOFGEN     (1u<<5) ///< USBCS register, bit Enable SOF timer interrupt
#define _WAKESRC    (1u<<7) ///< USBCS register, bit Wakeup source from wakeup pin
/**@}*/

/**
 * \name Bits from register TOGCTL
 * @{
 */
#define _TOGIO      (1u<<4) ///< TOGCTL register, bit Select IN/OUT endpoint
#define _TOGR       (1u<<5) ///< TOGCTL register, bit Reset data toggle to DATA0
#define _TOGS       (1u<<6) ///< TOGCTL register, bit Reset data toggle to DATA1
#define _TOGQ       (1u<<7) ///< TOGCTL register, bit Data toggle DATA0/DATA1 select
/**@}*/

/**
 * \name Bits from register USBPAIR
 * @{
 */
#define _PR2IN      (1u<<0) ///< USBPAIR register, bit Pair bulk IN 2 and 3 endpoints
#define _PR4IN      (1u<<1) ///< USBPAIR register, bit Pair bulk IN 4 and 5 endpoints
#define _PR6IN      (1u<<2) ///< USBPAIR register, bit Pair bulk IN 6 and 7 endpoints
#define _PR2OUT     (1u<<3) ///< USBPAIR register, bit Pair bulk OUT 2 and 3 endpoints
#define _PR4OUT     (1u<<4) ///< USBPAIR register, bit Pair bulk OUT 4 and 5 endpoints
#define _ISOSEND0   (1u<<7) ///< USBPAIR register, bit ISO endpoints send zero length data packet
/**@}*/

#endif
