PROJECTNAME = ATMEGA32
MCU = atmega32
F_CPU = 8000000UL
COMPILE = avr-gcc -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)
OBJCOPY = avr-objcopy
SIZE = avr-size
BUILD_DIR = build

ROOM_SOURCES = \
    DHT11.c

ROOM_OBJECTS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(ROOM_SOURCES))

compile: create_build_dir $(ROOM_OBJECTS)
	$(COMPILE) -o $(PROJECTNAME).elf $(ROOM_OBJECTS)
	$(OBJCOPY) -O ihex $(PROJECTNAME).elf $(PROJECTNAME).hex
	$(SIZE) --format=avr --mcu=$(MCU) $(PROJECTNAME).elf
	mv $(PROJECTNAME).hex $(BUILD_DIR)/Room/$(PROJECTNAME).hex
	mv $(PROJECTNAME).elf $(BUILD_DIR)/Room/$(PROJECTNAME).elf

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPILE) -c $< -o $@

create_build_dir:
	mkdir -p $(BUILD_DIR)/Room

clean:
	rm -rf $(BUILD_DIR)