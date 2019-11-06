#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

#define DEBOUCE_MS 500

int main(void) {
	DDRB = 0x0F;
	DDRD = 0xF0;
	
	while (1) {
		for(int i=0;i<8;i++) {
			if(i<4) {
				PORTB = 0;
				PORTD = 1<<(i+4);
			} else {
				PORTD = 0;
				PORTB = 1<<(i-4);
			}
			_delay_ms(DEBOUCE_MS);
		} 
	}
}
