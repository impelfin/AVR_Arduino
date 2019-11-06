/*
 * Uni_7Segment_Anode_Array.c
 *
 * Created: 2017-11-19 ¿ÀÈÄ 6:18:51
 * Author : Moon
 */ 

#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

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
