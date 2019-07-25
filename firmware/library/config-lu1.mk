# This file contains only configuration for nRF24LU1(+) builds, no rules.
# Use it if you need tight control over the build system.

# -- Configuration start --

CODE_SIZE ?= 0x4000 # all program memory with 16 kB option; low half with 32 kB option
XRAM_SIZE ?= 0x0200 # all data memory
CFLAGS    ?=
LIBRARIES ?= nrf24lu1

# -- Configuration end --

MODEL      = small  # only small memory model is supported
SDCCFLAGS  = \
	--iram-size 0x100 \
	--code-size $(CODE_SIZE) \
	--xram-loc  0x8000 \
	--xram-size $(XRAM_SIZE) \
	--std-sdcc11 \
	--model-$(MODEL) \
	$(CFLAGS) \
	-I$(LIBNRF24L)/include \
	-L$(LIBNRF24L)/lib/$(MODEL)
