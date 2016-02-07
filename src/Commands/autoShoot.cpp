#include "autoShoot.h"

#define STOPSPEED 0
#define FULLSPEED 1

#define STARTTIME 0.3
#define REVTIME 1.25
#define SHOOTFINISH 1.5

#define LOWGOALRETRACTSPEED -0.15
#define LOWGOALPUSHSPEED 0.5
#define HIGHGOALPUSHSPEED 0.9

autoShoot::autoShoot()
{
	Requires (ballSuckerShooter);// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void autoShoot::Initialize()
{
	time.Reset();
	time.Start();
	ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
	ballSuckerShooter->setHighGoalShoot(STOPSPEED);
}

// Called repeatedly when this Command is scheduled to run
void autoShoot::Execute()
{
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

}

// Make this return true when this Command no longer needs to run execute()
bool autoShoot::IsFinished()
{
	if(time.Get() >= SHOOTFINISH)
	{
		ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
		ballSuckerShooter->setHighGoalShoot(STOPSPEED);
		return true;

	}
	else
		return false;
}

// Called once after isFinished returns true
void autoShoot::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoShoot::Interrupted()
{

}
