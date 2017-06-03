build-all:

setup:
	@sh -c '. ./.kaleidoscope-builder.conf && setup'

MAKEFILE_PREFIX=keyboardio/avr/libraries/Kaleidoscope-Plugin/build
UNAME_S := $(shell uname -s)

BOARD_HARDWARE_PATH ?= $(HOME)/Arduino/hardware
ifeq ($(UNAME_S),Darwin)
BOARD_HARDWARE_PATH ?= $(HOME)/Library/Arduino/hardware
endif

include $(BOARD_HARDWARE_PATH)/$(MAKEFILE_PREFIX)/*.mk
