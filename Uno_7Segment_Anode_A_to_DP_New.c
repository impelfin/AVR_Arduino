#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

#define DEBOUCE_MS 500

int main(void) {
    DDRB = 0x0F;	// DDRB = 0b00001111;
	DDRD = 0xF0;	// DDRD = 0b11110000;
	PORTB = 0x0F;
	PORTD = 0xF0;
	
    while (1) {
		for(int i=0;i<8; ++i) {
			if(i<4) {
				PORTD = 0xE0<<i;	// 0b11100000;
			} else {
				PORTB =	0xFE<<(i%4);	// 0b11111110;
			}
			_delay_ms(DEBOUCE_MS);
		}
		PORTB = 0xFF;
		PORTD = 0xFF;
	}
}
