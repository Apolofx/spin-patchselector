/*
Binary counter with uController for controlling FV-1 spinsemi patch selection
uController: Attiny85
Additional hardware: 10kB Potentiometer
Description: The code reads analog input from a potentiometer and converts it to a byte data, it uses only 3 bits though.
			The obtained byte is used to write PORTB in order to set Spin FV1's state on 
			S0 S1 S2 ports and manage the EEPROM patch selection.
*/
#include <avr/io.h>

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


