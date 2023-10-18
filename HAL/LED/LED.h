#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../UTLIS/micro_config.h"
#include "../../UTLIS/common_macros.h"
#include "../../UTLIS/std_types.h"

#define LED_PORT_DIR DDRA
#define LED_PORT PORTA
#define LED_PIN PA0

void LED_init(void);
void LED_turnOn(void);
void LED_turnOff(void);

#endif /* LED_H_ */