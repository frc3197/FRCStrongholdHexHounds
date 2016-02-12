/*#include <Commands/Autonomous.h>
#include <Commands/autoDrive.h>
#include <Commands/AutoDriveDefense.h>
#include <unistd.h>
#include <Commands/autoSquaredAlign.h>
#include <Commands/autoShoot.h>
#include <Commands/testCommand.h>

Autonomous::Autonomous()
{
	AddSequential(new testCommand());//drives over defense
	AddSequential(new AutoDriveDefense());//drives to batter
	AddSequential(new autoSquaredAlign());//auto aligns
	AddSequential(new autoShoot());//shoots
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

//Called just before this Command runs the first time
void Autonomous::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Autonomous::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Autonomous::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous::Interrupted()
{

}*/
