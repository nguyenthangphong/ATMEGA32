PROJECTNAME = ATMEGA32
MCU = atmega32
F_CPU = 8000000UL
COMPILE = avr-gcc -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)
OBJCOPY = avr-objcopy
SIZE = avr-size
BUILD_DIR = build

# Define the source files
SOURCES = \
	APP/main/main.c \
	HAL/LED/LED.c \
	MCAL/ADC/ADC.c \
    MCAL/DIO/DIO.c \
	MCAL/EEPROM/EEPROM.c \
	MCAL/I2C/I2C.c \
	MCAL/SPI/SPI.c \
	MCAL/TIMER/TIMER.c \
	MCAL/UART/UART.c

# Generate object file names
OBJECTS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SOURCES))

compile: create_build_dir $(OBJECTS)
	$(COMPILE) -o $(PROJECTNAME).elf $(OBJECTS)
	$(OBJCOPY) -O ihex $(PROJECTNAME).elf $(PROJECTNAME).hex
	$(SIZE) --format=avr --mcu=$(MCU) $(PROJECTNAME).elf
	mv $(PROJECTNAME).hex $(BUILD_DIR)/$(PROJECTNAME)/$(PROJECTNAME).hex
	mv $(PROJECTNAME).elf $(BUILD_DIR)/$(PROJECTNAME)/$(PROJECTNAME).elf

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPILE) -c $< -o $@

create_build_dir:
	mkdir -p $(BUILD_DIR)/$(PROJECTNAME)

clean:
	rm -rf $(BUILD_DIR)