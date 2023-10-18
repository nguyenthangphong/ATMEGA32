#ifndef DIO_H_
#define DIO_H_

#include "../../UTLIS/micro_config.h"
#include "../../UTLIS/common_macros.h"
#include "../../UTLIS/std_types.h"

unsigned char decimaltoOctal(unsigned char deciNum);
unsigned char DIO_WriteChannel(channel_t channelNumber, level_t level);
unsigned char DIO_ReadChannel(channel_t channelNumber);

#endif /* DIO_H_ */