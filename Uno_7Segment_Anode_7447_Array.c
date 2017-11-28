/*
 * Uno_7Segment_Anode_7447_Array.c
 *
 * Created: 2017-11-19 ¿ÀÈÄ 7:08:45
 * Author : Moon
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define DEBOUCE_MS 500

unsigned int digit[] = {0,1,0,8,2,8,8,2,0,7,5};

int main(void)
{
	DDRB = 0xFF;
	PORTB = 0x00;
		
	while(1) {
		for(int i=0; i<(sizeof(digit)/sizeof(int)); i++) {
			PORTB = digit[i];
			_delay_ms(DEBOUCE_MS);
		}
	}
}