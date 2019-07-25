# -- Configuration start --

BOOT_VID ?= 0x1915 # Nordic Semi
BOOT_PID ?= 0x0101 # factory bootloader

CODE_LOC ?= 0x0000 # any Flash or RAM page

# -- Configuration end --

TARGET    = boot
SOURCES   = main startup
SDCCFLAGS = \
	--iram-size 0x100 \
	--code-loc  $(CODE_LOC) \
	--code-size 0x200 \
	--no-xinit-opt \
	--std-sdcc11 \
	--nostdlib \
	--model-small \
	--acall-ajmp \
	-I$(LIBNRF24L)/include \
	-D BOOT_VID=$(BOOT_VID) \
	-D BOOT_PID=$(BOOT_PID)

LIBNRF24L = ../../library
include $(LIBNRF24L)/rules.mk
