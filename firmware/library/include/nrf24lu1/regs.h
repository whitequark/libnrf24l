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


_IOR(0xc440) USBBUF[768]; ///< Combined USB Buffers
_IOR(0xc760) OUT8DATA; ///< ISO OUT endpoint 8 data FIFO register
_IOR(0xc768) IN8DATA; ///<
_IOR(0xc770) OUT8BCH; ///<
_IOR(0xc771) OUT8BCL; ///<
_IOR(0xc781) BOUT1ADDR; ///<
_IOR(0xc782) BOUT2ADDR; ///<
_IOR(0xc783) BOUT3ADDR; ///<
_IOR(0xc784) BOUT4ADDR; ///<
_IOR(0xc785) BOUT5ADDR; ///<
_IOR(0xc788) BINSTADDR; ///<
_IOR(0xc789) BIN1ADDR; ///<
_IOR(0xc78a) BIN2ADDR; ///<
_IOR(0xc78b) BIN3ADDR; ///<
_IOR(0xc78c) BIN4ADDR; ///<
_IOR(0xc78d) BIN5ADDR; ///<
_IOR(0xc7a0) ISOERR; ///<
_IOR(0xc7a2) ZBCOUT; ///<
_IOR(0xc7a8) USB_IVEC; ///<
_IOR(0xc7a9) IN_IRQ; ///<
_IOR(0xc7aa) OUT_IRQ; ///<
_IOR(0xc7ab) USBIRQ; ///<
_IOR(0xc7ac) IN_IEN; ///<
_IOR(0xc7ad) OUT_IEN; ///<
_IOR(0xc7ae) USBIEN; ///<
_IOR(0xc7af) USBBAV; ///<
_IOR(0xc7b4) EP0CS; ///<
_IOR(0xc7b5) IN0BC; ///<
_IOR(0xc7b6) IN1CS; ///<
_IOR(0xc7b7) IN1BC; ///<
_IOR(0xc7b8) IN2CS; ///<
_IOR(0xc7b9) IN2BC; ///<
_IOR(0xc7ba) IN3CS; ///<
_IOR(0xc7bb) IN3BC; ///<
_IOR(0xc7bc) IN4CS; ///<
_IOR(0xc7bd) IN4BC; ///<
_IOR(0xc7be) IN5CS; ///<
_IOR(0xc7bf) IN5BC; ///<
_IOR(0xc7c5) OUT0BC; ///<
_IOR(0xc7c6) OUT1CS; ///<
_IOR(0xc7c7) OUT1BC; ///<
_IOR(0xc7c8) OUT2CS; ///<
_IOR(0xc7c9) OUT2BC; ///<
_IOR(0xc7ca) OUT3CS; ///<
_IOR(0xc7cb) OUT3BC; ///<
_IOR(0xc7cc) OUT4CS; ///<
_IOR(0xc7cd) OUT4BC; ///<
_IOR(0xc7ce) OUT5CS; ///<
_IOR(0xc7cf) OUT5BC; ///<
_IOR(0xc7d6) USBCS; ///<
_IOR(0xc7d7) TOGCTLB; ///<
_IOR(0xc7d8) USBFRML; ///<
_IOR(0xc7d9) USBFRMH; ///<
_IOR(0xc7db) FNADDR; ///<
_IOR(0xc7dd) USBPAIR; ///<
_IOR(0xc7de) INBULKVAL; ///<
_IOR(0xc7df) OUTBULKVAL; ///<
_IOR(0xc7e0) INISOVAL; ///<
_IOR(0xc7e1) OUTISOVAL; ///<
_IOR(0xc7e2) ISOSTADDR; ///<
_IOR(0xc7e3) ISOSIZE; ///<
_IOR(0xc7e8) SETUPBUF[8];
_IOR(0xc7f0) OUT8ADDR; ///<
_IOR(0xc7f8) IN8ADDR; ///<


#endif
