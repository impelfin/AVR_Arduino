/*
 * Uno_7Segment_Anode_7447.c
 *
 * Created: 2017-11-19 ¿ÀÈÄ 7:08:45
 * Author : Moon
 */ 

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
	DDRB = 0xFF;
		
	while(1) {
		for (int i=0; i<16; i++) {
			PORTB = i;
			_delay_ms(DEBOUCE_MS);
		}
	}
}
