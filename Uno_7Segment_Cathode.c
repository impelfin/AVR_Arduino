/*
 * Uno_7Segment_Cathode.c
 *
 * Created: 2017-11-07 ¿ÀÈÄ 8:22:36
 * Author : Moon
 */ 

#define F_CPU 16000000UL

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

#define DEBOUCE_MS 300

int main(void)
{
	DDRB = 0xFF;
	DDRD = 0xFF;
	PORTB = 0x00;
	PORTD = 0x00;
	
	while (1)
	{
		// 0
		//PORTB |= ~((1<<D8) | (1<<D9) | (0<<D10) | (1<<D11));
		//PORTD |= ~((1<<D4) | (1<<D5) | (1<<D6) | (1<<D7));
		PORTB=0x0B;
		PORTD=0xF0;
		_delay_ms(DEBOUCE_MS);

		// 1
		//PORTB |= ~((0<<D8) | (0<<D9) | (0<<D10) | (0<<D11));
		//PORTD |= ~((0<<D4) | (1<<D5) | (1<<D6) | (0<<D7));
		PORTB=0x00;
		PORTD=0x60;
		_delay_ms(DEBOUCE_MS);

		// 2
		//PORTB |= ~((1<<D8) | (0<<D9) | (1<<D10) | (1<<D11));
		//PORTD |= ~((1<<D4) | (1<<D5) | (0<<D6) | (1<<D7));
		PORTB=0x0D;
		PORTD=0xB0;
		_delay_ms(DEBOUCE_MS);

		// 3
		//PORTB |= ~((0<<D8) | (0<<D9) | (1<<D10) | (0<<D11));
		//PORTD |= ~((1<<D4) | (1<<D5) | (1<<D6) | (1<<D7));
		PORTB=0x04;
		PORTD=0xF0;
		_delay_ms(DEBOUCE_MS);

		// 4
		//PORTB |= ~((0<<D8) | (1<<D9) | (1<<D10) | (1<<D11));
		//PORTD |= ~((0<<D4) | (1<<D5) | (1<<D6) | (0<<D7));
		PORTB=0x0E;
		PORTD=0x60;
		_delay_ms(DEBOUCE_MS);

		// 5
		//PORTB |= ~((0<<D8) | (1<<D9) | (1<<D10) | (0<<D11));
		//PORTD |= ~((1<<D4) | (0<<D5) | (1<<D6) | (1<<D7));
		PORTB=0x06;
		PORTD=0xD0;
		_delay_ms(DEBOUCE_MS);

		// 6
		//PORTB |= ~((1<<D8) | (1<<D9) | (1<<D10) | (1<<D11));
		//PORTD |= ~((1<<D4) | (0<<D5) | (1<<D6) | (1<<D7));
		PORTB=0x0F;
		PORTD=0xD0;
		_delay_ms(DEBOUCE_MS);

		// 7
		//PORTB |= ~((0<<D8) | (1<<D9) | (0<<D10) | (0<<D11));
		//PORTD |= ~((1<<D4) | (1<<D5) | (1<<D6) | (0<<D7));
		PORTB=0x02;
		PORTD=0x70;
		_delay_ms(DEBOUCE_MS);

		// 8
		//PORTB |= ~((1<<D8) | (1<<D9) | (1<<D10) | (1<<D11));
		//PORTD |= ~((1<<D4) | (1<<D5) | (1<<D6) | (1<<D7));
		PORTB=0x0F;
		PORTD=0xF0;
		_delay_ms(DEBOUCE_MS);

		// 9
		//PORTB |= ~((0<<D8) | (1<<D9) | (1<<D10) | (0<<D11));
		//PORTD |= ~((1<<D4) | (1<<D5) | (1<<D6) | (1<<D7));
		PORTB=0x06;
		PORTD=0xF0;
		_delay_ms(DEBOUCE_MS);	
	}

}