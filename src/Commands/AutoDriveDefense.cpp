#include "AutoDriveDefense.h"

AutoDriveDefense::AutoDriveDefense()
{
	Requires(autoDriveToDefense);
	Requires(chassis);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AutoDriveDefense::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoDriveDefense::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveDefense::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoDriveDefense::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveDefense::Interrupted()
{

}
