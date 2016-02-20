#include "ClimberUp.h"
#include "../RobotMap.h"
#include "Commands/Climber.h"

ClimberUp::ClimberUp() :
		Subsystem("ClimberUp"),
		CAN7(7),
		limitSwitchDown(5),
		limitSwitchMiddle(6),
		limitSwitchTop(7)
{

}

void ClimberUp::InitDefaultCommand()
{
	SetDefaultCommand(new Climber());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void ClimberUp::setCANTalon7(float val)
{
	CAN7.Set(-val);//sets climber motor speed
}

bool ClimberUp::getBottomSwitch()
{
	return limitSwitchDown.Get();//returns bottom limit switch
}

bool ClimberUp::getMiddleSwitch()
{
	return limitSwitchMiddle.Get();//returns middle limit switch (when climber arm angle = 90 deg
}

bool ClimberUp::getTopSwitch()
{
	return limitSwitchTop.Get();//returns top limit switch
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

