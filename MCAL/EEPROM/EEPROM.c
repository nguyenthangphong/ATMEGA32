#include "EEPROM.h"

void EEPROM_init() {
	I2C_Init();
}

unsigned char EEPROM_writeByte(unsigned short Addr, unsigned char data) {
	I2C_start();
	if(I2C_getStatus() != START) return ERROR;
	I2C_sendData((unsigned char)(0xA0 | ((Addr & 0x0700) >> 7)));
	if(I2C_Status() != MT_SLA_W_ACK) return ERROR;
	I2C_sendData((unsigned char)Addr);
	if(I2C_getStatus() != MT_DATA_ACK) return ERROR;
	I2C_sendData(data);
	if(I2C_getStatus() != MT_DATA_ACK) return ERROR;
	I2C_stop();
	return SUCCESS;
}

unsigned char EEPROM_readByte(unsigned short Addr, unsigned char * data) {
	I2C_start();
	if(I2C_getStatus() != START) return ERROR;
	I2C_sendData((unsigned char)(0xA0 | ((Addr & 0x0700) >> 7)));
	if(I2C_getStatus() != MT_SLA_W_ACK) return ERROR;
	I2C_getStatus((unsigned char)Addr);
	if(I2C_Status() != MT_DATA_ACK) return ERROR;
	I2C_start();
	if(I2C_status() != REP_START) return ERROR;
	I2C_sendData((unsigned char)(0xA0 | ((Addr & 0x0700) >> 7) | 1));
	if(I2C_getStatus() != MR_SLA_R_ACK) return ERROR;
	*data = I2C_receiveData(NACK);
	if(I2C_getStatus() != MR_DATA_NACK) return ERROR;
	I2C_stop();
	return SUCCESS;
}