#include "autoDrive.h"
#include "AutoDriveDefense.h"
//#include "CommandGroup.h"
#define ERROR_RANGE 0.75

#define ON_RAMP_RANGE 1.5
#define ELEVATION_ANGLE_RANGE 1
#define DOWN_RAMP_RANGE -1.5

#define OLD_OUTOUT_PERCENT .95
#define ABS_INPUT_PERCENT .05

#define CAN_MOTOR_SLOW_SPEED -.4
#define CAN_MOTOR_FAST_SPEED -.45
#define STOP_SPEED 0.0

#define ELEVATIONCHANGERANGE 10

autoDrive::autoDrive()
{
 	Requires(chassis);
}

// Called just before this Command runs the first time
void autoDrive::Initialize()
{
	onRamp = false;
	finish = false;
	oi->elevationGyroReset();
	time.Reset();
	elevationAngle = 0.0;
	oldElevationAngle = 0.0;
}

// Called repeatedly when this Command is scheduled to run
void autoDrive::Execute()
{
	SmartDashboard::PutNumber("Time", time.Get());
	//absInput = fabs(chassis->getAccelerometerZ() - 1);
	//output = (OLD_OUTOUT_PERCENT*oldOutput) + (ABS_INPUT_PERCENT*absInput);
	//SmartDashboard::PutNumber("Output", output);
	elevationAngle = oi->getElevationAngle();
switch(position){
case 1:
	switch(number)
	{
		case 1://movs forward until on ramp
			SmartDashboard::PutNumber("Case", number);
			chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
			if(elevationAngle >= ON_RAMP_RANGE)//output > .36)
			{
				number = 2;
			}
		break;

		case 2://moves forward until off ramp
			 SmartDashboard::PutNumber("Case", number);
			 angle = oi->getAngle();
			 if(angle > ERROR_RANGE)
			 {
				 chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, CAN_MOTOR_SLOW_SPEED);
			 }
			 else if(angle < ERROR_RANGE)
			 {
				 chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_FAST_SPEED);
			 }
			 else
			 {
				 chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
			 }

			 if(elevationAngle <= DOWN_RAMP_RANGE)
			 {
				 goingDownRamp = true;
				 SmartDashboard::PutString("Case", "finished");
			 }

			 if((goingDownRamp) && ((elevationAngle <= ELEVATION_ANGLE_RANGE) && (elevationAngle >= -ELEVATION_ANGLE_RANGE)))
			 {
				 SmartDashboard::PutString("Finishing", "true");
				 finish = true;
				 number = 3;
			 }
		break;

		default:

		break;
	}
break;

case 2://rough terrain none-detection
	time.Start();
	if(time.Get() >= .1)
	{
		time.Reset();
		elevationAngle = fabs(oi->getElevationAngle() - oldElevationAngle);
	}

	if(elevationAngle > ELEVATIONCHANGERANGE)
	{
		chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, CAN_MOTOR_FAST_SPEED);
	}
	else if(oi->getElevationAngle() < ELEVATION_ANGLE_RANGE)
	{
		chassis->tankDrive2(0, 0);
		finish = true;
	}

	oldElevationAngle = oi->getElevationAngle();

break;

default:

break;
}
	SmartDashboard::PutBoolean("Finish", finish);
	SmartDashboard::PutBoolean("On Ramp", onRamp);
	SmartDashboard::PutNumber("Elevation Angle", elevationAngle);
}

// Make this return true when this Command no longer needs to run execute()
bool autoDrive::IsFinished()
{
	if(finish)
	{//stops moving if finished
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
