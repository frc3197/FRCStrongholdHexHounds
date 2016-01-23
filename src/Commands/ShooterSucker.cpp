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
}

// Called repeatedly when this Command is scheduled to run
void ShooterSucker::Execute()
{
	lastNum = num;
	num = oi->getShoot();
	if(lastNum != num)
	{
		time.Reset();
	}
	if(num==1)
	{//low goal shooter
		SmartDashboard::PutNumber("Time", time.Get());
		ballSuckerShooter->setPickupMotorSpeed(-1);
		ballSuckerShooter->setLowGoalShoot(1);
		if(time.Get()>.01)
		{
			ballSuckerShooter->setPickupMotorSpeed(0);
			ballSuckerShooter->setLowGoalShoot(0);
		}
	}
	else if(num==2)
	{//ball sucker
		while(num==2)
		{
			SmartDashboard::PutNumber("Time", time.Get());
			ballSuckerShooter->setPickupMotorSpeed(1);
			ballSuckerShooter->setLowGoalShoot(-1);
		}
	}
	else if(num==3)
	{//high goal shooter
		SmartDashboard::PutNumber("Time", time.Get());
		ballSuckerShooter->setLowGoalShoot(.15);
		ballSuckerShooter->setPickupMotorSpeed(-.15);
		if(time.Get()>.01)
		{
			ballSuckerShooter->setLowGoalShoot(-.15);
			ballSuckerShooter->setPickupMotorSpeed(.15);
			ballSuckerShooter->setHighGoalShoot(.75);
			if(time.Get()>.025)
			{
				ballSuckerShooter->setLowGoalShoot(0);
				ballSuckerShooter->setPickupMotorSpeed(0);
				ballSuckerShooter->setHighGoalShoot(0);
			}
		}
	}


}

// Make this return true when this Command no longer needs to run execute()
bool ShooterSucker::IsFinished()
{

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
