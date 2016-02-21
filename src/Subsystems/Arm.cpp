#include "Arm.h"
#include "../RobotMap.h"
#include "Commands/ArmMover.h"

Arm::Arm() :
		Subsystem("ExampleSubsystem"),
		can8(8),
		limitSwitchUp(9),
		limitSwitchDown(10)
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
	return limitSwitchUp.Get();
}

bool Arm::getLimitSwitchDown()
{
	return limitSwitchDown.Get();
}

void Arm::setCan8Speed(float val)
{
	can8.Set(val);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

