#include "ShooterSucker.h"

#define STOPSPEED 0
#define FULLSPEED 1

#define LOWGOALRETRACTSPEED -0.15
#define LOWGOALPUSHSPEED 0.5
#define HIGHGOALPUSHSPEED 0.9

#define STARTTIME 0.3
#define REVTIME 1.25
#define SHOOTFINISH 1.5

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
	//initializes speeds to 0
	ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
	ballSuckerShooter->setHighGoalShoot(STOPSPEED);
	buttonNum = 0;
}

// Called repeatedly when this Command is scheduled to run
void ShooterSucker::Execute()
{
	buttonNum = oi->getShoot();

	if(buttonNum == BUTTONLB)
	{
		highGoalBool = true;
	}
	else if(!highGoalBool)
	{
		time.Reset();
		ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
		ballSuckerShooter->setHighGoalShoot(STOPSPEED);
	}
	SmartDashboard::PutNumber("Button Number", buttonNum);

	if(buttonNum==BUTTONRB)//low goal
	{
		ballSuckerShooter->setPickupMotorSpeed(FULLSPEED);
	}
	else if(buttonNum == BUTTONRT)//ball suck
	{
			ballSuckerShooter->setPickupMotorSpeed(-FULLSPEED);
	}

	else if(highGoalBool) //high goal shooter
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
