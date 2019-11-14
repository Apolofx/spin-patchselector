/*
Binary counter with uController for controlling FV-1 spinsemi patch selection
uController: Attiny85
Additional hardware: 10kB Potentiometer
*/
#include <avr/io.h>
// elegir el contador desde PB hasta PB2 me permite setear todo el puerto de una en PORTB
int S0 = 0, S1 = 1, S2 = 2, potPin = 3, lastread, potState;

void setup() 
{
	DDRB |= (1 << S0) | (1 << S1) | (1 << S2); //set counter outputs
	DDRB &= ~(1 << potPin); // sets pot input
	PORTB &= ~((1 << S0) | (1 << S1) | (1 << S2));

	lastread = analogRead(potPin);
}

void loop()
{
	lastread = map(analogRead(potPin), 0, 1023, 0, 7);

	if (PORTB != lastread)
	{
		PORTB = lastread;
	}
}


