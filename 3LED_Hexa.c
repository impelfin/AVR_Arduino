#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{	
	DDRB = 0x07;  // 0b00000111; 
	
    while (1) 
    {
		PORTB = 0x01;	// 0b00000001;
		_delay_ms(1000);
		
		PORTB = 0x02;	// 0b00000010;
		_delay_ms(1000);
		
		PORTB = 0x04;	// 0b00000100;
		_delay_ms(1000);
    }
}

