#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

#define DEBOUCE_MS 500

int main(void) {
	DDRB = 0xFF;
		
	while(1) {
			PORTB |= 1<<PB0;
			_delay_ms(DEBOUCE_MS);
			PORTB &= ~(1<<PB0);
			_delay_ms(DEBOUCE_MS);
	}
}
