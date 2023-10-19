#include "I2C.h"

void I2C_init(const I2C_configType * I2C_Config_Ptr){
	TWBR = I2C_Config_Ptr->bitRate;
	TWSR = I2C_Config_Ptr->prescaler;
	TWAR = I2C_Config_Ptr->slaveModeAddress;
	TWCR = (1 << TWEN);
	PORTC |= (1 << PC0) | (1 << PC1);
}

void I2C_start(void){
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (BIT_IS_CLEAR(TWCR, TWINT));
}

void I2C_sendData(unsigned char data){
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (BIT_IS_CLEAR(TWCR, TWINT));
}

unsigned char I2C_receiveData(I2C_ACKorNACK ack){
	switch (ack){
    case NACK:
        TWCR = (1 << TWINT) | (1 << TWEN);
        break;
    case ACK:
        TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
        break;
	}
    while(BIT_IS_CLEAR(TWCR, TWINT));
    return TWDR;
}

unsigned char I2C_getStatus(void){
    return (TWSR & 0xF8);
}

void I2C_stop(void){
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

unsigned char I2C_MTR_Seq(unsigned char * data, unsigned char SLA, I2C_RW R_W){
	unsigned char SLA_R = (SLA << 1) | (0x01);
	unsigned char SLA_W = (SLA << 1) & (0xFE);

	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));

	if ((TWSR & 0xF8) != START){
	    return 1;
	}

	switch(R_W){
	case READ:
		TWDR = SLA_R;
		break;
	case WRITE:
		TWDR = SLA_W;
		break;
	}

	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));

	switch(R_W){
	case READ:
		if ((TWSR & 0xF8) != MR_SLA_R_ACK){
			return 1;
		}
		break;
	case WRITE:
		if ((TWSR & 0xF8) != MT_SLA_W_ACK){
			return 1;
		}
		break;
	}

	switch(R_W){
	case READ:
		*data = TWDR;
		break;
	case WRITE:
		TWDR = *data;
		break;
	}

	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));

	switch(R_W){
	case READ:
		if ((TWSR & 0xF8) != MR_DATA_ACK){
			return 1;
		}
		break;
	case WRITE:
		if ((TWSR & 0xF8) != MT_DATA_ACK){
			return 1;
		}
		break;
	}

	switch(R_W){
	case READ:
		TWCR = (1 << TWINT) | (1 << TWEN);
		if ((TWSR & 0xF8) != MR_DATA_NACK){
			return 1;
		}
		break;
	case WRITE:
		break;
	}

	/* Stop bit */
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);

	return 0;
}