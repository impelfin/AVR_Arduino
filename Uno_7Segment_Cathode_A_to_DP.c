#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

#define D0 PD0
#define D1 PD1
#define D2 PD2
#define D3 PD3
#define D4 PD4
#define D5 PD5
#define D6 PD6
#define D7 PD7
#define D8 PB0
#define D9 PB1
#define D10 PB2
#define D11 PB3
#define D12 PB4
#define D13 PB5
#define A0 PC0
#define A1 PC1
#define A2 PC2
#define A3 PC3
#define A4 PC4
#define A5 PC5

#define DEBOUCE_MS 500

int main(void) {
	DDRB = 0x0F;
	DDRD = 0xF0;
	
	while (1) {
		for (int i = 0; i < 8; ++i) {
			if (i < 4) {
				PORTB = 0;
				PORTD = 0x10 << i;
			} else {
				PORTD = 0;
				PORTB = 0x01 << (i % 4);
			}
			_delay_ms(DEBOUCE_MS);
		}
	}
}
