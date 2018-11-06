/*
 * Uno_7Segment_Anode_PORTD.c
 *
 * Created: 2018-10-23 오후 1:27:59
 * Author : KW
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
int i=0;
unsigned char digit[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void display_7segled(unsigned char led[], unsigned int number) {
	PORTD = led[number];
}

int main(void) {
	DDRD = 0xFF;

	while(1) {
		display_7segled(digit,i%10);
		_delay_ms(DEBOUCE_MS);
		i++;
	}
	return 0;	
}
