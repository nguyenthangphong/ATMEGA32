#ifndef _UART_H_
#define _UART_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

typedef enum { DISABLED, RESERVED, EVEN, ODD } UART_parity;
typedef enum { ONE, TWO } UART_stopBits;
typedef enum { FIVE, SIX, SEVEN, EIGHT } UART_dataSize;

typedef struct {
	UART_parity parity;
	UART_stopBits stopBit;
	UART_dataSize dataSize;
	unsigned long baudRate;
} UART_configType;

void UART_init(const UART_configType * Config_Ptr);
void UART_sendByte(const unsigned char Byte);
unsigned char UART_receiveByte(void);

#endif /* _UART_H_ */