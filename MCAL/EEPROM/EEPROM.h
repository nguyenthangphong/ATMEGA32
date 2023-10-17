#ifndef EEPROM_H_
#define EEPROM_H_

#include "../../MCAL/I2C/I2C.h"

#define ERROR 0
#define SUCCESS 1

void EEPROM_init();
unsigned char EEPROM_writeByte(unsigned short Addr, unsigned char data);
unsigned char EEPROM_readByte(unsigned short Addr, unsigned char * data);

#endif /* EEPROM_H_ */