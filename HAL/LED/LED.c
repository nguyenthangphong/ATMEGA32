#include "LED.h"

void LED_init(void) {
    SET_BIT(LED_PORT_DIR, LED_PIN);
}

void LED_turnOn(void) {
    SET_BIT(LED_PORT, LED_PIN);
}

void LED_turnOff(void) {
    CLEAR_BIT(LED_PORT, LED_PIN);
}