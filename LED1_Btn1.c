#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB = DDRB | (1<<PB0);
	DDRD = DDRD & ~(1<<PD5);
	
	int sw;
	
    	while (1) {
		sw = PIND & (1<<PD5);
		
		if(sw == 0) {
			PORTB = PORTB | (1<<PB0);
		} else {
			PORTB = PORTB & ~(1<<PB0);
		}
    	}
}
