#include "DIO.h"

unsigned char decimaltoOctal(unsigned char deciNum) {
    unsigned char octalNum = 0, countval = 1;

    while (deciNum != 0) {
        int remainder = deciNum % 8;
        octalNum += remainder * countval;
        countval = countval * 10;
        deciNum /= 8;
    }

    return octalNum;
}

unsigned char DIO_WriteChannel(channel_t channelNumber, level_t level){
	unsigned char Octal;
	unsigned char error = 0;
	Octal = decimaltoOctal(channelNumber);
	switch((Octal / 10)){
	case A:
		switch(level){
		case LOW:
			SET_BIT(DDRA, (Octal % 10));
			CLEAR_BIT(PORTA, (Octal % 10));
			break;
		case HIGH:
			SET_BIT(DDRA, (Octal % 10));
			SET_BIT(PORTA, (Octal % 10));
			break;
		}
		break;
	case B:
		switch(level){
		case LOW:
			SET_BIT(DDRB, (Octal % 10));
			CLEAR_BIT(PORTB, (Octal % 10));
			break;
		case HIGH:
			SET_BIT(DDRB, (Octal % 10));
			SET_BIT(PORTB, (Octal % 10));
			break;
		}
		break;
	case C:
		switch(level){
		case LOW:
			SET_BIT(DDRC, (Octal % 10));
			CLEAR_BIT(PORTC, (Octal % 10));
			break;
		case HIGH:
			SET_BIT(DDRC, (Octal % 10));
			SET_BIT(PORTC, (Octal % 10));
			break;
		}
		break;
	case D:
		switch(level){
		case LOW:
			SET_BIT(DDRD, (Octal % 10));
			CLEAR_BIT(PORTD, (Octal % 10));
			break;
		case HIGH:
			SET_BIT(DDRD, (Octal % 10));
			SET_BIT(PORTD, (Octal % 10));
			break;
		}
		break;
	default:
		error = 1;
	}

	return error;
}

unsigned char DIO_ReadChannel(channel_t channelNumber){
	unsigned char Octal;
	unsigned char pinState;
	Octal = decimaltoOctal(channelNumber);
    switch((Octal / 10)){
    case A:
        CLEAR_BIT(DDRA, (Octal % 10));
        if(BIT_IS_CLEAR(PINA, (Octal % 10))){
            pinState = 0;
        }else {
            pinState = 1;
        }
        break;
    case B:
        CLEAR_BIT(DDRB, (Octal%10));
        if(BIT_IS_CLEAR(PINB, (Octal%10))){
            pinState = 0;
        }else {
            pinState = 1;
        }
        break;
    case C:
        CLEAR_BIT(DDRC, (Octal % 10));
        if(BIT_IS_CLEAR(PINC, (Octal % 10))){
            pinState = 0;
        }else {
            pinState = 1;
        }
        break;
    case D:
        CLEAR_BIT(DDRD, (Octal % 10));
        if(BIT_IS_CLEAR(PIND, (Octal % 10))){
            pinState = 0;
        }else {
            pinState = 1;
        }
        break;
    default:
        pinState = 3;
    }

	return pinState;
}