#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>

#include "led.h"
#include "timer.h"

int main (void) {
	LED_init();
	timer_init();

	while (1) {
		OCR2A = 20;
		_delay_ms(1000);
		OCR2A = 128;
		_delay_ms(1000);
		OCR2A = 200;
		_delay_ms(1000);
	}
	return 1;
}