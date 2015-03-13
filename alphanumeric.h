/*
alphanumeric.h - Library description.
Created by fito_segrera, Feb-2015.
http://fii.to
*/

#ifndef Alphanumeric_h
#define Alphanumeric_h

#include "Arduino.h"

class Alphanumeric{
  public:
  	//Alphanumeric(int digits);
  	void setupPins(int latchpin, int clockpin, int datapin, int dig1, int dig2, int dig3, int dig4);
  	void alphaWrite(int number, int digit);
  	void count(int number);
  	void setDigit(int dig);
};
#endif