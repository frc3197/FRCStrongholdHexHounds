#include "autoDrive.h"
#include "AutoDriveDefense.h"
//#include "CommandGroup.h"
#define ERROR_RANGE 1.5

#define ON_RAMP_RANGE 1.5
#define ELEVATION_ANGLE_RANGE 1
#define DOWN_RAMP_RANGE -1.5

#define OLD_OUTOUT_PERCENT .95
#define ABS_INPUT_PERCENT .05

#define CAN_MOTOR_SLOW_SPEED -.4
#define CAN_MOTOR_FAST_SPEED -.45
#define STOP_SPEED 0.0

#define ELEVATIONCHANGERANGE 10

#define STOPSPEED 0
#define FULLSPEED 1

#define STARTTIME 0.3
#define REVTIME 1.25
#define SHOOTFINISH 1.5

#define LOWGOALRETRACTSPEED -0.15
#define LOWGOALPUSHSPEED 0.5
#define HIGHGOALPUSHSPEED 0.9

autoDrive::autoDrive()
{
 	Requires(chassis);
 	Requires(ballSuckerShooter);
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
	time.Start();
	SmartDashboard::PutNumber("Position", position);
	SmartDashboard::PutNumber("Time", time.Get());
	elevationAngle = oi->getElevationAngle();
switch(command)
{
case 1:
	switch(position){
	case 1:
		switch(number)
		{
			case 1://moves forward until on ramp
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
			 	 }

			 	 if((goingDownRamp) && ((elevationAngle <= ELEVATION_ANGLE_RANGE) && (elevationAngle >= -ELEVATION_ANGLE_RANGE)))
			 	 {
				 	 command = 2;
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
			command = 2;
		}

		oldElevationAngle = oi->getElevationAngle();

	break;

	default:

	break;
	}
break;

case 2:
	switch(position)
	{
	case 1://low bar position 1
		switch(state)
		{
			case 1:
				if(time.Get() <= 2.5)//chassis->GetEncodeDistance() < (149.34))
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);

				}
				else
				{
					chassis->tankDrive2(0, 0);
					state = 2;
				}
				SmartDashboard::PutNumber("case 1", 1);

			break;

			case 2:
				if(oi->getAngle() < 60)
				{
					chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, -CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->tankDrive2(0, 0);
					chassis->ResetEncoder();
					state = 3;
					time.Reset();
				}
				SmartDashboard::PutNumber("case 2", 2);
			break;

			case 3:
				if(time.Get() <= 2.5)//chassis->GetEncodeDistance() < 149.34 + 68.1 - 17)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					chassis->tankDrive2(0, 0);
					command = 3;
				}
			 SmartDashboard::PutNumber("case 3", 3);
			break;

			default:

			break;
		}
	break;

	case 2://position 2
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() < (137.59))
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() < 60)
				{
					chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, -CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() < 36.34 - 17)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					command = 3;
				}
			break;

			default:

			break;
		}
	break;

	case 3://position 3
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() <= 27.33)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() <= 45)
				{
					chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, -CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() <= 54)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					oi->gyroReset();
					state = 4;
				}
			break;

			case 4:
				if(oi->getAngle() >= -45)
				{
					chassis->tankDrive2(-CAN_MOTOR_FAST_SPEED, CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 5;
				}
			break;

			case 5:
				if(chassis->GetEncodeDistance() <= (57.3 - 17))
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					command = 3;
				}
			break;

			default:

			break;
		}
	break;

	case 4: //position 4
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() <= 48.36)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() >= -45)
				{
					chassis->tankDrive2(-CAN_MOTOR_FAST_SPEED, CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() <= 24.85)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED,CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					oi->gyroReset();
					state = 4;
				}
			break;

			case 4:
				if(oi->getAngle() <= 45)
				{
					chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, -CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 5;
				}
			break;

			case 5:
				if(chassis->GetEncodeDistance() <= 57.43 - 17)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					command = 3;
				}
			break;

			default:

			break;
		}
	break;

	case 5: //position 5
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() < (154.91 - 17))
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() > -180 + 116.45)
				{
					chassis->tankDrive2(-CAN_MOTOR_FAST_SPEED, CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() < 9.34)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					command = 3;
				}
			break;

			default:

			break;
		}
	break;

	default:

	break;
	}
break;

case 3:
	if(oi->getRangeDif() >= ERROR_RANGE)
		{
			chassis->turnClockwise();
		}

		else if(oi->getRangeDif() <= -ERROR_RANGE)
		{
			chassis->turnCounterClockwise();
		}

		if(oi->getRangeDif() < ERROR_RANGE && oi->getRangeDif() > -ERROR_RANGE)
		{
			command = 4;
		}
break;

case 4:
	if(shoot == 0)//low goal
	{
		ballSuckerShooter->setPickupMotorSpeed(FULLSPEED);
	}
	else if(shoot == 1) //high goal shooter
	{
		time.Start();

		ballSuckerShooter->setPickupMotorSpeed(-LOWGOALRETRACTSPEED);
		ballSuckerShooter->setHighGoalShoot(HIGHGOALPUSHSPEED);//winds ball back while starting high goal motor

		if((time.Get() >= STARTTIME) && (time.Get()<REVTIME))
		{
			ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
			ballSuckerShooter->setHighGoalShoot(HIGHGOALPUSHSPEED);//stops winding ball back
		}

		if((time.Get() >= REVTIME) && (time.Get() < SHOOTFINISH))
		{
			ballSuckerShooter->setPickupMotorSpeed(LOWGOALRETRACTSPEED);
			ballSuckerShooter->setHighGoalShoot(HIGHGOALPUSHSPEED);//shoots ball forward into high goal motor to shoot ball out
		}

		if(time.Get() >= SHOOTFINISH)
		{
			ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
			ballSuckerShooter->setHighGoalShoot(STOPSPEED);
			time.Reset();
		}
	}

	if(time.Get() >= SHOOTFINISH)
	{
		ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
		ballSuckerShooter->setHighGoalShoot(STOPSPEED);
		finish = true;
	}
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
