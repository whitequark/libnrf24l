# This file contains only configuration for nRF24LE1 builds, no rules.
# Use it if you need tight control over the build system.

# -- Configuration start --

MODEL     ?= small  # small and medium are supported
CODE_SIZE ?= 0x4000 # all program memory
XRAM_SIZE ?= 0x0200 # retentive half of data memory only
CFLAGS    ?=
LIBRARIES ?= nrf24le1

# -- Configuration end --

SDCCFLAGS  = \
	--iram-size 0x100 \
	--code-size $(CODE_SIZE) \
	--xram-loc  0x0000 \
	--xram-size $(XRAM_SIZE) \
	--std-sdcc11 \
	--model-$(MODEL) \
	$(CFLAGS) \
	-I$(LIBNRF24L)/include \
	-L$(LIBNRF24L)/lib/$(MODEL)
