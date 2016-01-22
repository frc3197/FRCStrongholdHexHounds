#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
}

float OI::getForward(float yVal){
	if(yVal<.1&&yVal>-.1){
		yVal = 0;
	}
	return yVal;
}

