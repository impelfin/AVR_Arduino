/*
 * Uno_7Segment_Cathode_Array.c
 *
 * Created: 2017-11-19 ¿ÀÈÄ 6:39:07
 * Author : Moon
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define DEBOUCE_MS 500

unsigned char digit_b[] = {0x0B, 0x00, 0x0D, 0x04, 0x0E, 0x06, 0x0F, 0x02, 0x0F, 0x06};
unsigned char digit_d[] = {0xF0, 0x60, 0xB0, 0xF0, 0x60, 0xD0, 0xD0, 0x70, 0xF0, 0xF0};

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
