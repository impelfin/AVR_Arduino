#define F_CPU 16E6

#define S0	PD5
#define S1	PD6
#define S2	PD7

#define D0	PB0
#define D1	PB1
#define D2	PB2
#define D3	PB3
#define D4	PB4

#include <avr/io.h>

int main(void) {
	DDRB |= 1<<D4 | 1<<D3 | 1<<D2 | 1<<D1 | 1<<D0;
	DDRD &= ~(1<<S2) & ~(1<<S1) & ~(1<<S0);
	
	while (1) {
		if(!(PIND & (1<<S0))) {
			PORTB |= 1<<D1 | 1<<D0;
		} else {
			PORTB &= ~(1<<D1) & ~(1<<D0);
		}
		
		if(!(PIND & (1<<S1))) {
			PORTB |= 1<<D2;
		} else {
			PORTB &= ~(1<<D2);
		}
		
		if(!(PIND & (1<<S2))) {
			PORTB |= 1<<D4 | 1<<D3;
		} else {
			PORTB &= ~(1<<D4) & ~(1<<D3);
		}
	}
}
