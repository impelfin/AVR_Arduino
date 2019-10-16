#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

#define DEBOUCE_MS 1000

int main(void) {
	DDRB |= (1<<PB0) | (1<<PB1);
	DDRD &= ~(1<<PD7);
	PORTB &= ~((1<<PB0) | (1<<PB1));

	while (1) {
		if(PIND & (1<<D7)) {
//			PORTB |= (1<<PB0) | (1<<PB1);
			PORTB &= ~((1<<PB0) | (1<<PB1)) ;
			} else {
			PORTB |= (1<<PB0) | (1<<PB1);
//			PORTB &= ~((1<<PB0) | (1<<PB1)) ;
		}
	}
}
