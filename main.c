#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>

#include "led.h"
#include "timer.h"

int main (void) {
	LED_init();
	timer_init();

	uint8_t direction = 1;
	uint8_t pwmvalue = 1;

	while (1) {
		if(TIFR0 & (1<<OCF0A)){
			TIFR0 |= (1<<OCF0A);
			OCR2A = simple_ramp(&pwmvalue, &direction);
		}
	}
	return 1;
}