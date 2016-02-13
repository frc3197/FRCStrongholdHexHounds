#include "driveWithJoystick.h"

#define ERROR_RANGE 1.5

driveWithJoystick::driveWithJoystick()
{
	Requires(chassis);
}

void driveWithJoystick::Initialize()
{
	inverse = false;
	oi->elevationGyroReset();
}

void driveWithJoystick::Execute()
{
	SmartDashboard::PutNumber("Encoder Distance", chassis->GetEncodeDistance());
	elevationAngle = fabs(oi->getElevationAngle());
	SmartDashboard::PutNumber("Elevation Angle", elevationAngle);

	if(!LBPressed)
	{
		LBPressed = oi->getButtonY();
		LBLast = false;
	}

	if(LBPressed && !LBLast)
	{
		LBLast = true;
		oi->gyroReset();
	}


	inverse = oi->getBoolean();
	oi->rangeSensor();

	if(((oi->GetLT()) && (!oi->getButton10())) && ((oi->getRangeDif() >= ERROR_RANGE) || (oi->getRangeDif() <= -ERROR_RANGE)))
	{//auto aligns
		if(oi->getRangeDif() >= ERROR_RANGE)
		{
			chassis->turnClockwise();
		}

		else if(oi->getRangeDif() <= -ERROR_RANGE)
		{
			chassis->turnCounterClockwise();
		}
	}
	else if((LBPressed) && (oi-> getAngle()  <= TURNAMOUNT))
	{//reverses 180 deg
		resetLB = true;
		chassis->reverse180();
		SmartDashboard::PutNumber("Working", 1);

	}
	else if (inverse) //Inverse Motors
	{
		chassis->tankDrive(-oi->getRight(), -oi->getLeft());//Inversed Drive
	}
	else
	{
		chassis->tankDrive(oi->getLeft(), oi->getRight()); //Normal Drive
	}


	/*if(((oi->getRangeDif() <= ERROR_RANGE) && (oi->getRangeDif() >= -ERROR_RANGE)) && (!oi->getButton10()))
	{
		oi->resetButtonX();
	}*/

	if(oi->getAngle() >= TURNAMOUNT && resetLB)
	{
		resetLB = oi->getButtonY();
		LBLast = LBPressed;
		LBPressed = false;
	}
}


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
