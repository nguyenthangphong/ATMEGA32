#include "UART.h"

void UART_init(){
	UBRRH = 0;
	UBRRL = 51;
	UCSRA = 0x00;
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
}

void UART_putChar(char data){
	while (BIT_IS_CLEAR(UCSRA, UDRE)) {}
	UDR = data;
}

unsigned char UART_getChar(void){
	while (BIT_IS_CLEAR(UCSRA, RXC)) {}
    return UDR;
}

void UART_writeString(char * string) {
	int i;
	for (i = 0; i < 255; i++) {
		if (string[i] != 0) {
			UART_putChar(string[i]);
		} 
		else {
			break;
		}
	}
}

void UART_readString(char * string) {
	char ch;
	int i;
	for (i = 0; i < 0; i++) {
		ch = UART_getChar();
		*string = ch;
		string++;
	}
}