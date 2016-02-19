#include "driveWithJoystick.h"

#define ERROR_RANGE 1.5

driveWithJoystick::driveWithJoystick()
{
	Requires(chassis);
}

void driveWithJoystick::Initialize()
{
	inverse = false;
	time.Reset();
	time.Start();
}

void driveWithJoystick::Execute()
{
	if(!YPressed)//Y is really Y
	{
		YPressed = oi->getButtonY();
		YLast = false;
	}

	if(YPressed && !YLast)
	{
		YLast = true;
		oi->gyroReset();
	}


	inverse = oi->getBooleanA();
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
	else if((YPressed) && (oi-> getAngle()  <= TURNAMOUNT))
	{//reverses 180 deg
		resetY = true;
		chassis->reverse180();

	}
	else if (inverse) //Inverse Motors
	{
		chassis->tankDrive(-oi->getRight(), -oi->getLeft());//Inversed Drive
	}
	else
	{
		chassis->tankDrive(oi->getLeft(), oi->getRight()); //Normal Drive
		changeCameras = true;
	}

	if(oi->getAngle() >= TURNAMOUNT && resetY)
	{
		resetY = oi->getButtonY();
		YLast = YPressed;
		YPressed = false;
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
