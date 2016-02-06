#include "autoDrive.h"
#include "AutoDriveDefense.h"
//#include "CommandGroup.h"
#define TIME 2

#define ERROR_RANGE 0
#define ON_RAMP_RANGE 0.26

#define OLD_OUTOUT_PERCENT .95
#define ABS_INPUT_PERCENT .05

#define CAN_MOTOR_SLOW_SPEED -.4
#define CAN_MOTOR_FAST_SPEED -.45

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
	onRamp = false;
	finish = false;
	oi->elevationGyroReset();
}

// Called repeatedly when this Command is scheduled to run
void autoDrive::Execute()
{
	absInput = fabs(chassis->getAccelerometerZ() - 1);
	output = (OLD_OUTOUT_PERCENT*oldOutput) + (ABS_INPUT_PERCENT*absInput);
	SmartDashboard::PutNumber("Output", output);
	elevationAngle = oi->getElevationAngle();

	 if((onRamp) && (elevationAngle >=.05))//output >= ON_RAMP_RANGE))
	 {
		 SmartDashboard::PutString("Running", "on ramp code");
	 	 angle = oi->getAngle();
	 	 if(angle > ERROR_RANGE)
	 	 {
	 		SmartDashboard::PutBoolean("Adjusting for angle", true);
	 		//chassis->SetCan1Speed(CAN_MOTOR_SLOW_SPEED);
			//chassis->SetCan2Speed(CAN_MOTOR_SLOW_SPEED);
			//chassis->SetCan3Speed(CAN_MOTOR_FAST_SPEED);
			//chassis->SetCan4Speed(CAN_MOTOR_FAST_SPEED);
	 		chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, CAN_MOTOR_SLOW_SPEED);
	 	 }
	 	 else if(angle < ERROR_RANGE)
	 	 {
	 		SmartDashboard::PutBoolean("Adjsuting for angle", true);
	 		//chassis->SetCan1Speed(CAN_MOTOR_FAST_SPEED);
			//chassis->SetCan2Speed(CAN_MOTOR_FAST_SPEED);
			//chassis->SetCan3Speed(CAN_MOTOR_SLOW_SPEED);
			//chassis->SetCan4Speed(CAN_MOTOR_SLOW_SPEED);
	 		chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_FAST_SPEED);
	 	 }
	 	 else
	 	 {
	 		SmartDashboard::PutBoolean("Adjsuting for angle", false);
	 		//chassis->SetCan1Speed(CAN_MOTOR_SLOW_SPEED);
	 		//chassis->SetCan2Speed(CAN_MOTOR_SLOW_SPEED);
			//chassis->SetCan3Speed(CAN_MOTOR_SLOW_SPEED);
			//chassis->SetCan4Speed(CAN_MOTOR_SLOW_SPEED);
	 		chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
	 	 }
	 }
	 else if(onRamp)
	 {
	 	 finish = true;
	 }
	 else
	 {
	 	SmartDashboard::PutString("Running", "normal code, not on ramp");
	 	//chassis->SetCan1Speed(CAN_MOTOR_SLOW_SPEED);
	 	//chassis->SetCan2Speed(CAN_MOTOR_SLOW_SPEED);
	 	//chassis->SetCan3Speed(CAN_MOTOR_SLOW_SPEED);
	 	//chassis->SetCan4Speed(CAN_MOTOR_SLOW_SPEED);
	 	chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
	 	if(elevationAngle >= .1)//output > .36)
		{
			onRamp = true;
		}
	}

	/*if(time.Get() < TIME  chassis->GetEncodeDistance() <= 122 + 17)
	{
		chassis->SetCan1Speed(-.25);
		chassis->SetCan2Speed(-.25);
		chassis->SetCan3Speed(-.25);
		chassis->SetCan4Speed(-.25);
	}*/
	oldOutput = output;
	SmartDashboard::PutBoolean("Finish", finish);
	SmartDashboard::PutBoolean("On Ramp", onRamp);
}

// Make this return true when this Command no longer needs to run execute()
bool autoDrive::IsFinished()
{
	/*if(time.Get() >= TIMEchassis->GetEncodeDistance() <= 122 + 16)
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
	}*/
	if(finish)
	{
		chassis->tankDrive2(0, 0);
	}
	return finish;
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
