#include "ADC.h"

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1);
	ADMUX = 0;
}

unsigned short ADC_read(unsigned char num_pin) {
	ADMUX |= (num_pin & 0x1F);
	SET_BIT(ADCSRA, ADSC);
	while(BIT_IS_CLEAR(ADCSRA, ADIF));
	SET_BIT(ADCSRA, ADIF);
	return ADC;
}