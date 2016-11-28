MAKEFLAGS += -s

all:

%:
	cd lib/Akela && ${MAKE} -C ../../src -f ${PWD}/lib/Akela/Mk/example.mk \
			LIBRARY=algernon SKETCH=algernon OUTPUT_PATH=../firmware/algernon $@
