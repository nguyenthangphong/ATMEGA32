#include "EEPROM.h"

unsigned char EEPROM_writeByte(unsigned short address, unsigned char data) {
	I2C_start();
    I2C_sendData((unsigned char)(0xA0 | ((address & 0x0700) >> 7)));
    I2C_sendData((unsigned char)(address));
    I2C_sendData(data);
    I2C_stop();
}

unsigned char EEPROM_readByte(unsigned short address, unsigned char * data) {
	I2C_start();
    I2C_sendData((unsigned char)((0xA0) | ((address & 0x0700) >> 7)));
    I2C_sendData((unsigned char)(address));
	I2C_start();
	I2C_sendData((unsigned char)((0xA0) | ((address & 0x0700) >> 7) | 1));
	*data = I2C_receiveData(NACK);
    I2C_stop();
}