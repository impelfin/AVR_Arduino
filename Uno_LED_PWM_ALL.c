//UNO AVR PWM - D6
int main (void) 
{
	DDRD |= _BV(D6);

	TCCR0A |= _BV(COM0A1) | _BV(WGM00) | _BV(WGM01);
	TCCR0B |= _BV(CS00);

	uint8_t pwm = 0x00;
	bool up = true;
	for(;;) {

		OCR0A = pwm;

		pwm += up ? 1 : -1;
		if (pwm == 0xff)
		up = false;
		else if (pwm == 0x00)
		up = true;

		_delay_ms(DEBOUCE_MS);
	}
}


//UNO AVR PWM - D5
int main (void)
{
	DDRD |= _BV(D5);

	TCCR0A |= _BV(COM0B1) | _BV(WGM00) | _BV(WGM01);
	TCCR0B |= _BV(CS00);

	uint8_t pwm = 0x00;
	bool up = true;
	for(;;) {

		OCR0B = pwm;

		pwm += up ? 1 : -1;
		if (pwm == 0xff)
		up = false;
		else if (pwm == 0x00)
		up = true;

		_delay_ms(DEBOUCE_MS);
	}
}


//UNO AVR PWM - D9
int main (void) 
{
	DDRB |= _BV(D9);

	TCCR1A |= _BV(COM1A1) | _BV(WGM10);
	TCCR1B |= _BV(CS10) | _BV(WGM12);

	uint8_t pwm = 0x00;
	bool up = true;
	for(;;) {

		OCR1A = pwm;

		pwm += up ? 1 : -1;
		if (pwm == 0xff)
			up = false;
		else if (pwm == 0x00)
			up = true;

		_delay_ms(DEBOUCE_MS);
	}
}


//UNO AVR PWM - D10
int main (void)
{
	DDRB |= _BV(D10);

	TCCR1A |= _BV(COM1B1) | _BV(WGM10);
	TCCR1B |= _BV(CS10) | _BV(WGM12);

	uint8_t pwm = 0x00;
	bool up = true;
	for(;;) {

		OCR1B = pwm;

		pwm += up ? 1 : -1;
		if (pwm == 0xff)
		up = false;
		else if (pwm == 0x00)
		up = true;

		_delay_ms(DEBOUCE_MS);
	}
}


//UNO AVR PWM - D11
int main (void)
{
	DDRB |= _BV(D11);

	TCCR2A |= _BV(COM2A1) | _BV(WGM21) | _BV(WGM20);
	TCCR2B |= _BV(CS22);

	uint8_t pwm = 0x00;
	bool up = true;
	for(;;) {

		OCR2A = pwm;

		pwm += up ? 1 : -1;
		if (pwm == 0xff)
		up = false;
		else if (pwm == 0x00)
		up = true;

		_delay_ms(DEBOUCE_MS);
	}
}


//UNO AVR PWM - D3
int main (void)
{
	DDRD |= _BV(D3);

	TCCR2A |= _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
	TCCR2B |= _BV(CS22);

	uint8_t pwm = 0x00;
	bool up = true;
	for(;;) {

		OCR2B = pwm;

		pwm += up ? 1 : -1;
		if (pwm == 0xff)
		up = false;
		else if (pwm == 0x00)
		up = true;

		_delay_ms(DEBOUCE_MS);
	}
}
