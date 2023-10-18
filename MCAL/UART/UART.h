#ifndef _UART_H_
#define _UART_H_

#include "../../UTLIS/micro_config.h"
#include "../../UTLIS/common_macros.h"
#include "../../UTLIS/std_types.h"

typedef enum { DISABLED, RESERVED, EVEN, ODD } UART_parity;
typedef enum { ONE = 1, TWO } UART_stopBits;
typedef enum { FIVE = 5, SIX, SEVEN, EIGHT } UART_dataSize;

typedef struct {
	UART_parity parity;
	UART_stopBits stopBit;
	UART_dataSize dataSize;
	unsigned long baudRate;
} UART_configType;

void UART_init();
unsigned char UART_getChar(void);
void UART_putChar(char data);
void UART_writeString(char * string);
void UART_readString(char * string);

#endif /* _UART_H_ */