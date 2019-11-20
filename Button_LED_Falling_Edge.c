#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

//#define DEBOUCE_MS 500

int main(void) {
	DDRB = 0x21;
	
	unsigned char o_sw, n_sw, led_state=0;
	
	o_sw = PINB & (1<<PINB1);
	
	while (1) {
		n_sw = PINB & (1<<PINB1);
		if(o_sw != 0 && n_sw == 0) {
			if(led_state == 0) {
				PORTB |= (1<<PB0) | (1<<PB5);
				led_state = 1;
			} else {
				PORTB &= ~((1<<PB0) | (1<<PB5));
				led_state = 0;
			}
		}
		o_sw = n_sw;
	}
}
