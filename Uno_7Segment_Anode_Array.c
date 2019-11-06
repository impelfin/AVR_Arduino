/*
 * Uni_7Segment_Anode_Array.c
 *
 * Created: 2017-11-19 ¿ÀÈÄ 6:18:51
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

unsigned char digit_b[] = {0x04, 0x0F, 0x02, 0x0B, 0x01, 0x09, 0x00, 0x0D, 0x00, 0x09};
unsigned char digit_d[] = {0x00, 0x90, 0x40, 0x00, 0x90, 0x20, 0x20, 0x80, 0x00, 0x00};
	
void display_7segled(unsigned int number) {
	PORTB = digit_b[number];
	PORTD = digit_d[number];
}

int main(void) {
	DDRB = 0xFF;
	DDRD = 0xFF;
	
	while(1) {
		for (int i=0; i<10; i++) {
			display_7segled(i);
			_delay_ms(DEBOUCE_MS);
		}
	}
}
