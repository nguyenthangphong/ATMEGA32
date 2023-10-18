#include "../../HAL/LED/LED.h"
#include "../../HAL/BUZZER/BUZZER.h"

int main() {
    LED_init();
    while (1) {
        LED_turnOn();
        _delay_ms(500);
        BUZZER_On();
        _delay_ms(500);
        LED_turnOff();
        _delay_ms(500);
        BUZZER_Off();
        _delay_ms(500);
    }
    return 0;
}