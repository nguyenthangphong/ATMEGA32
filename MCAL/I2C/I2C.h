#ifndef I2C_H_
#define I2C_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#define START 			0x08
#define REP_START 		0x10
#define MT_SLA_W_ACK 	0x18
#define MR_SLA_R_ACK 	0x40
#define MR_DATA_ACK 	0x50
#define MR_DATA_NACK 	0x58
#define SR_OWN_SLA_W 	0x60
#define MT_DATA_ACK 	0x28

typedef enum { NACK, ACK } I2C_ACKorNACK;
typedef enum { WRITE, READ } I2C_RW;
typedef enum { _1_I2C, _4_I2C, _16_I2C, _64_I2C } I2C_bitRatePrescaler;

typedef struct {
	I2C_bitRatePrescaler prescaler;
	unsigned char bitRate;
	unsigned char slaveModeAddress;
} I2C_configType;

void I2C_init(const I2C_configType * I2C_Config_Ptr);
void I2C_sendData(unsigned char data);
unsigned char I2C_receiveData(I2C_ACKorNACK ack/*, unsigned char * data */);
unsigned char I2C_getStatus(void);
void I2C_start(void);
void I2C_stop(void);
unsigned char I2C_MTR_Seq(unsigned char *data, unsigned char SLA, I2C_RW R_W);

#endif /* I2C_H_ */