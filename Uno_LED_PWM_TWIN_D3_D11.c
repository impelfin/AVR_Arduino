/*
 * Uno_LED_PWM_TWIN_D3_D11.c
 *
 * Created: 2017-11-01 ¿ÀÀü 12:02:28
 * Author : Moon
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/delay.h>

#define D0 PD0
#define D1 PD1
#define D2 PD2
#define D3 PD3
#define D4 PD4
#define D5 PD5
#define D6 PD6
#define D7 PD7
#define D8 PB0
#define D9 PB1
#define D10 PB2
#define D11 PB3
#define D12 PB4
#define D13 PB5
#define A0 PC0
#define A1 PC1
#define A2 PC2
#define A3 PC3
#define A4 PC4
#define A5 PC5

#define DEBOUCE_MS 10

int main (void)
{
	DDRB |= _BV(D11);
	DDRD |= _BV(D3);

	TCCR2A |= _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
	TCCR2B |= _BV(CS22);

	uint8_t pwm = 0x00;
	bool up = true;
	for(;;) {
		
		OCR2A = pwm;
		OCR2B = pwm;

		pwm += up ? 1 : -1;
		if (pwm == 0xff)
		up = false;
		else if (pwm == 0x00)
		up = true;

		_delay_ms(DEBOUCE_MS);
	}
}
