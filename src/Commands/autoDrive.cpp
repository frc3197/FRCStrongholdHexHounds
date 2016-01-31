#include "autoDrive.h"
#include "AutoDriveDefense.h"
//#include "CommandGroup.h"

autoDrive::autoDrive()
{
 	Requires(chassis);
}

// Called just before this Command runs the first time
void autoDrive::Initialize()
{
	time.Reset();
	time.Start();
}

// Called repeatedly when this Command is scheduled to run
void autoDrive::Execute()
{
	if(time.Get() < 5/*chassis->GetEncodeDistance() <= 10*/)
	{
		chassis->SetCan1Speed(.25);
		chassis->SetCan2Speed(-.25);
		chassis->SetCan3Speed(-.25);
		chassis->SetCan4Speed(.25);
	}
	else if(time.Get() >= 5/*chassis->GetEncodeDistance() <= 20 && chassis->GetEncodeDistance() >= 10*/)
	{
		chassis->SetCan1Speed(-.75);
		chassis->SetCan2Speed(.75);
		chassis->SetCan3Speed(.75);
		chassis->SetCan4Speed(-.75);
	}
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
