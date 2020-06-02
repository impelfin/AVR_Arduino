#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

#define DEBOUCE_MS 1000

int main(void) {
	DDRB = 0x03;
	DDRD = 0x30;
	
	while (1) {
		PORTB = 0x02;			// M1 forward
		PORTD = 0x00;
 		_delay_ms(DEBOUCE_MS);
		PORTB = 0x01;			// M1 backward
		PORTD = 0x00;
		_delay_ms(DEBOUCE_MS);
		PORTB = 0x00;			// M2 forward
		PORTD = 0x10;
		_delay_ms(DEBOUCE_MS);
		PORTB = 0x00;			// M2 backward
		PORTD = 0x20;
		_delay_ms(DEBOUCE_MS);
		PORTB = 0x02;			// M1, M2 forward
		PORTD = 0x10;
		_delay_ms(DEBOUCE_MS);
		PORTB = 0x01;			// M1, M2 backward
		PORTD = 0x20;
		_delay_ms(DEBOUCE_MS);			
	}
}
