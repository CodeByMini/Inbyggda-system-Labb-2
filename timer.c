#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

//Calculate Output Compare value

//((clock speed/prescaler) * delay)-1
//(16000000/1024)*(10/1000)-1

uint16_t OutputCompare(uint16_t prescaler, uint8_t milliseconds){
	uint16_t freq_scaled = F_CPU/prescaler; //15625
	uint16_t seconds = milliseconds/1000;   //0,01
	uint16_t ticks = freq_scaled*seconds;   //156,25 ~ 156
	ticks = ticks - 1;						//Correct for starting at 0

	return ticks;
}

void timer_init() {
	//
    /*Enable CTC*/
	TCCR0A &= ~(1 << WGM00);
	TCCR0A |= (1 << WGM01);
	TCCR0A &= ~(1 << WGM02);

    /*prescaler 1024*/
	TCCR0B |= (1 << CS00) | (1 << CS02);
	TCCR0A &= ~(1 << CS01);
    
	/* Frequency based on prescaler 1024 and 10 milliseconds*/
	OCR0A = OutputCompare(1024, 10);
    
	/*Counter init 0*/
	TCNT0 = 0;
}