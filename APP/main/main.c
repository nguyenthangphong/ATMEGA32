#include "../../HAL/LED/LED.h"

int main() {
    LED_init();
    while (1) {
        LED_turnOn();
        _delay_ms(500);
        LED_turnOff();
        _delay_ms(500);
    }
    return 0;
}