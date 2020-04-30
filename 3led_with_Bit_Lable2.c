#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 1<<DDB2 | 1<<DDB1 | 1<<DDB0 ;  
	
	while (1)
	{
		PORTB = PORTB & ~(1<<PB2 | 1<<PB1 | 1<<PB0);
		
		PORTB = PORTB | 1<<PB0;
		_delay_ms(1000);
				
		PORTB = PORTB & ~(1<<PB0) | 1<<PB1;
		_delay_ms(1000);
				
		PORTB = PORTB & ~(1<<PB1) | 1<<PB2;
		_delay_ms(1000);
	}
}

