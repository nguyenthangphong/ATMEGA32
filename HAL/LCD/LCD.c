#include "LCD.h"

void LCD_init(void) {
	LCD_DATA_PORT_DIR = 0xFF;
	LCD_CTRL_PORT_DIR = (1 << EN) | (1 << RS) | (1 << RW);
	_delay_ms(50);
	LCD_sendCommand(TWO_LINE_LCD_EIGHT_BIT_MODE);
	_delay_ms(1);
	LCD_sendCommand(CURSOR_OFF);
	_delay_ms(1);
	LCD_sendCommand(CLEAR_COMMAND);
	_delay_ms(2);
}

void LCD_sendCommand(unsigned char cmd) {
	CLEAR_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT, EN);
	_delay_ms(1);
	LCD_DATA_PORT = cmd;
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT, EN);
}

void LCD_sendData(unsigned char data) {
	SET_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT, EN);
	_delay_ms(1);
	LCD_DATA_PORT = data;
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT, EN);
}

void LCD_displayString(const unsigned char * str) {
	unsigned char i=0;

	while (str[i] != '\0') {
		LCD_sendData(str[i]);
		i++;
	} 
}

void LCD_goToRowColumn(unsigned char row, unsigned char column) {
	unsigned char address;
	switch (row) {
    case 0:
        address = column;
        break;
    case 1:
        address = column + 0x40;
        break;
    case 2:
        address = column + 0x10;
        break;
    case 3:
        address = column + 0x50;
        break;
	}
	LCD_sendCommand(address | SET_CURSOR_LOCATION);
}

void LCD_clear(void) {
    LCD_sendCommand(CLEAR_COMMAND);
}

void LCD_displayStringAtRowAndColumn(unsigned char row, unsigned char column, const unsigned char * str) {
    LCD_goToRowColumn(row, column);
    LCD_displayString(str);
}

void LCD_convertIntegerToString(unsigned char value) {
    unsigned char numbers[100];
    itoa(value, numbers, 10);
    LCD_displayString(numbers);
}