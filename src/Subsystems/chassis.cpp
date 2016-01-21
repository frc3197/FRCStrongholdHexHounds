#include "Chassis.h"
#include "../RobotMap.h"

Chassis::Chassis() :
		Subsystem("Chassis")
{
	leftStick(0), rightStick(1), can1(1), can2(2), can3(3), can4(4),
	robotDrive(can1,can2,can3,can4)
}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Chassis::tankDrive(){
	robotDrive(leftStick, rigthStick, true);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

