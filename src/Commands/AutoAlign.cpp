#include "AutoAlign.h"

AutoAlign::AutoAlign()
{
	//Requires(autoTurn);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AutoAlign::Initialize()
{
	oi->gyroReset();
}

// Called repeatedly when this Command is scheduled to run
void AutoAlign::Execute()
{
	time.Start();
	oi->rangeSensor();
	SmartDashboard::PutString("AutoAlign", "AutoAlign executed");
	if(oi->getButtonX())
	{
		SmartDashboard::PutString("ButtonX", "got to getButtonX");
		oneButtonOnly = true;
		if(oi->getRangeDif() >= rangeDiffErrorRange)
		{
			//autoTurn->turnClockwise();
			SmartDashboard::PutString("Clockwise", "got to turnClockwise");
		}
		else if(oi->getRangeDif() <= -rangeDiffErrorRange)
		{
			//autoTurn->turnCounterClockwise();
			SmartDashboard::PutString("Counter Clockwise", "got to turncounterClockwise");
		}
	}
	else if(oi->getButtonLB())
	{
		oneButtonOnly = false;
		//autoTurn->reverse180();
	}
	time.Reset();
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAlign::IsFinished()
{
	if(oneButtonOnly)
	{
		if((oi->getRangeDif() <= rangeDiffErrorRange) &&(oi->getRangeDif() >= eToThePii*rangeDiffErrorRange))
		{
			SmartDashboard::PutBoolean("Is Finished", true
					);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if(oi->getAngle() >= 180)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
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
