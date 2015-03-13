#include "alphanumeric.h"

Alphanumeric alpha;
int latchpin = 4; 
int clockpin = 3;
int datapin = 2;
int dig3 = 10;
int dig2 = 11;
int dig4 = 12;
int dig1 = 13;

int r;
int number = 6;
int DIGIT = 4;

void setup(){
	alpha.setupPins(latchpin, clockpin, datapin, dig1, dig2, dig3, dig4);
	r = random(0, 10000);
}

void loop(){
	alpha.alphaWrite(number, DIGIT);
}
    