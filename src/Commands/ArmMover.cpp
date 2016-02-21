#include "ArmMover.h"

#define MOTORSPEED .8

ArmMover::ArmMover()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(arm);
}

// Called just before this Command runs the first time
void ArmMover::Initialize()
{
	arm->setCan8Speed(0);
	limitSwitchUp = false;
	limitSwitchDown = false;
	finish = false;
}

// Called repeatedly when this Command is scheduled to run
void ArmMover::Execute()
{
	limitSwitchUp = arm->getLimitSwitchUp();
	limitSwitchDown = arm->getLimitSwitchDown();

	if(oi->getClimberButton2())//moves arm down
	{
		if(!limitSwitchDown)
		{
			arm->setCan8Speed(MOTORSPEED);
		}
		else
		{
			finish = true;
		}
	}
	else if(oi->getClimberButton3())//moves arm up
	{
		if(!limitSwitchUp)
		{
			arm->setCan8Speed(-MOTORSPEED);
		}
		else
		{
			finish = true;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMover::IsFinished()
{
	if(finish)
	{
		arm->setCan8Speed(0);
	}
	return finish;
}

// Called once after isFinished returns true
void ArmMover::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMover::Interrupted()
{

}
