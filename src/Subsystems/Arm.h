#ifndef ARM_H
#define ARM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arm: public Subsystem
{
private:
	CANTalon can8;
	DigitalInput limitSwitchUp;
	DigitalInput limitSwitchDown;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Arm();
	void InitDefaultCommand();
	bool getLimitSwitchUp();
	bool getLimitSwitchDown();
	void setCan8Speed(float val);
};

#endif
