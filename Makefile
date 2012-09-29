include Makefile.common
LDFLAGS=$(COMMONFLAGS) -fno-exceptions -L$(LIBDIR) -nostartfiles -Tstm32_flash.ld

LDLIBS+=-lm
LDLIBS+=-lstm32

all: src
	$(LD) -o $(PROGRAM).elf $(LDFLAGS) \
		-W1,--whole-archive src/app.a \
		-W1,--no-whole-archive $(LDLIBS)
	$(OBJCOPY) -Oihex $(PROGRAM).elf $(PROGRAM).hex
	$(OBJCOPY) -Obinary $(PROGRAM).elf $(PROGRAM).bin

.PHONY:libs src clean


src:
	$(MAKE) -C src $@

clean:
	$(MAKE) -C src $@
	rm -f $(PROGRAM).elf $(PROGRAM).hex $(PROGRAM).bin
