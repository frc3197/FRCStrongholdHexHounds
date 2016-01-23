#include <Subsystems/Chassis.h>
#include "../Commands/drivewithJoystick.h"
#include "../RobotMap.h"

OI* oi = NULL;

Chassis::Chassis():
	Subsystem("Chassis"),
	stick(0), can1(1), can2(2), can3(3), can4(4),
	robotDrive(can3,can2,can1,can4)
{
	robotDrive.SetSafetyEnabled(false);
}

void Chassis::InitDefaultCommand()
{
	SetDefaultCommand(new driveWithJoystick());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Chassis::tankDrive(){
	robotDrive.TankDrive(oi->getForward(-stick.GetRawAxis(1)),oi->getForward(-stick.GetRawAxis(5)), true);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

