SDCC      = sdcc -mmcs51 --std-sdcc99 -Iinclude $(CFLAGS)
SDAS      = sdas8051 -plo
SDAR     ?= sdar rc

OBJECTS_common   = bswap.rel radio.rel
OBJECTS_nrf24le1 = $(OBJECTS_common) radio_le1.rel
OBJECTS_nrf24lu1 = $(OBJECTS_common) radio_lu1.rel usb_lu1.rel

all::
	@touch .stamp

define make-library
lib/$1/$2.lib: $(addprefix build/$1/,$(OBJECTS_$2))
	@mkdir -p $$(dir $$@)
	$(SDAR) $$@ $$^
endef

define make-model
all:: $(addprefix lib/$1/,$(addsuffix .lib,$2))

$(foreach library,$2,$(eval $(call make-library,$1,$(library))))

build/$1/%.rel: %.c
	@mkdir -p $$(dir $$@)
	$(SDCC) --model-$1 -c -o $$@ $$<

build/$1/%.rel: %.asm
	@mkdir -p $$(dir $$@)
	$(SDAS) $$@ $$<
endef

$(eval $(call make-model,small,nrf24le1 nrf24lu1))
$(eval $(call make-model,medium,nrf24le1))

clean:
	rm -rf build/ lib/ .stamp *.lib

.PHONY: all clean

.SUFFIXES:
MAKEFLAGS += -r
