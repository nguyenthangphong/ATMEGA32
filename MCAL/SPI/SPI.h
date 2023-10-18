#ifndef SPI_H_
#define SPI_H_

#include "../../UTLIS/micro_config.h"
#include "../../UTLIS/common_macros.h"
#include "../../UTLIS/std_types.h"

#define SS              PB4
#define MOSI            PB5
#define MISO            PB6
#define SCK             PB7
#define SPI_PORT_DIR    DDRB

void SPI_receiveString(unsigned char * str);
void SPI_sendString(unsigned char * str);
unsigned char SPI_receiveByte();
void SPI_sendByte(unsigned char data);
void SPI_initSlave();
void SPI_initMaster();

#endif /* SPI_H_ */