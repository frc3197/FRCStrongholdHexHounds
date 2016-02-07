#include "ClimberUp.h"
#include "../RobotMap.h"

ClimberUp::ClimberUp() :
		Subsystem("ClimberUp"),
		CAN7(7),
		limitSwitchDown(3),
		limitSwitchMiddle(4),
		limitSwitchTop(5)
{

}

void ClimberUp::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void ClimberUp::setCANTalon7(float val)
{
	CAN7.Set(val);
}

bool ClimberUp::getBottomSwitch()
{
	return limitSwitchDown.Get();
}

bool ClimberUp::getMiddleSwitch()
{
	return limitSwitchMiddle.Get();
}

bool ClimberUp::getTopSwitch()
{
	return limitSwitchTop.Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

