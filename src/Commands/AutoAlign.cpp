#include "AutoAlign.h"

AutoAlign::AutoAlign()
{
	Requires(autoTurn);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AutoAlign::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoAlign::Execute()
{
	if((oi->getButtonX()) && ((oi->getRangeDif() >= 2) || (oi->getRangeDif() <= -2)))
	{
		if(oi->getRangeDif() >=2)
		{
			autoTurn->turnClockwise();
		}
		else
		{
			autoTurn->turnCounterClockwise();
		}
	}
	else if(oi->getButtonLB())
	{
		autoTurn->reverse180();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAlign::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoAlign::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoAlign::Interrupted()
{

}
