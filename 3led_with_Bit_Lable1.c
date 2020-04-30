#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 1<<DDB2 | 1<<DDB1 | 1<<DDB0 ;  // 0b00000111;
	
	while (1)
	{
		PORTB = 0x00;
		PORTB = 1<<PB0;	// 0b00000001;
		_delay_ms(1000);
		
		PORTB = 0x00;
		PORTB = 1<<PB1;	// 0b00000010;
		_delay_ms(1000);
		
		PORTB = 0x00;
		PORTB = 1<<PB2;	// 0b00000100;
		_delay_ms(1000);
	}
}

