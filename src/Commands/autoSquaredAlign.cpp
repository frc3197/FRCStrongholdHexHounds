#include "autoSquaredAlign.h"
#include "OI.h"

#define ERROR_RANGE 1.5

autoSquaredAlign::autoSquaredAlign()
{
	Requires(chassis);// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void autoSquaredAlign::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void autoSquaredAlign::Execute()
{

			if(oi->getRangeDif() >= ERROR_RANGE)
			{
				chassis->turnClockwise();
			}

			else if(oi->getRangeDif() <= -ERROR_RANGE)
			{
				chassis->turnCounterClockwise();
			}

}

// Make this return true when this Command no longer needs to run execute()
bool autoSquaredAlign::IsFinished()
{
	if(oi->getRangeDif() < ERROR_RANGE && oi->getRangeDif() > -ERROR_RANGE)
	{
		chassis->tankDrive2(0, 0);
		return true;
	}

	else
		return false;
}

// Called once after isFinished returns true
void autoSquaredAlign::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoSquaredAlign::Interrupted()
{

}
