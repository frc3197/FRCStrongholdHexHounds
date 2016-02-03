#include "autoDrive.h"
#include "AutoDriveDefense.h"
//#include "CommandGroup.h"
#define TIME 5

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

	while(time.Get() < TIME/*chassis->GetEncodeDistance() <= 122 + 17*/)
	{
		chassis->SetCan1Speed(.25);
		chassis->SetCan2Speed(-.25);
		chassis->SetCan3Speed(-.25);
		chassis->SetCan4Speed(.25);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool autoDrive::IsFinished()
{
	if(time.Get() >= TIME/*chassis->GetEncodeDistance() <= 122 + 16*/)
	{
		SmartDashboard::PutString("AutoDrive Over", "booyeah!");
		chassis->SetCan1Speed(0);
		chassis->SetCan2Speed(0);
		chassis->SetCan3Speed(0);
		chassis->SetCan4Speed(0);
		return true;
	}
	else
	{
		SmartDashboard::PutString("AutoDrive Over", "Nope");
		return false;
	}
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
