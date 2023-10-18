#include "UART.h"

void UART_init(const UART_configType * UART_Config_Ptr){
	unsigned short BaudPrescaler = ((F_CPU / (UART_Config_Ptr->baudRate)) - 1);
	SET_BIT(UCSRA, U2X);
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRC, URSEL);
	CLEAR_BIT(UCSRC, UMSEL);
	UCSRC = 0;
	UCSRC = (UCSRC & 0xCF) | ((UART_Config_Ptr->parity) << UPM0);
	CLEAR_BIT(UCSRB, UCSZ2);
	UCSRC = (UCSRC & 0xF9) | ((UART_Config_Ptr->dataSize) << UCSZ0);
	UCSRC = (UCSRC & 0xF7) | ((UART_Config_Ptr->stopBit) << USBS);
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