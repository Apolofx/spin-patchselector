# Spin-Patchselector
## Binary counter with uController for controlling FV-1 spinsemi patch selection
- uController: Attiny85.
- Additional hardware: 10kB Potentiometer.
- Description: The code reads analog input from a potentiometer and converts it to a byte data, it uses only 3 bits though.
			The obtained byte is used to write PORTB in order to set Spin FV1's state on 
			S0 S1 S2 ports and manage the EEPROM patch selection.
