#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"


/*
clock speed / (prescaler * (TOP + 1))
16000000 / (64 * (255+1)) = 976,5625
*/
void timer_init() {
    /*Fast PWM*/
	TCCR2A |= (1 << WGM20);
	TCCR2A |= (1 << WGM21);
	TCCR2B &= ~(1 <<  WGM22); 

	/*Non inverting Mode*/
	TCCR2A &= ~(1 << COM2A0);
	TCCR2A |= (1 << COM2A1);
	
    /*Prescaler 64*/
	TCCR2B &= ~(1 << CS20) | (1 << CS21);
	TCCR2B |= (1 << CS22);
}