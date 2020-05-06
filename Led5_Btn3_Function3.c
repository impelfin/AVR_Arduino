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
#include <util/delay.h>

#define DEBOUCE_MS 500

void S0_click() {
	for(int i=0;i<5;i++) {
		PORTB = 0x1F>>i;
		_delay_ms(DEBOUCE_MS);
	}
	PORTB = 0x00;
}

void S1_click() {
	PORTB = 0x00;
	for(int i=0;i<10;i++) {
		PORTB = PORTB ^ 0x1F;
		_delay_ms(DEBOUCE_MS);
	}
}

void S2_click() {
	for(int i=0;i<5;i++) {
		PORTB = 0x1F<<i;
		_delay_ms(DEBOUCE_MS);
	}
	PORTB = 0x00;
}

int main(void) {
	DDRB |= 1<<D4 | 1<<D3 | 1<<D2 | 1<<D1 | 1<<D0;
	DDRD &= ~(1<<S2) & ~(1<<S1) & ~(1<<S0);
	
	unsigned char o_sw0, o_sw1, o_sw2; 
	unsigned char n_sw0, n_sw1, n_sw2;
	unsigned char led_state0=1, led_state1=1, led_state2=1;
	
	o_sw0 = PIND & (1<<S0);
	o_sw1 = PIND & (1<<S1);
	o_sw2 = PIND & (1<<S2);
	
	while (1) {
		n_sw0 = PIND & (1<<S0);
		n_sw1 = PIND & (1<<S1);
		n_sw2 = PIND & (1<<S2);
		
		if(o_sw0 != 0 && n_sw0 == 0 && led_state0 != 0) {
			S0_click();
			led_state0 = 1;	
		}
		
		if(o_sw1 != 0 && n_sw1 == 0 && led_state1 != 0) {
			S1_click();
			led_state1 = 1;
		}
		
		if(o_sw2 != 0 && n_sw2 == 0 && led_state2 != 0 ) { 
			S2_click();
			led_state2 = 1;
		}
		
		o_sw0 = n_sw0;
		o_sw1 = n_sw1;
		o_sw2 = n_sw2;
	}
}

