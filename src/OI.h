#ifndef OI_H
#define OI_H
//hi
#include "WPILib.h"

class OI
{
private:
	Joystick stick;
public:
	OI();
	float getLeft();
	float getRight();
};

#endif
