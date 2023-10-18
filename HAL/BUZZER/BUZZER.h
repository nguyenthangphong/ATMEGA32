#ifndef _BUZZER_H
#define _BUZZER_H

#include "../../MCAL/DIO/DIO.h"
#include "../../UTLIS/micro_config.h"
#include "../../UTLIS/common_macros.h"
#include "../../UTLIS/std_types.h"

#define BUZZER_CHANNEL  8 

void BUZZER_On(void);
void BUZZER_Off(void);

#endif _BUZZER_H