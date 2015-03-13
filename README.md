# Arduino_LED_Display
Arduino Library for controlling an 4 digit 7 segment LED alphanumeric display using a shift register.

This code uses drives a 4 digit alphanumeric LED display: [LINK](https://www.sparkfun.com/products/11408) using a shift register: [LINK] (https://www.sparkfun.com/products/733)... Please see the file schematic.pdf for details on how to hook up the circuit.

PLEASE CHECKOUT THE FILE: example.ino to see a basic usage of the library...

####Steps:
1. Import the library with the line:

	include "alphanumeric.h" //Remeber to use a # at the begining of the line #include "alphanumeric.h"

2. Create an instance of the class:

	Alphanumeric alpha;

3. Declare your pins as integers:

	int latchpin = 4; 
	int clockpin = 3;
	int datapin = 2;
	int dig3 = 10;
	int dig2 = 11;
	int dig4 = 12;
	int dig1 = 13;

4. To setup the pins that will be used to drive the shiftregister and the digits from the display use this line on the setup():

	alpha.setupPins(int latchpin, int clockpin, int datapin, int dig1Pin, int dig2Pin, int dig3Pin, int dig4Pin);

5. To write a number to one of the digits in the display use this line on the loop():

	alpha.alphaWrite(int numbToDisplay, int DIGIT);

6. If you want to write a 4 digit number like 4719 use the count function:

	alpha.count(4719);

PLEASE FEEL FREE TO DO WHATEVER YOU WANT WITH THIS CODE!!!


