/*
 * Uno_Test.c
 *
 * Created: 2017-10-17 ¿ÀÈÄ 9:29:32
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

#define DEBOUCE_MS 1000

int main(void)
{
    DDRB = 0xFF;
    DDRD = 0xFF;
	
	while (1) 
    {	
		// D5 On
		PORTB = 0x00;
		PORTD = 0x20;
		_delay_ms(DEBOUCE_MS);
		
		// D6 On		
		PORTB = 0x00;
		PORTD = 0x40;
		_delay_ms(DEBOUCE_MS);
		
		// D7 On
		PORTB = 0x00;
		PORTD = 0x80;
		_delay_ms(DEBOUCE_MS);
		
		// D8 On		
		PORTB = 0x01;
		PORTD = 0x00;
		_delay_ms(DEBOUCE_MS);

		// D9 On
		PORTB = 0x02;
		PORTD = 0x00;
		_delay_ms(DEBOUCE_MS);

		// D10 On		
		PORTB = 0x04;
		PORTD = 0x00;
		_delay_ms(DEBOUCE_MS);

		// D11 On
		PORTB = 0x08;
		PORTD = 0x00;
		_delay_ms(DEBOUCE_MS);
		
		// D12 On
		PORTB = 0x10;
		PORTD = 0x00;
		_delay_ms(DEBOUCE_MS);		
		
		// D5, D6, D7, D8 On
		PORTB = 0x01;
		PORTD = 0xE0;
		_delay_ms(DEBOUCE_MS);

		// D9, D10, D11, D12 On
		PORTB = 0x1E;
		PORTD = 0x00;
		_delay_ms(DEBOUCE_MS);
		
		// D5, D6, D7, D8, D9, D10, D11, D12 On
		PORTB = 0x1F;
		PORTD = 0xE0;
		_delay_ms(DEBOUCE_MS);
    }
}

