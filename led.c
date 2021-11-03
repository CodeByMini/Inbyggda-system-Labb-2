#include <avr/io.h>
#include "led.h"

void LED_init() {
	/*Set the DDRB registry for pin 9-11 to be an outputs*/
    DDRB |= (1<<BLUE_PIN);
    DDRB |= (1<<GREEN_PIN);
    DDRB |= (1<<RED_PIN);

    /*Flip the bits so they start high, ie: led off*/
    PORTB |= (1 << BLUE);
    PORTB |= (1 << GREEN);
    PORTB |= (1 << RED);
}

uint8_t simple_ramp(uint8_t *pwm, uint8_t *dir){
	if(*pwm == 255 || *pwm == 0){
		*dir *= -1;
	}
	*pwm += *dir;
	return *pwm;
}
