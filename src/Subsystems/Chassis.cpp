#include <Subsystems/Chassis.h>
#include "../Commands/drivewithJoystick.h"
#include "../RobotMap.h"

#define FORWARD_MOTOR_SPEED .5
#define BACKWARD_MOTOR_SPEED -.5
#define FORWARD_MOTOR_SPEED_FAST 1.0
#define BACKWARD_MOTOR_SPEED_FAST -1.0

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
	robotDrive.TankDrive(FORWARD_MOTOR_SPEED_FAST, BACKWARD_MOTOR_SPEED_FAST, true);
}

void Chassis::turnClockwise()//auto-aligns if right sensor>left sensor
{
	SmartDashboard::PutString("Turn CLockwise", "turn clockwise executed");
	robotDrive.TankDrive(FORWARD_MOTOR_SPEED, BACKWARD_MOTOR_SPEED, false);
}

void Chassis::turnCounterClockwise()//auto-aligns if left sensor > right sensor
{
	SmartDashboard::PutString("Turn Counter CLockwise", "turn counter clockwise executed");
	robotDrive.TankDrive(BACKWARD_MOTOR_SPEED, FORWARD_MOTOR_SPEED, false);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

