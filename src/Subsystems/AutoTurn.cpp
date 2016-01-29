#include "AutoTurn.h"
#include "../RobotMap.h"
#include "../Commands/AutoAlign.h"

#define FORWARD_MOTOR_SPEED .75
#define BACKWARD_MOTOR_SPEED -.75
#define FORWARD_MOTOR_SPEED_FAST 1.0
#define BACKWARD_MOTOR_SPEED_FAST -1.0

AutoTurn::AutoTurn() :
		Subsystem("AutoTurn"), can1(1), can2(2), can3(3), can4(4),
		drive(can3, can2, can1, can4)
{
	drive.SetSafetyEnabled(false);
}

void AutoTurn::InitDefaultCommand()
{
	SetDefaultCommand(new AutoAlign());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void AutoTurn::reverse180()
{
	drive.TankDrive(FORWARD_MOTOR_SPEED_FAST, BACKWARD_MOTOR_SPEED_FAST, true);
}

void AutoTurn::turnClockwise()
{
	SmartDashboard::PutString("Turn CLockwise", "turn clockwise executed");
	drive.TankDrive(FORWARD_MOTOR_SPEED, BACKWARD_MOTOR_SPEED, false);
}

void AutoTurn::turnCounterClockwise()
{
	SmartDashboard::PutString("Turn Counter CLockwise", "turn counter clockwise executed");
	drive.TankDrive(BACKWARD_MOTOR_SPEED, FORWARD_MOTOR_SPEED, false);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

