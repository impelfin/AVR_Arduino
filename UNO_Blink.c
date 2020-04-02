#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define DEBOUCE_MS 200

int main(void)
{
	DDRB = 0xFF;
	DDRD = 0xFF;
	
	while (1)
	{
		// D13 On
		PORTB = 0x20;
		_delay_ms(DEBOUCE_MS);
		
		// D13 Off
		PORTB = 0x00;
		_delay_ms(DEBOUCE_MS);
	}
}
