#ifndef TIMER_H_
#define TIMER_H_

#include "../../UTLIS/micro_config.h"
#include "../../UTLIS/common_macros.h"
#include "../../UTLIS/std_types.h"

typedef enum { TIMER_0, TIMER_1, TIMER_2 } TIMER_t;
typedef enum { OVERFLOW, COMPARE_MATCH } TIMER_MODE;
typedef enum { OFF, _1_TIMER, _8_TIMER, _64_TIMER, _256_TIMER, _1024_TIMER } TIMER_PRESCALER;

typedef struct {
	TIMER_t timer;
	TIMER_MODE timerMode;
	TIMER_PRESCALER prescaler;
	unsigned short compareValue;
	unsigned short initialValue;
} TIMER_configType;

unsigned char TIMER_init(const TIMER_configType * TIMER_configType);
void TIMER_setTimer0OverFlowBack(void(*a_ptr)(void));
void TIMER_setTimer0CompareCallBack(void(*a_ptr)(void));
void TIMER_setTimer1OverFlowBack(void(*a_ptr)(void));
void TIMER_setTimer1CompareCallBack(void(*a_ptr)(void));
void TIMER_setTimer2OverFlowBack(void(*a_ptr)(void));
void TIMER_setTimer2CompareCallBack(void(*a_ptr)(void));
void TIMER_clearCounter(TIMER_t timer);
void TIMER_stop(TIMER_t timer);
void TIMER_resume(TIMER_t timer, TIMER_PRESCALER prescaler);

#endif /* TIMER_H_ */