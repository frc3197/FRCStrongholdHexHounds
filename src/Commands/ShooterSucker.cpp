#include "ShooterSucker.h"
#include <string>
#include <Preferences.h>

#define STOPSPEED 0
#define FULLSPEED 1

#define LOWGOALRETRACTSPEED 0.45
#define LOWGOALPUSHSPEED 0.5
#define LOWHIGHGOALPUSHSPEED -1

#define BALLSUCKSPEED .75

/*#define STARTTIME 0.18
#define REVTIME 3
#define SHOOTFINISH 4*/

#define BUTTONA 1
#define BUTTONB 2
#define BUTTONX 3
#define BUTTONY 4
#define BUTTONLB 5
#define BUTTONRB 6
#define BUTTONRT 7

ShooterSucker::ShooterSucker()
{
	Requires(ballSuckerShooter);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ShooterSucker::Initialize()
{
	//prefs = Preferences::GetInstance();

	//prefs->PutDouble("HighGoalPushSpeed", 0.625);//sets default high goal speed
	//initializes speeds to 0
	ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
	ballSuckerShooter->setHighGoalShoot(STOPSPEED);
	buttonNum = 0;

	/*SmartDashboard::PutNumber("High Goal Push Speed", 0.9);//sets default speeds
	SmartDashboard::PutNumber("High Goal Suck down time", STARTTIME);
	SmartDashboard::PutNumber("High Goal Wind up time", REVTIME);
	SmartDashboard::PutNumber("High Goal end time", SHOOTFINISH);*/
}

// Called repeatedly when this Command is scheduled to run
void ShooterSucker::Execute()
{
	//HIGHGOALPUSHSPEED = (float) prefs->GetDouble("HighGoalPushSpeed", 0.9);//gets high goal speed from smart dashboard
	SmartDashboard::PutNumber("High Goal Speed (should = High Goal Push Speed)", HIGHGOALPUSHSPEED);
	/*HIGHGOALPUSHSPEED = SmartDashboard::GetNumber("High Goal Push Speed", 0.9);
	STARTTIME = SmartDashboard::GetNumber("High Goal Suck down time", .18);
	REVTIME = SmartDashboard::GetNumber("High Goal Wind up time", 3);
	SHOOTFINISH = SmartDashboard::GetNumber("High Goal end time", 4);

	SmartDashboard::PutNumber("High Goal Speed (should = High Goal Push Speed)", HIGHGOALPUSHSPEED);
	SmartDashboard::PutNumber("High Goal Suck time (should = High Goal Suck down time", STARTTIME);
	SmartDashboard::PutNumber("High goal wind time (should = High Goal Wind up time)", REVTIME);
	SmartDashboard::PutNumber("High Goal end (should = High Goal end time)", SHOOTFINISH);*/

	buttonNum = oi->getShoot();//gets button number for button that is pressed

	if(buttonNum == BUTTONLB)
	{//sets high goal bool to true if LB is pressed
		highGoalBool = true;
	}
	else if(!highGoalBool)
	{//if LB isn't pressed, time starts and motor speeds are set to 0
		time.Reset();
		ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
		ballSuckerShooter->setHighGoalShoot(STOPSPEED);
	}
	SmartDashboard::PutNumber("Button Number", buttonNum);//prints out button #

	if(buttonNum==BUTTONRB)//low goal
	{
		ballSuckerShooter->setPickupMotorSpeed(FULLSPEED);
	}
	else if(buttonNum == BUTTONRT)//ball suck
	{
		ballSuckerShooter->setPickupMotorSpeed(-BALLSUCKSPEED);
	}

	else if(highGoalBool) //high goal shooter
	{
		time.Start();

		if(time.Get() < STARTTIME)
		{
			ballSuckerShooter->setPickupMotorSpeed(LOWGOALRETRACTSPEED);//starts sucking down
		}
		else if((time.Get() >= STARTTIME) && (time.Get() < REVTIME))
		{
			ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);//stops sucking down
			ballSuckerShooter->setHighGoalShoot(HIGHGOALPUSHSPEED);//starts winding up high goal motor
		}
		else if((time.Get() >= REVTIME) && (time.Get() < SHOOTFINISH))
		{
			ballSuckerShooter->setPickupMotorSpeed(LOWHIGHGOALPUSHSPEED);//shoots ball forward into high goal motor to shoot ball out
			ballSuckerShooter->setHighGoalShoot(HIGHGOALPUSHSPEED);//continues running high goal motor
		}
		else
		{//stops motors
			ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
			ballSuckerShooter->setHighGoalShoot(STOPSPEED);
			highGoalBool = false;
			time.Reset();
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterSucker::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterSucker::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterSucker::Interrupted()
{

}
