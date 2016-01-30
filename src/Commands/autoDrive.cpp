#include "autoDrive.h"

autoDrive::autoDrive()
{
	Requires(autoDriveToDefense);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void autoDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void autoDrive::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool autoDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void autoDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoDrive::Interrupted()
{

}
