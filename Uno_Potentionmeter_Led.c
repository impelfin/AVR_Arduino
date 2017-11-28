/*
 * Uno_Potentionmeter_Led.c
 *
 * Created: 2017-11-07 ¿ÀÈÄ 11:36:21
 * Author : Moon
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
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

#define DEBOUCE_MS 1000

static inline void initADC0(void) {
	ADMUX |= (1<<REFS0);                //reference voltage on AVCC
	ADCSRA |= (1<<ADPS1) | (1<<ADPS0); //ADC clock prescaler /8
	ADCSRA |= (1<<ADEN);                //enables the ADC
}

int main(void) {
	uint16_t potentionmeterValue;
	uint16_t threshold_level;
	threshold_level = 0x80;
	DDRB |= (1<<D12);
		
	initADC0();
	
    while (1) {
		ADCSRA |= (1<<ADSC);   //start ADC convertion;
		loop_until_bit_is_clear(ADCSRA, ADSC);  //wait until ADC conversion is done
		potentionmeterValue = ADC;  //read ADC value in
		if (potentionmeterValue > threshold_level) {
			PORTB |= (1<<D12);
		} else {
			PORTB &= ~(1<<D12);
		}
	}
}

