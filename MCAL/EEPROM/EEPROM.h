#ifndef EEPROM_H_
#define EEPROM_H_

#include "../../MCAL/I2C/I2C.h"

unsigned char EEPROM_writeByte(unsigned short address, unsigned char data);
unsigned char EEPROM_readByte(unsigned short address, unsigned char * data);

#endif /* EEPROM_H_ */