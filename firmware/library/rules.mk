# This file includes the config.mk configuration for nRF24L builds,
# and contains rules that should suffice for most firmware.
# It implements out-of-tree builds and dependency tracking for C,
# so that rebuilds work correctly after modifying headers.

# Configuration start

# See the configuration in config.mk as well.
ifdef CHIP
include $(LIBNRF24L)/config-$(CHIP).mk
endif

# Name of our build product. Build will create $(FIRMWARE).ihex.
TARGET  	?= firmware

# List of C or assembly sources that comprise our firmware.
# The extension is determined automatically.
SOURCES 	?= main

# List of standard libraries to be included in the firmware.
LIBRARIES ?=

# Configuration end

SDCC       = sdcc -mmcs51 $(SDCCFLAGS)
SDAS       = sdas8051 -plo

ifeq ($(V),1)
SDCCFLAGS += -V
endif

OBJECTS 	 = \
	$(patsubst %,build/%.rel,$(SOURCES)) \
	$(patsubst %,$(LIBNRF24L)/lib/$(strip $(MODEL))/%.lib,$(LIBRARIES))

all: $(TARGET).ihex

$(TARGET).ihex: $(OBJECTS) $(LIBNRF24L)/.stamp
	$(SDCC) -o build/$@ $(OBJECTS)
	cp build/$@ $@

$(LIBNRF24L)/.stamp: $(wildcard $(LIBNRF24L)/*.c $(LIBNRF24L)/*.asm $(LIBNRF24L)/include/*.h)
	$(MAKE) -C $(LIBNRF24L)

-include build/*.d
build/%.rel: %.c
	@mkdir -p $(dir $@)
	$(SDCC) -Wp,-MQ,$@,-MMD,build/$*.d -c -o $@ $<

build/%.rel: %.asm
	@mkdir -p $(dir $@)
	$(SDAS) $@ $<

clean:
	rm -rf build/ $(TARGET).ihex

.PHONY: all clean load

.SUFFIXES:
MAKEFLAGS += -r
