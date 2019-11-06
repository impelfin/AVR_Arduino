/*
 * Uno_7Segment_Anode_7447.c
 *
 * Created: 2017-11-19 ¿ÀÈÄ 7:08:45
 * Author : Moon
 */ 

#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

#define DEBOUCE_MS 500

int main(void) {
	DDRB = 0xFF;
	PORTB = 0x00;
	
	while(1) {
		for (int i=0; i<16; i++) {
			PORTB = i;
			_delay_ms(DEBOUCE_MS);
		}
	}
}
