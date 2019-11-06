/*
 * Uno_7Segment_Anode_PORTD.c
 *
 * Created: 2018-10-23 오후 1:27:59
 * Author : KW
 */ 

#define F_CPU 16E6
#include <avr/io.h>
#include <util/delay.h>

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
