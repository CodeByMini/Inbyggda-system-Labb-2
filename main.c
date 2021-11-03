#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>

#include "led.h"
#include "timer.h"

int main (void) {
	LED_init();
	timer_init();

	int count = 0;

	while (1) {
		if(TIFR0 & (1<<OCF0A)){
			TIFR0 |= (1<<OCF0A);
			count++;
		}
		if (count >= 10) {
		   	BIT_FLIP(PORTB,RED);
			count = 0;
		}	
	}
	return 1;
}