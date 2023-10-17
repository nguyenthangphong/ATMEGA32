#include "SPI.h"

void SPI_initMaster() {
	SPI_PORT_DIR |= (1 << SS) | (1 << MOSI) | (1 << SCK);
	SPCR |= (1 << SPE) | (1 << MSTR);
}

void SPI_initSlave() {
	SPI_PORT_DIR |= (1 << MISO);
	SPCR |= (1 << SPE);
}

void SPI_sendByte(unsigned char data) {
	SPDR = data;
	while(BIT_IS_CLEAR(SPSR, SPIF));
}

unsigned char SPI_receiveByte() {
	while (BIT_IS_CLEAR(SPSR, SPIF));
	return SPDR;
}

void SPI_sendString(unsigned char *str) {
	while(*str) {
		SPI_sendByte(*str);
		str++;
	}
}

void SPI_receiveString(unsigned char *str) {
	unsigned char i = 0;
	str[i] = SPI_receiveByte();
	while(str[i] != '#') {
		i++;
		str[i] = SPI_receiveByte();
	}
	str[i] = '\0';
}