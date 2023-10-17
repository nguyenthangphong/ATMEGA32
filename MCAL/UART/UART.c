#include "UART.h"

void UART_init(const UART_configType * UART_Config_Ptr){
	unsigned short BaudPrescaler = ((F_CPU / (UART_Config_Ptr->baudRate)) - 1);

	/* use double speed mode */
	SET_BIT(UCSRA, U2X);

	/* enable the rx and tx */
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);

	/* URSEL must be 1 while writing to UCSRC */
	SET_BIT(UCSRC, URSEL);

	/* selecting Async mode */
	CLEAR_BIT(UCSRC, UMSEL);

	/* selecting frame options */
	UCSRC = 0;

	/*selecting Parity */
	UCSRC = (UCSRC & 0xCF) | ((UART_Config_Ptr->parity) << UPM0); // UPM0 is bit 4

	/*selecting Data length */
	/* Not a 9bit data mode */
	CLEAR_BIT(UCSRB, UCSZ2);

	/* 5,6,7 or 8 data length mode */
	UCSRC = (UCSRC & 0xF9) | ((UART_Config_Ptr->dataSize) << UCSZ0); //UCSZ0 is bit 1

	/*selecting stop bits */
	UCSRC = (UCSRC & 0xF7) | ((UART_Config_Ptr->stopBit) << USBS); //USBS is bit 3

	/* URSEL must be 0 while writing to UBRR */
	// CLEAR_BIT(UCSRC,URSEL);

	/* Selecting BaudRate : 9600 */
	UBRRH = BaudPrescaler >> 8;
	UBRRL = BaudPrescaler;
}

void UART_sendByte(const unsigned char Byte){
	while (BIT_IS_CLEAR(UCSRA, UDRE)) {}
	UDR = Byte;
}

unsigned char UART_receiveByte(void){
	while (BIT_IS_CLEAR(UCSRA, RXC)) {}
    return UDR;
}