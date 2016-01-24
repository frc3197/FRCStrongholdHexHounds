#include "ShooterSucker.h"

ShooterSucker::ShooterSucker()
{
	Requires(ballSuckerShooter);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ShooterSucker::Initialize()
{
	ballSuckerShooter->setPickupMotorSpeed(0);
	ballSuckerShooter->setLowGoalShoot(0);
	ballSuckerShooter->setHighGoalShoot(0);
	num = 0;
	tempTime = 0;
	actTime = 0;
}

// Called repeatedly when this Command is scheduled to run
void ShooterSucker::Execute()
{
	num = oi->getShoot();
	if(num==4){
		b = true;
	}
	else if(!b)
	{
		time.Reset();
		ballSuckerShooter->setPickupMotorSpeed(0);
		ballSuckerShooter->setLowGoalShoot(0);
		ballSuckerShooter->setHighGoalShoot(0);
	}
	SmartDashboard::PutNumber("Button Number", num);

	if(num==1)
	{//low goal
		ballSuckerShooter->setPickupMotorSpeed(1);
		ballSuckerShooter->setLowGoalShoot(-1);
	}
	else if(num==2)
	{//ball suck
			SmartDashboard::PutNumber("Time", time.Get());
			ballSuckerShooter->setPickupMotorSpeed(-1);
			ballSuckerShooter->setLowGoalShoot(1);
	}
	/*else if(num==3)
	{//high goal shooter
		SmartDashboard::PutNumber("Time", time.Get());
		ballSuckerShooter->setLowGoalShoot(-.15);
	}*/
	else if(b){
		tempTime = time.Get();
		time.Start();
		actTime += tempTime+time.Get();
		ballSuckerShooter->setLowGoalShoot(-.15);
		ballSuckerShooter->setHighGoalShoot(.1);
		if(time.Get() >= 1&&time.Get()<3.6)
		{
			ballSuckerShooter->setHighGoalShoot(.1);
			ballSuckerShooter->setHighGoalShoot(.8);

		}
		if(time.Get() >= 3.6&&time.Get() < 5)
		{
			ballSuckerShooter->setLowGoalShoot(.5);
			ballSuckerShooter->setHighGoalShoot(.8);
		}
		if(time.Get() >= 5)
		{
			ballSuckerShooter->setPickupMotorSpeed(0);
			ballSuckerShooter->setLowGoalShoot(0);
			ballSuckerShooter->setHighGoalShoot(0);
			b = false;
			time.Reset();
		}
	}
	/*else if(num==5){
		ballSuckerShooter->setHighGoalShoot(1);
	}*/
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
