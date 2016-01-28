#include "AutoTurn.h"
#include "../RobotMap.h"
#include "../Commands/AutoAlign.h"

#define FORWARD_MOTOR_SPEED .5
#define BACKWARD_MOTOR_SPEED -.5
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
	time.Start();
	drive.TankDrive(FORWARD_MOTOR_SPEED_FAST, BACKWARD_MOTOR_SPEED_FAST, true);
	if(time.Get() >= 2)
	{
		drive.TankDrive(0.0, 0.0, true);
		time.Reset();
	}
}

void AutoTurn::turnClockwise()
{
	drive.TankDrive(FORWARD_MOTOR_SPEED, BACKWARD_MOTOR_SPEED, true);
}

void AutoTurn::turnCounterClockwise()
{
	drive.TankDrive(BACKWARD_MOTOR_SPEED, FORWARD_MOTOR_SPEED, true);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

