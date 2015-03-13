/*
alphanumeric.cpp - Library for writing on a 7 segments 
LED display using a shiftRegister 74HC595 and an atmega328p
Created by fito_segrera, Feb-2015.
http://fii.to
*/

#include "Arduino.h"
#include "alphanumeric.h"

int numbers[] = {
	2, // 00000010 		--> Display #0
	158, // 10011110 	--> Display #1
	68, // 01000100 	--> Display #2
	12, // 00001100 	--> Display #3
	152, // 10011000 	--> Display #4
	40, // 00101000 	--> Display #5
	32, // 00100000 	--> Display #6
	30, // 00011110 	--> Display #7
	0, // 00000000 		--> Display #8
	24, // 00011000 	--> Display #9
};

int l, c, d, D1, D2, D3, D4;

// Alphanumeric::Alphanumeric(int digits){
// }

void Alphanumeric::setupPins(int latchpin, int clockpin, int datapin, int dig1, int dig2, int dig3, int dig4){
	pinMode(latchpin, OUTPUT); // Shiftregister's latch pin
	pinMode(clockpin, OUTPUT); // Shiftregister's clock pin
	pinMode(datapin, OUTPUT); // Shiftregister's data pin
	pinMode(dig1, OUTPUT); // Display's digit 1
	pinMode(dig2, OUTPUT); // Display's digit 2
	pinMode(dig3, OUTPUT); // Display's digit 3
	pinMode(dig4, OUTPUT); // Display's digit 4
	l = latchpin;
	c = clockpin;
	d = datapin;
	D1 = dig1;
	D2 = dig2;
	D3 = dig3;
	D4 = dig4;
}

void Alphanumeric::setDigit(int dig){
	switch(dig){
	   case 1 :
	      	digitalWrite(D1, HIGH);
		    digitalWrite(D2, LOW);
		    digitalWrite(D3, LOW);
		    digitalWrite(D4, LOW);
	      	break;
	   case 2 :
	   		digitalWrite(D1, LOW);
		    digitalWrite(D2, HIGH);
		    digitalWrite(D3, LOW);
		    digitalWrite(D4, LOW);
			break;
	   case 3 :
	      	digitalWrite(D1, LOW);
		    digitalWrite(D2, LOW);
		    digitalWrite(D3, HIGH);
		    digitalWrite(D4, LOW);
	      	break;
	   case 4 :
	      	digitalWrite(D1, LOW);
		    digitalWrite(D2, LOW);
		    digitalWrite(D3, LOW);
		    digitalWrite(D4, HIGH);
	      	break;
   	}
}

void Alphanumeric::alphaWrite (int number, int digit){
	int b;
	int n = number;
	//Get the decimal equivalent to the binarry corresponding
	//to the nuber tha will be written on the display
	for(int i = 0; i < sizeof(numbers); i++){
		if(i == n){
			b = numbers[i]; 
		}
	}
	//first set latch pin low so we can shift in data without disrupting the outputs
    digitalWrite(l, LOW);
    //set the digit of the display to write
    setDigit(digit);
    // shift out bits of data
    shiftOut(d, c, LSBFIRST, b);  
    //set latch pin high to send data to output pins
    digitalWrite(l, HIGH);
    //first set latch pin low so we can shift in data without disrupting the outputs
    delay(5);
}	

void Alphanumeric::count(int number){
	
	//Split the number into 4 digits
	int n4 = number%10;
    number /= 10;
    int n3 = number%10;
    number /= 10;
    int n2 = number%10;
    number /= 10;
    int n1 = number%10;
    number /=10;

    if(n4 > 0 && n3 == 0 && n2 == 0 && n1 == 0){
    	alphaWrite(n4, 4);
    }else if (n3 > 0 && n2 == 0 && n1 == 0){
    	alphaWrite(n4, 4);
    	alphaWrite(n3, 3);
    }else if (n2 > 0 && n1 == 0){
    	alphaWrite(n4, 4);
    	alphaWrite(n3, 3);
    	alphaWrite(n2, 2);
    }else if (n1 > 0){
    	alphaWrite(n4, 4);
    	alphaWrite(n3, 3);
    	alphaWrite(n2, 2);
    	alphaWrite(n1, 1);
    }
}