#include "KEYPAD.h"

unsigned char keys[4][4] = {
    { '7', '8', '9', '%' },
    { '4', '5', '6', '*' },
    { '1', '2', '3', '-' },
    { 'c', '0', '=', '+' }
};

void KEYPAD_init(void) {
    KEYPAD_PORT_DIR = 0x0F;
    KEYPAD_PORT = 0xFF;
}

unsigned char KEYPAD_getKey(void) {
    unsigned char key = 'x';
    int i, j;

    for (i = 0; i < 4; i++) {
        KEYPAD_PORT = (~(0x08) >> i);
        for (j = 0; j < 4; j++) {
            if (BIT_IS_CLEAR(KEYPAD_PIN, (j + 4))) {
                key = keys[3 - i][j];
            }
        }
    }
    return key;
}