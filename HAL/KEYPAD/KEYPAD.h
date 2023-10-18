#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../UTLIS/micro_config.h"
#include "../../UTLIS/common_macros.h"
#include "../../UTLIS/std_types.h" 

#define KEYPAD_PORT PORTA
#define KEYPAD_PIN PINA
#define KEYPAD_PORT_DIR DDRA

void KEYPAD_init(void);
unsigned char KEYPAD_getKey(void);

#endif /* KEYPAD_H_ */