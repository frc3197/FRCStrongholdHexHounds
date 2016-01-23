#include "driveWithJoystick.h"


driveWithJoystick::driveWithJoystick()
{
	Requires(chassis);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void driveWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void driveWithJoystick::Execute()
{
	chassis->tankDrive(oi->getLeft(),oi->getRight());
}

// Make this return true when this Command no longer needs to run execute()
bool driveWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void driveWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void driveWithJoystick::Interrupted()
{

}
