#include "Arm.h"
#include "../RobotMap.h"
#include "Commands/ArmMover.h"

Arm::Arm() :
		Subsystem("ExampleSubsystem"),
		can8(8),//can 8
		limitSwitchUp(8),//top limit switch
		limitSwitchDown(9)//bottom limit switch
{

}

void Arm::InitDefaultCommand()
{
	SetDefaultCommand(new ArmMover());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

bool Arm::getLimitSwitchUp()
{
	return !limitSwitchUp.Get();//returns top limit switch
}

bool Arm::getLimitSwitchDown()
{
	return !limitSwitchDown.Get();//returns bottom limit switch
}

void Arm::setCan8Speed(float val)
{
	can8.Set(val);//sets can 8 speed
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

