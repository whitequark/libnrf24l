#ifndef NRF24LE1_REGS_H
#define NRF24LE1_REGS_H

#include <stdint.h>

#ifndef DOXYGEN
#define _SFR(addr)   static __sfr __at (addr)
#define _SFR16(addr) static __sfr16 __at (addr)
#define _SBIT(addr)  static __sbit __at (addr)
#endif

// Register _XPAGE must be defined at a location that sets the upper
// address byte of movx using \@rN for non-small memory models to work.
// This should *not* be declared as `static`.
/// Alias of `MPAGE` used internally by sdcc.
__sfr __at(0xc9) _XPAGE;

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
_SFR(0x8f) P3CON; ///< Port 3 Configuration Register
_SFR(0x90) P1; ///< Port 1 Value
    _SBIT(0x90 + 0) P1_0; ///< Port 1 Value, bit 0
    _SBIT(0x90 + 1) P1_1; ///< Port 1 Value, bit 1
    _SBIT(0x90 + 2) P1_2; ///< Port 1 Value, bit 2
    _SBIT(0x90 + 3) P1_3; ///< Port 1 Value, bit 3
    _SBIT(0x90 + 4) P1_4; ///< Port 1 Value, bit 4
    _SBIT(0x90 + 5) P1_5; ///< Port 1 Value, bit 5
    _SBIT(0x90 + 6) P1_6; ///< Port 1 Value, bit 6
    _SBIT(0x90 + 7) P1_7; ///< Port 1 Value, bit 7
_SFR(0x92) DPS; ///< Data Pointer Select Register
_SFR(0x93) P0DIR; ///< Port 0 Pin Direction Control Register
_SFR(0x94) P1DIR; ///< Port 1 Pin Direction Control Register
_SFR(0x95) P2DIR; ///< Port 2 Pin Direction Control Register
_SFR(0x96) P3DIR; ///< Port 3 Pin Direction Control Register
_SFR(0x97) P2CON; ///< Port 2 Configuration Register
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
_SFR(0x9e) P0CON; ///< Port 0 Configuration Register
_SFR(0x9f) P1CON; ///< Port 1 Configuration Register
_SFR(0xa0) P2; ///< Port 2 Value
    _SBIT(0xa0 + 0) P2_0; ///< Port 2 Value, bit 0
    _SBIT(0xa0 + 1) P2_1; ///< Port 2 Value, bit 1
    _SBIT(0xa0 + 2) P2_2; ///< Port 2 Value, bit 2
    _SBIT(0xa0 + 3) P2_3; ///< Port 2 Value, bit 3
    _SBIT(0xa0 + 4) P2_4; ///< Port 2 Value, bit 4
    _SBIT(0xa0 + 5) P2_5; ///< Port 2 Value, bit 5
    _SBIT(0xa0 + 6) P2_6; ///< Port 2 Value, bit 6
    _SBIT(0xa0 + 7) P2_7; ///< Port 2 Value, bit 7
_SFR(0xa1) PWMDC0; ///< PWM Duty Cycle for Channel 0
_SFR(0xa2) PWMDC1; ///< PWM Duty Cycle for Channel 1
_SFR(0xa3) CLKCTRL; ///< Clock Control Register
_SFR(0xa4) PWRDWN; ///< Power-down Control Register
_SFR(0xa5) WUCON; ///< Wakeup configuration Register
_SFR(0xa6) INTEXP; ///< Interrupt Expander Register
_SFR(0xa7) MEMCON; ///< Memory Configuration Register
_SFR(0xa8) IEN0; ///< Interrupt Enable Register 0
    _SBIT(0xa8 + 0) EIFP; ///< Interrupt Enable Register 0, bit Enable Interrupt From Pin
    _SBIT(0xa8 + 1) ETF0; ///< Interrupt Enable Register 0, bit Enable Timer0 Overflow Interrupt
    _SBIT(0xa8 + 2) EPOF; ///< Interrupt Enable Register 0, bit Enable Power Failure Interrupt
    _SBIT(0xa8 + 3) ETF1; ///< Interrupt Enable Register 0, bit Enable Timer1 Overflow Interrupt
    _SBIT(0xa8 + 4) ES0; ///< Interrupt Enable Register 0, Enable bit Serial Port 0 Interrupt
    _SBIT(0xa8 + 5) ETF2; ///< Interrupt Enable Register 0, bit Enable Timer2 Overflow Interrupt
    // Unused bit 6
    _SBIT(0xa8 + 7) EA; ///< Interrupt Enable Register 0, bit Enable Interrupts
_SFR(0xa9) IP0; ///< Interrupt Priority Register 0
_SFR(0xaa) S0RELL; ///< Serial Port 0 Reload Register, low byte
_SFR(0xab) RTC2CPT01; ///< RTC2 Capture Value Register 01
_SFR(0xac) RTC2CPT10; ///< RTC2 Capture Value Register 10
_SFR(0xad) CLKLFCTRL; ///< 32 kHz (CLKLF) Control Register
_SFR(0xae) OPMCON; ///< Operational Mode Control Register
_SFR(0xaf) WDSW; ///< Watchdog Start Value Register
_SFR(0xb0) P3; ///< Port 3 Value
    _SBIT(0xb0 + 0) P3_0; ///< Port 3 Value, bit 0
    _SBIT(0xb0 + 1) P3_1; ///< Port 3 Value, bit 1
    _SBIT(0xb0 + 2) P3_2; ///< Port 3 Value, bit 2
    _SBIT(0xb0 + 3) P3_3; ///< Port 3 Value, bit 3
    _SBIT(0xb0 + 4) P3_4; ///< Port 3 Value, bit 4
    _SBIT(0xb0 + 5) P3_5; ///< Port 3 Value, bit 5
    _SBIT(0xb0 + 6) P3_6; ///< Port 3 Value, bit 6
    _SBIT(0xb0 + 7) P3_7; ///< Port 3 Value, bit 7
_SFR(0xb1) RSTREAS; ///< Reset Reason Register
_SFR(0xb2) PWMCON; ///< PWM Configuration Register
_SFR(0xb3) RTC2CON; ///< RTC2 Configuration Register
_SFR(0xb4) RTC2CMP0; ///< RTC2 Compare Value Register 0
_SFR(0xb5) RTC2CMP1; ///< RTC2 Compare Value Register 1
_SFR(0xb6) RTC2CPT00; ///< RTC2 Capture Value Register 00
_SFR(0xb8) IEN1; ///< Interrupt Enable Register 1
    _SBIT(0xb8 + 0) ERFRDY; ///< Interrupt Enable Register 1, bit Enable RF SPI Ready Interrupt
    _SBIT(0xb8 + 1) ERFIRQ; ///< Interrupt Enable Register 1, bit Enable RF IRQ Interrupt
    _SBIT(0xb8 + 2) EWIRE2; ///< Interrupt Enable Register 1, bit Enable 2-Wire Completed Interrupt
    _SBIT(0xb8 + 2) ESPI; ///< Interrupt Enable Register 1, bit Enable SPI Completed Interrupt
    _SBIT(0xb8 + 3) EWUOP; ///< Interrupt Enable Register 1, bit Enable Wakeup on Pin Interrupt
    _SBIT(0xb8 + 4) EMISC; ///< Interrupt Enable Register 1, bit Enable Miscellaneous Interrupt
    _SBIT(0xb8 + 5) ETICK; ///< Interrupt Enable Register 1, bit Enable Internal Wakeup Interrupt
    // Unused bit 6
    _SBIT(0xb8 + 7) EEXF2; ///< Interrupt Enable Register 1, bit Enable Timer2 External Reload Int.
_SFR(0xb9) IP1; ///< Interrupt Priority Register 1
_SFR(0xba) S0RELH; ///< Serial Port 0 Reload Register, high byte
_SFR16(0xbaaa) S0REL; ///< Serial Port 0 Reload Register
_SFR(0xbc) SPISCON0; ///< SPI Slave Configuration Register 0
_SFR(0xbe) SPISSTAT; ///< SPI Slave Status Register
_SFR(0xbf) SPISDAT; ///< SPI Slave Data Register
_SFR(0xc0) IRCON; ///< Interrupt Request Control Register
    _SBIT(0xc0 + 0) IRFRDY; ///< Interrupt Request Ctrl. Reg., bit RF SPI Ready Interrupt Flag
    _SBIT(0xc0 + 1) IRFIRQ; ///< Interrupt Request Ctrl. Reg., bit RF IRQ Interrupt Flag
    _SBIT(0xc0 + 2) IWIRE2; ///< Interrupt Request Ctrl. Reg., bit 2-Wire Completed Interrupt Flag
    _SBIT(0xc0 + 2) ISPI; ///< Interrupt Request Ctrl. Reg., bit SPI Completed Interrupt Flag
    _SBIT(0xc0 + 3) IWUOP; ///< Interrupt Request Ctrl. Reg., bit Wakeup on Pin Interrupt Flag
    _SBIT(0xc0 + 4) IMISC; ///< Interrupt Request Ctrl. Reg., bit Miscellaneous Interrupt Flag
    _SBIT(0xc0 + 5) ITICK; ///< Interrupt Request Ctrl. Reg., bit Internal Wakeup Interrupt Flag
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
_SFR(0xc9) MPAGE; ///< Start Address of the PDATA Page
_SFR(0xca) CRCL; ///< Compare/Reload/Capture Register, low byte
_SFR(0xcb) CRCH; ///< Compare/Reload/Capture Register, high byte
_SFR16(0xcbca) CRC; ///< Compare/Reload/Capture Register
_SFR(0xcc) TL2; ///< Timer 2 Reload Register, low byte
_SFR(0xcd) TH2; ///< Timer 2 Reload Register, high byte
_SFR16(0xcdcc) T2; ///< Timer 2 Reload Register
_SFR(0xce) WUOPC1; ///< Wakeup On Pin Configuration Register 1
_SFR(0xcf) WUOPC0; ///< Wakeup On Pin Configuration Register 0
_SFR(0xd0) PSW; ///< Program Status Word
    _SBIT(0xd0 + 0) P; ///< Program Status Word, bit P
    _SBIT(0xd0 + 1) F1; ///< Program Status Word, bit F1
    _SBIT(0xd0 + 2) OV; ///< Program Status Word, bit OV
    _SBIT(0xd0 + 3) RS0; ///< Program Status Word, bit RS0
    _SBIT(0xd0 + 4) RS1; ///< Program Status Word, bit RS1
    _SBIT(0xd0 + 5) F0; ///< Program Status Word, bit F0
    _SBIT(0xd0 + 6) AC; ///< Program Status Word, bit AC
    _SBIT(0xd0 + 7) CY; ///< Program Status Word, bit CY
_SFR(0xd1) ADCCON3; ///< ADC Configuration Register 3
_SFR(0xd2) ADCCON2; ///< ADC Configuration Register 2
_SFR(0xd3) ADCCON1; ///< ADC Configuration Register 1
_SFR(0xd4) ADCDATH; ///< ADC Data Register, high byte
_SFR(0xd5) ADCDATL; ///< ADC Data Register, low byte
_SFR16(0xd5d4) ADCDAT; ///< ADC Data Register
_SFR(0xd6) RNGCTL; ///< Random Number Generator Control Register
_SFR(0xd7) RNGDAT; ///< Random Number Generator Data Register
_SFR(0xd8) ADCON; ///< Serial Port 0 Baud Rate Select Register
    // Unused bits 0:6
    _SBIT(0xd8 + 7) BD; ///< Serial Port 0 Baud Rate Select Register, bit Use Internal Baud Rate
_SFR(0xd9) W2SADR; ///< 2-Wire Slave Address Register
_SFR(0xda) W2DAT; ///< 2-Wire Data Register
_SFR(0xdb) COMPCON; ///< Comparator Control Register
_SFR(0xdc) POFCON; ///< Power-fail Comparator Configuration Register
_SFR(0xdd) CCPDATIA; ///< Encryption/Decryption accelerator Data In Register A
_SFR(0xde) CCPDATIB; ///< Encryption/Decryption accelerator Data In Register B
_SFR(0xdf) CCPDATO; ///< Encryption/Decryption accelerator Data Out Register
_SFR(0xe0) ACC; ///< Accumulator
    _SBIT(0xe0 + 0) ACC0; ///< Accumulator, bit 0
    _SBIT(0xe0 + 1) ACC1; ///< Accumulator, bit 1
    _SBIT(0xe0 + 2) ACC2; ///< Accumulator, bit 2
    _SBIT(0xe0 + 3) ACC3; ///< Accumulator, bit 3
    _SBIT(0xe0 + 4) ACC4; ///< Accumulator, bit 4
    _SBIT(0xe0 + 5) ACC5; ///< Accumulator, bit 5
    _SBIT(0xe0 + 6) ACC6; ///< Accumulator, bit 6
    _SBIT(0xe0 + 7) ACC7; ///< Accumulator, bit 7
_SFR(0xe1) W2CON1; ///< 2-Wire Configuration Register 1/Status Register
_SFR(0xe2) W2CON0; ///< 2-Wire Configuration Register 0
_SFR(0xe4) SPIRCON0; ///< RF Transceiver SPI Master Configuration Register 0
_SFR(0xe5) SPIRCON1; ///< RF Transceiver SPI Master Configuration Register 1
_SFR(0xe6) SPIRSTAT; ///< RF Transceiver SPI Master Status Register
_SFR(0xe7) SPIRDAT; ///< RF Transceiver SPI Master Data Register
_SFR(0xe8) RFCON; ///< RF Transceiver Control Register
    _SBIT(0xe8 + 0) RFCE; ///< RF Transceiver Control Register, bit Enable RF Transceiver
    _SBIT(0xe8 + 1) RFCSN; ///< RF Transceiver Control Register, bit Enable RF Command
    _SBIT(0xe8 + 2) RFCKEN; ///< RF Transceiver Control Register, bit Enable RF Clock
    // Unused bits 3:7
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
_SFR(0xf8) FSR; ///< Flash Status Register
    // Unused bits 0:1
    _SBIT(0xf8 + 2) RDISMB; ///< Flash Status Register, bit Flash MB Readback Protection Enabled
    _SBIT(0xf8 + 3) INFEN; ///< Flash Status Register, bit Flash IP Enable
    _SBIT(0xf8 + 4) RDYN; ///< Flash Status Register, bit Flash Ready Flag
    _SBIT(0xf8 + 5) WEN; ///< Flash Status Register, bit Flash Write Enable Latch
    _SBIT(0xf8 + 6) STP; ///< Flash Status Register, bit Start From Protected Area
    _SBIT(0xf8 + 7) ENDEBUG; ///< Flash Status Register, bit Hardware Debug Features Enabled
_SFR(0xf9) FPCR; ///< Flash Protect Configuration Register
_SFR(0xfa) FCR; ///< Flash Command Register
_SFR(0xfc) SPIMCON0; ///< SPI Master Configuration Register 0
_SFR(0xfd) SPIMCON1; ///< SPI Master Configuration Register 1
_SFR(0xfe) SPIMSTAT; ///< SPI Master Status Register
_SFR(0xff) SPIMDAT; ///< SPI Master Data Register

#endif
