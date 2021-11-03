#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

uint16_t OutputCompare(uint16_t prescaler, uint8_t milliseconds){
	uint16_t freq_scaled = F_CPU/prescaler; //15625
	uint16_t seconds = milliseconds/1000;   //0,016
	uint16_t ticks = freq_scaled*seconds;   //250
	ticks = ticks - 1;						//Correct for starting at 0

	return ticks;
}

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

	   /*Enable CTC*/
	TCCR0A &= ~(1 << WGM00);
	TCCR0A |= (1 << WGM01);
	TCCR0A &= ~(1 << WGM02);

    /*prescaler 1024*/
	TCCR0B |= (1 << CS00) | (1 << CS02);
	TCCR0A &= ~(1 << CS01);
    
	/* Frequency based on prescaler 1024 and 16 milliseconds*/
	OCR0A = OutputCompare(1024, 16);
    
	/*Counter init 0*/
	TCNT0 = 0;
}