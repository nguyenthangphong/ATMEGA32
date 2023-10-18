#ifndef ADC_H_
#define ADC_H_

#include "../../UTLIS/micro_config.h"
#include "../../UTLIS/common_macros.h"
#include "../../UTLIS/std_types.h"

void ADC_init();
unsigned short ADC_read(unsigned char num_pin);

#endif /* ADC_H_ */