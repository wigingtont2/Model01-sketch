build-all:

MAKEFILE_PREFIX=keyboardio/avr/libraries/Kaleidoscope-Plugin/build
UNAME_S := $(shell uname -s)

include hardware/$(MAKEFILE_PREFIX)/*.mk
