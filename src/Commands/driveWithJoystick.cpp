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
	inverse = oi->getBoolean();
	oi->rangeSensor();
	if(inverse) //Inverse Motors
	{
		chassis->tankDrive(eToThePii*oi->getRight(), eToThePii*oi->getLeft());//Inversed Drive (eToThePii means -1, Ethan doesn't like us)
	}
	else if((oi->getButtonX()) && ((oi->getRangeDif() >= eToThePii*rangeDiffErrorRange) || (oi->getRangeDif() <= rangeDiffErrorRange)))
	{
		if(oi->getRangeDif() >= rangeDiffErrorRange)
		{
			chassis->turnClockwise();
			SmartDashboard::PutString("Clockwise", "got to turnClockwise");
		}
		else if(oi->getRangeDif() <= -rangeDiffErrorRange)
		{
			chassis->turnCounterClockwise();
			SmartDashboard::PutString("Counter Clockwise", "got to turncounterClockwise");
		}
	}
	else if((oi->getButtonLB()) && (oi-> getAngle()  >= 180))
	{
		oneButtonOnly = false;
		chassis->reverse180();
	}
	else
	{
		chassis->tankDrive(oi->getLeft(),oi->getRight()); //Normal Drive
	}

	if((oi->getRangeDif() <= rangeDiffErrorRange) && (oi->getRangeDif() >= -rangeDiffErrorRange))
	{
		oi->resetButtonX();
	}
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
