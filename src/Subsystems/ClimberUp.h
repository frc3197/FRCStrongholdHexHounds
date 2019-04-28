#ifndef CLIMBERUP_H
#define CLIMBERUP_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ClimberUp: public Subsystem
{
private:
	CANTalon CAN7;
	DigitalInput limitSwitchDown;
	DigitalInput limitSwitchMiddle;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ClimberUp();
	void InitDefaultCommand();
	void setCANTalon7(float val);
	bool getBottomSwitch();
	bool getMiddleSwitch();
};

#endif
