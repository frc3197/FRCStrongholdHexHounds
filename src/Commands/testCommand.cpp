#include "testCommand.h"

testCommand::testCommand()
{
	Requires(chassis);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void testCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void testCommand::Execute()
{
	chassis->tankDrive2( -.35, -.35);
}

// Make this return true when this Command no longer needs to run execute()
bool testCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void testCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void testCommand::Interrupted()
{

}
