#ifndef _LED_H_
#define _LED_H_

/*if position b in byte b is set to 1 set it to 0 and vice versa*/
#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))

#define BLUE_PIN DDB1
#define GREEN_PIN DDB2
#define RED_PIN DDB3

#define BLUE PB1
#define GREEN PB2
#define RED PB3

void LED_init(void);

#endif

