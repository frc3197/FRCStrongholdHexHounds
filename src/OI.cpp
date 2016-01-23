#include "OI.h"

OI::OI():
	stick(0)
{
	// Process operator interface input here.
}

float OI::getLeft(){
	float yVal = stick.GetRawAxis(1);
	if((yVal<.1)&&(yVal>-.1)){
		yVal = 0;
	}
	return -yVal;
}

float OI::getRight(){
	float yVal = stick.GetRawAxis(5);
	if((yVal<.1)&&(yVal>-.1)){
		yVal = 0;
	}
	return -yVal;
}

