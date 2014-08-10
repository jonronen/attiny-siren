MCU ?= attiny13

ARDUINO_FILES ?= /usr/share/arduino/hardware
ARDUINO_SRCS = $(ARDUINO_FILES)/arduino/avr/cores/arduino

PORT ?= /dev/ttyACM0


GPP_FLAGS := -c -O3 -Wall -mmcu=$(MCU) -I$(ARDUINO_FILES)/tools/avr/lib/avr/include


generator.hex: generator.elf
	$(ARDUINO_FILES)/tools/avr/bin/avr-objcopy -O ihex -R .eeprom generator.elf generator.hex

generator.elf: generator.o
	$(ARDUINO_FILES)/tools/avr/bin/avr-gcc -O3 -Wl,--gc-sections -mmcu=$(MCU) -o generator.elf generator.o -lm

generator.o: generator.c
	avr-gcc $(GPP_FLAGS) generator.c

upload: generator.hex
	$(ARDUINO_FILES)/tools/avrdude -C$(ARDUINO_FILES)/tools/avrdude.conf -v -p$(MCU) -cstk500v1 -P$(PORT) -b19200 -Uflash:w:generator.hex:i

fuses:
	$(ARDUINO_FILES)/tools/avrdude -C$(ARDUINO_FILES)/tools/avrdude.conf -v -p$(MCU) -cavrisp -P$(PORT) -b19200 -U lfuse:w:0x6a:m -U hfuse:w:0xff:m

clean:
	rm -f *.o *.hex *.elf

