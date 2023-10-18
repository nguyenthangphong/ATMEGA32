#ifndef LCD_H_
#define LCD_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../UTLIS/micro_config.h"
#include "../../UTLIS/common_macros.h"
#include "../../UTLIS/std_types.h"

#define	LCD_CTRL_PORT_DIR DDRB
#define	LCD_CTRL_PORT PORTB
#define RS PD0
#define RW PD1
#define EN PD2

#define LCD_DATA_PORT_DIR DDRA
#define LCD_DATA_PORT PORTA

#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_EIGHT_BIT_MODE 0x38
#define TWO_LINE_LCD_FOUR_BIT_MODE 0x28
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

void LCD_init(void);
void LCD_sendCommand(unsigned char cmd);
void LCD_sendData(unsigned char data);
void LCD_displayString(const unsigned char * str);
void LCD_goToRowColumn(unsigned char row, unsigned char column);
void LCD_clear(void);
void LCD_displayStringAtRowAndColumn(unsigned char row, unsigned char column, const unsigned char * str);
void LCD_convertIntegerToString(unsigned char value);

#endif /* LCD_H_ */