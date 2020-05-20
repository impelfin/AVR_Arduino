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
	for(int i=0; i<8; ++i) {	
		if(i<4) {
			PORTB = 0xFF;
			PORTD = 0xEF<<i;	//0b11101111;
		} else {
			PORTD = 0xFF;
			PORTB = ~(0x01<<(i%4));
		}
		_delay_ms(DEBOUCE_MS);
	}
    }
}
