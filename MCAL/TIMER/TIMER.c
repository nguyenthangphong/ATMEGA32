#include "TIMER.h"

static volatile void (*TIMER0_OVF_callBackPtr)(void) = NULL;
static volatile void (*TIMER0_COMP_callBackPtr)(void) = NULL;

static volatile void (*TIMER1_OVF_callBackPtr)(void) = NULL;
static volatile void (*TIMER1_COMPA_callBackPtr)(void) = NULL;

static volatile void (*TIMER2_OVF_callBackPtr)(void) = NULL;
static volatile void (*TIMER2_COMP_callBackPtr)(void) = NULL;

ISR(TIMER0_OVF_vect) {
	if(TIMER0_OVF_callBackPtr != NULL) {
		(*TIMER0_OVF_callBackPtr)();
	}
}

ISR(TIMER0_COMP_vect) {
	if(TIMER0_COMP_callBackPtr != NULL) {
		(*TIMER0_COMP_callBackPtr)();
	}
}

ISR(TIMER1_OVF_vect){
	if(TIMER1_OVF_callBackPtr != NULL) {
		(*TIMER1_OVF_callBackPtr)();
	}
}

ISR(TIMER1_COMPA_vect){
	if(TIMER1_COMPA_callBackPtr != NULL) {
		(*TIMER1_COMPA_callBackPtr)();
	}
}

ISR(TIMER2_OVF_vect){
	if(TIMER2_OVF_callBackPtr != NULL) {
		(*TIMER2_OVF_callBackPtr)();
	}
}

ISR(TIMER2_COMP_vect){
	if(TIMER2_COMP_callBackPtr != NULL) {
		(*TIMER2_COMP_callBackPtr)();
	}
}

unsigned char TIMER_init(const TIMER_configType * TIMER_configType) {
	switch (TIMER_configType->timer) {

	case TIMER_0:
        TCCR0 = (1 << FOC0);
        TCCR0 = (TCCR0 & 0xF8) | (TIMER_configType->prescaler);
        TCNT0=(unsigned char)TIMER_configType->initialValue;

        switch (TIMER_configType->timerMode) {
        case OVERFLOW:
            TCCR0 |= (1 << WGM01) | (1 << WGM00);
            TIMSK |= (1 << TOIE0);
            break;
        case COMPARE_MATCH:
            TCCR0 |= (1 << WGM01);
            OCR0 = (unsigned char)TIMER_configType->compareValue;
            TIMSK |= (1 << OCIE0);
            break;
        default:
            return 15;
        }
	    break;

	case TIMER_1:
        TCCR1A = (1<<FOC1A);
        TCCR1B = 0;
        TCCR1B = (TCCR1B & 0xF8) | (TIMER_configType->prescaler);
        TCNT1=TIMER_configType->initialValue;
        switch(TIMER_configType->timerMode) {
        case OVERFLOW:
            TIMSK |= (1 << TOIE1);
            break;

        case COMPARE_MATCH:
            TCCR1B |= (1 << WGM12);
            OCR1A = TIMER_configType->compareValue;
            TIMSK |= (1 << OCIE1A);
            break;
        default:
            return 15;
        }
	    break;

	case TIMER_2:
		TCCR2 = (1 << FOC2);
		TCCR2 = (TCCR2 & 0xF8) | (TIMER_configType->prescaler);
		TCNT2=(unsigned char)TIMER_configType->initialValue;
		switch(TIMER_configType->timerMode){
		case OVERFLOW:
			TCCR2 |= (1 << WGM21) | (1 << WGM20);
			TIMSK |= (1 << TOIE2);
		    break;

		case COMPARE_MATCH:
			TCCR2 |= (1 << WGM21);
			OCR2 = (unsigned char)TIMER_configType->compareValue;
			TIMSK |= (1 << OCIE2);
		    break;

		default:
			return 15;
		}
	    break;
	default:
		return 5;
	}

    return 0;
}

void TIMER_setTimer0OverFlowBack(void(*a_ptr)(void)) {
    TIMER0_OVF_callBackPtr = a_ptr;
}

void TIMER_setTimer0CompareCallBack(void(*a_ptr)(void)) {
	TIMER0_COMP_callBackPtr  = a_ptr;
}

void TIMER_setTimer1OverFlowBack(void(*a_ptr)(void)) {
	TIMER1_COMPA_callBackPtr = a_ptr;
}

void TIMER_setTimer1CompareCallBack(void(*a_ptr)(void)) {
    TIMER1_COMPA_callBackPtr = a_ptr;
}

void TIMER_setTimer2OverFlowBack(void(*a_ptr)(void)) {
	TIMER2_OVF_callBackPtr = a_ptr;
}

void TIMER_setTimer2CompareCallBack(void(*a_ptr)(void)) {
	TIMER2_COMP_callBackPtr = a_ptr;
}

void TIMER_stop(TIMER_t timer){
	switch(timer){
	case TIMER_0 :
		TCCR0 = (TCCR0 & 0xF8) | 0;
		break;
	case TIMER_1 :
		TCCR1B = (TCCR1B & 0xF8) | 0;
		break;
	case TIMER_2 :
		TCCR2 = (TCCR2 & 0xF8) | 0;
		break;
	}
}

void TIMER_clearCounter(TIMER_t timer){
	switch(timer){
	case TIMER_0 :
		TCNT0 = 0;
		break;
	case TIMER_1 :
		TCNT1 = 0 ;
		break;
	case TIMER_2 :
		TCNT2 = 0;
		break;
	}
}

void TIMER_resume(TIMER_t timer, TIMER_PRESCALER prescaler){
	switch(timer){
	case TIMER_0 :
		TCCR0 = (TCCR0 & 0xF8) | prescaler;
		break;
	case TIMER_1 :
		TCCR1B = (TCCR1B & 0xF8) | prescaler;
		break;
	case TIMER_2 :
		TCCR2 = (TCCR2 & 0xF8) | prescaler;
		break;
	}
}