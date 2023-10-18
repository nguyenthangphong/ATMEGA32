#include "BUZZER.h"

void BUZZER_On(void) {
    DIO_WriteChannel(BUZZER_CHANNEL, HIGH);
}

void BUZZER_Off(void) {
    DIO_WriteChannel(BUZZER_CHANNEL, LOW);
}