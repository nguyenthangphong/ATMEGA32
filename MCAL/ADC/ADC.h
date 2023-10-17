#ifndef ADC_H_
#define ADC_H_

#include "Micro_config.h"
#include "Common_Macros.h"
#include "Std_Types.h"

void ADC_init();
unsigned short ADC_read(unsigned char num_pin);

#endif /* ADC_H_ */