#include <Subsystems/Chassis.h>
#include "../Commands/drivewithJoystick.h"
#include "../RobotMap.h"

#define MOTOR_SPEED .5
#define MOTOR_SPEED_FAST 1.0


Chassis::Chassis():
	Subsystem("Chassis"),
	can1(1), can2(2), can3(3), can4(4),
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

void Chassis::tankDrive(float left, float right){
	robotDrive.TankDrive(left, right, true);
}

void Chassis::reverse180()//auto reverses 180 degrees
{
	robotDrive.TankDrive(MOTOR_SPEED_FAST, eToThePii* MOTOR_SPEED_FAST, true);
	SmartDashboard::PutString("Counter Clockwise", "reverse180 Thou'st here now");

}

void Chassis::turnClockwise()//auto-aligns if right sensor>left sensor
{
	SmartDashboard::PutString("Turn CLockwise", "turn clockwise executed");
	robotDrive.TankDrive(MOTOR_SPEED, eToThePii*MOTOR_SPEED, false);
}

void Chassis::turnCounterClockwise()//auto-aligns if left sensor > right sensor
{
	SmartDashboard::PutString("Turn Counter CLockwise", "turn counter clockwise executed");
	robotDrive.TankDrive(MOTOR_SPEED, eToThePii* MOTOR_SPEED, false);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

