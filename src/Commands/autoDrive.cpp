#include "autoDrive.h"

#define ERROR_RANGE 1.5

#define ON_RAMP_RANGE 1.5
#define ELEVATION_ANGLE_RANGE 1
#define DOWN_RAMP_RANGE -1.5

#define OLD_OUTOUT_PERCENT .95
#define ABS_INPUT_PERCENT .05

#define CAN_MOTOR_SLOW_SPEED -.35
#define CAN_MOTOR_FAST_SPEED -.4
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

#define HALFBOTLENGTH 17

//#define POSITION1FIRSTDISTANCE 149.34
//#define POSITION1FIRSTTURNANGLE 60
//#define POSITION1SECONDDISTANCE (149.34 + 68.1 - HALFBOTLENGTH)

#define POSITION2FIRSTDISTANCE 137.59
#define POSITION2FIRSTTURNANGLE 60
#define POSITION2SECONDDISTANCE (36.34 - HALFBOTLENGTH)

#define POSITION3FIRSTDISTANCE 27.33
#define POSITION3FIRSTTURNANGLE 45
#define POSITION3SECONDDISTANCE 54
#define POSITION3SECONDTURNANGLE -45
#define POSITION3THIRDDISTANCE (57.3 - HALFBOTLENGTH)

#define POSITION4FIRSTDISTANCE 48.36
#define POSITION4FIRSTTURNANGLE -45
#define POSITION4SECONDDISTANCE 24.85
#define POSITION4SECONDTURNANGLE 45
#define POSITION4THIRDDISTANCE (57.43 - HALFBOTLENGTH)

#define POSITION5FIRSTDISTANCE (154.91 - HALFBOTLENGTH)
#define POSITION5FIRSTTURNANGLE (-180 + 116.45)
#define POSITION5SECONDDISTANCE 9.34

autoDrive::autoDrive()
{
 	Requires(chassis);
 	Requires(ballSuckerShooter);

	autoChooser.InitTable(NetworkTable::GetTable("Position Chooser"));
	autoChooser.AddDefault("Position 1", &s1);
	autoChooser.AddObject("Position 2", &s2);
	autoChooser.AddObject("Position 3", &s3);
	autoChooser.AddObject("Position 4", &s4);
	autoChooser.AddObject("Position 5", &s5);
	SmartDashboard::PutData("Position Chooser", &autoChooser);

	autoChooser2.AddDefault("ON ROUGH TERRAIN", &st0);
	autoChooser2.AddObject("NOT ON ROUGH TERRAIN", &st1);
	SmartDashboard::PutData("Defense Chooser", &autoChooser2);
}

// Called just before this defenseNumber runs the first time
void autoDrive::Initialize()
{
	oi->elevationGyroReset();

	POSITION1FIRSTDISTANCE = SmartDashboard::GetNumber("POSITION 1 FIRST DISTANCE", 149.34);
	POSITION1FIRSTTURNANGLE = SmartDashboard::GetNumber("POSITION 1 FIRST TURNANGLE", 60);
	POSITION1SECONDDISTANCE = SmartDashboard::GetNumber("POSITION 1 SECOND DISTANCE", (36.34 - HALFBOTLENGTH));
	SmartDashboard::PutNumber("POSITION 1 FIRST DISTANCE:", POSITION1FIRSTDISTANCE);
	SmartDashboard::PutNumber("POSITION 1 FIRST ANGLE:", POSITION1FIRSTTURNANGLE);
	SmartDashboard::PutNumber("POSITION 1 SECOND DISTANCE:", POSITION1SECONDDISTANCE);

	string* p = (string *)(autoChooser).GetSelected();
	string* p2 = (string *)(autoChooser2).GetSelected();

	onRamp = false;
	finish = false;
	time.Reset();
	elevationAngle = 0.0;
	oldElevationAngle = 0.0;
	position = 1;
	defenseNumber = 1;
	goingDownRamp = false;
	number = 1;

	if(((p->compare("1")) == 0))
	{
		position = 1;
	}
	else if(((p->compare("2")) == 0))
	{
		position = 2;
	}
	else if(((p->compare("3")) == 0))
	{
		position = 3;
	}
	else if(((p->compare("4")) == 0))
	{
		position = 4;
	}
	else if(((p->compare("5")) == 5))
	{
		position = 5;
	}

	if(((p2->compare("0")) == 0))
	{
		terrainType = 2;
	}
	else if(((p2->compare("1")) == 0))
	{
		terrainType = 1;
	}

	SmartDashboard::PutNumber("Position Number", position);
	SmartDashboard::PutNumber("Terrain Type Number", terrainType);
}

// Called repeatedly when this defenseNumber is scheduled to run
void autoDrive::Execute()
{
	SmartDashboard::PutString("Is Running Autonomous", "yes");
	if(firstRun)
	{
		firstRun = false;
	}

	time.Start();
	elevationAngle = oi->getElevationAngle();
switch(defenseNumber)
{
case 1:
	switch(terrainType)
	{
	case 1:
		switch(number)
		{
			case 1://moves forward until on ramp
				chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				SmartDashboard::PutString("Is Running Switch Statement", "yes");
				if(elevationAngle >= ON_RAMP_RANGE)//output > .36)
				{
					number = 2;
				}
			break;

			case 2://moves forward until off ramp
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
			 		 position = 1;
				 	 defenseNumber = 2;
				 	 finish = true;
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
			position = 1;
			defenseNumber = 2;
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
				if(chassis->GetEncodeDistance() < POSITION1FIRSTDISTANCE)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);

				}
				else
				{
					chassis->tankDrive2(0, 0);
					state = 2;
				}

			break;

			case 2:
				if(oi->getAngle() < POSITION1FIRSTTURNANGLE)
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
			break;

			case 3:
				if(chassis->GetEncodeDistance() < POSITION1SECONDDISTANCE)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					chassis->tankDrive2(0, 0);
					defenseNumber = 3;
				}
			break;

			default:

			break;
		}
	break;

	case 2://position 2
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() < (POSITION2FIRSTDISTANCE))
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() < POSITION2FIRSTTURNANGLE)
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
				if(chassis->GetEncodeDistance() < POSITION2SECONDDISTANCE)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					defenseNumber = 3;
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
				if(chassis->GetEncodeDistance() <= POSITION3FIRSTDISTANCE)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() <= POSITION3FIRSTTURNANGLE)
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
				if(chassis->GetEncodeDistance() <= POSITION3SECONDDISTANCE)
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
				if(oi->getAngle() >= POSITION3SECONDTURNANGLE)
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
				if(chassis->GetEncodeDistance() <= POSITION3THIRDDISTANCE)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					defenseNumber = 3;
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
				if(chassis->GetEncodeDistance() <= POSITION4FIRSTDISTANCE)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() >= POSITION4FIRSTTURNANGLE)
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
				if(chassis->GetEncodeDistance() <= POSITION4SECONDDISTANCE)
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
				if(oi->getAngle() <= POSITION4SECONDTURNANGLE)
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
				if(chassis->GetEncodeDistance() <= POSITION4THIRDDISTANCE)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					defenseNumber = 3;
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
				if(chassis->GetEncodeDistance() < POSITION5FIRSTDISTANCE)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() > POSITION5FIRSTTURNANGLE)
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
				if(chassis->GetEncodeDistance() < POSITION5SECONDDISTANCE)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					defenseNumber = 3;
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
			defenseNumber = 4;
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
}

// Make this return true when this defenseNumber no longer needs to run execute()
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
