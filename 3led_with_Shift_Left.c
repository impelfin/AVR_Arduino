#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{	
	DDRB = 0x07;  // 0b00000111; 
	
    while (1) 
    {
		(for i=0;i<3;i++){
			PORTB = 1<<i;
			_delay_ms(1000);
		}
    }
}

