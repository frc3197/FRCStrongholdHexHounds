#include "ClimberUp.h"
#include "../RobotMap.h"

ClimberUp::ClimberUp() :
		Subsystem("ClimberUp"),
		CAN7(7)
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

// Put methods for controlling this subsystem
// here. Call these from Commands.

