#include "autoDrive.h"
#include "AutoDriveDefense.h"
//#include "CommandGroup.h"
#define TIME 5
#define ERROR_RANGE 0
#define ON_RAMP_RANGE .5


autoDrive::autoDrive()
{
 	Requires(chassis);
}

// Called just before this Command runs the first time
void autoDrive::Initialize()
{
	time.Reset();
	time.Start();
	oi->gyroReset();
}

// Called repeatedly when this Command is scheduled to run
void autoDrive::Execute()
{
	absInput = fabs(chassis->getAccelerometerZ());
	output = (0.9*oldOutput) + (0.1*absInput);
	oldOutput = output;
	SmartDashboard::PutNumber("Output", output);
	/*
	 	chassis->SetCan1Speed(-.8);
		chassis->SetCan2Speed(-.8);
		chassis->SetCan3Speed(-.8);
		chassis->SetCan4Speed(-.8);

		if(output > ON_RAMP_RANGE || output < -ON_RAMP_RANGE)
		{
			onRamp = true;
		}
	 */



	//if dy/dx of angle > 0, it is turning right
	//if dy/dx of angle < 0, it is turning left
	/*
	 angle = oi->getAngle();
	 if(angle > ERROR_RANGE)
	 {
	 	chassis->SetCan1Speed(-.8);
		chassis->SetCan2Speed(-.8);
		chassis->SetCan3Speed(-.85);
		chassis->SetCan4Speed(-.85);
	 }
	 else if(angle < ERROR_RANGE)
	 {
	 	chassis->SetCan1Speed(-.85);
		chassis->SetCan2Speed(-.85);
		chassis->SetCan3Speed(-.8);
		chassis->SetCan4Speed(-.8);
	 }
	 else
	 {
	 	chassis->SetCan1Speed(-.8);
	 	chassis->SetCan2Speed(-.8);
		chassis->SetCan3Speed(-.8);
		chassis->SetCan4Speed(-.8);
	 }
	 */

	while(time.Get() < TIME/*chassis->GetEncodeDistance() <= 122 + 17*/)
	{
		chassis->SetCan1Speed(-.25);
		chassis->SetCan2Speed(.25);
		chassis->SetCan3Speed(.25);
		chassis->SetCan4Speed(-.25);
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

	/*
	if(onRamp && (chassis->getAccelerometerZ() <= .5 && chassis->getAccelerometerZ() >= .5))
	{
		return true;
	}
	else
	{
		return false;
	}


	 */
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
