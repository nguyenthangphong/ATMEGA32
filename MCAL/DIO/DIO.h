#ifndef DIO_H_
#define DIO_H_

#include "micro_config.h"
#include "common_macros.h"
#include "std_types.h"

unsigned char decimaltoOctal(unsigned char deciNum);
unsigned char DIO_WriteChannel(channel_t channelNumber, level_t level);
unsigned char DIO_ReadChannel(channel_t channelNumber);

#endif /* DIO_H_ */