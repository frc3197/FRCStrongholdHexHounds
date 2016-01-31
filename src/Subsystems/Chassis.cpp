#include <Subsystems/Chassis.h>
#include "../Commands/drivewithJoystick.h"
#include "../RobotMap.h"

#define MOTOR_SPEED .5
#define MOTOR_SPEED_FAST .8


Chassis::Chassis():
	Subsystem("Chassis"),
	can1(1), can2(2), can3(3), can4(4),
	robotDrive(can3,can2,can1,can4),
	encode(1, 2, false, Encoder::k4X)
{
	robotDrive.SetSafetyEnabled(false);
}

void Chassis::InitDefaultCommand()
{
	SetDefaultCommand(new driveWithJoystick());
}

void Chassis::tankDrive(float left, float right)
{
	robotDrive.TankDrive(left, right, true);
}

void Chassis::reverse180() //auto reverses 180 degrees
{
	robotDrive.TankDrive(MOTOR_SPEED_FAST, -MOTOR_SPEED_FAST, true);
	SmartDashboard::PutString("Counter Clockwise", "*Slow Clap* You turned around!");
}

void Chassis::turnClockwise() //auto-aligns if right sensor>left sensor
{
	SmartDashboard::PutString("Turn CLockwise", "turn clockwise executed");
	robotDrive.TankDrive(-MOTOR_SPEED, MOTOR_SPEED, false);
}

void Chassis::turnCounterClockwise() //auto-aligns if left sensor > right sensor
{
	SmartDashboard::PutString("Turn Counter CLockwise", "turn counter clockwise executed");
	robotDrive.TankDrive(MOTOR_SPEED, -MOTOR_SPEED, false);
}

void Chassis::SetCan1Speed(float speed)
{
	can1.Set(speed);
}

void Chassis::SetCan2Speed(float speed)
{
	can2.Set(speed);
}

void Chassis::SetCan3Speed(float speed)
{
	can3.Set(speed);
}

void Chassis::SetCan4Speed(float speed)
{
	can4.Set(speed);
}

float Chassis::GetEncodeDistance()
{
	float distance = encode.Get();
	return distance;
}

void Chassis::ResetEncoder()
{
	encode.Reset();
}

void Chassis::Turn()
{
	robotDrive.TankDrive(MOTOR_SPEED_FAST, -MOTOR_SPEED_FAST, true);
}
