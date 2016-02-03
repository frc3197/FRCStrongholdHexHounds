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
	chassis->ResetEncoder();
	oi->gyroReset();
	switch(num)
	{
	case 1:
		while(chassis->GetEncodeDistance() < (149.34))
		{
			chassis->tankDrive(.8, .8);
		}
		while(oi->getAngle() < 120)
		{
			chassis->tankDrive(.8, -.8);
		}
		chassis->ResetEncoder();
		while(chassis->GetEncodeDistance() < 68.1 - 17)
		{
			chassis->tankDrive(.8, .8);
		}
	break;

	case 2:
		while(chassis->GetEncodeDistance() < (137.59))
		{
			chassis->tankDrive(.8, .8);
		}
		while(oi->getAngle() < 120)
		{
			chassis->tankDrive(.8, -.8);
		}
		chassis->ResetEncoder();
		while(chassis->GetEncodeDistance() < 36.34 - 17)
		{
			chassis->tankDrive(.8, .8);
		}
	break;

	case 3:
		while(chassis->GetEncodeDistance() < 27.33)
		{
			chassis->tankDrive(.8, .8);
		}
		while(oi->getAngle() < 45)
		{
			chassis->tankDrive(.8, -.8);
		}
		chassis->ResetEncoder();
		while(chassis->GetEncodeDistance() < 54.0)
		{
			chassis->tankDrive(.8, .8);
		}
		while(oi->getAngle() < 45)
		{
			chassis->tankDrive(.8, -.8);
		}
		chassis->ResetEncoder();
		while(chassis->GetEncodeDistance() < 57.43 - 17)
		{
			chassis->tankDrive(.8, .8);
		}
	break;

	case 4:
		while(chassis->GetEncodeDistance() < 48.36)
		{
			chassis->tankDrive(.8, .8);
		}
		while(oi->getAngle() < 45)
		{
			chassis->tankDrive(.8, -.8);
		}
		chassis->ResetEncoder();
		while(chassis->GetEncodeDistance() < 24.85)
		{
			chassis->tankDrive(.8, .8);
		}
		while(oi->getAngle() < 45)
		{
			chassis->tankDrive(.8, -.8);
		}
		chassis->ResetEncoder();
		while(chassis->GetEncodeDistance() < 57.43 - 17)
		{
			chassis->tankDrive(.8, .8);
		}

	break;

	case 5:
		while(chassis->GetEncodeDistance() < (154.91 - 17))
		{
			chassis->tankDrive(.8, .8);
		}
		while(oi->getAngle() < 116.45)
		{
			chassis->tankDrive(.8, -.8);
		}
		chassis->ResetEncoder();
		while(chassis->GetEncodeDistance() < 9.34)
		{
			chassis->tankDrive(.8, .8);
		}

	break;

	default:

	break;
	}
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
