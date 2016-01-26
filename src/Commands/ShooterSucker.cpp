#include "ShooterSucker.h"

ShooterSucker::ShooterSucker()
{
	Requires(ballSuckerShooter);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ShooterSucker::Initialize()
{//initializes speeds to 0
	ballSuckerShooter->setPickupMotorSpeed(0);
	ballSuckerShooter->setLowGoalShoot(0);
	ballSuckerShooter->setHighGoalShoot(0);
	num = 0;
}

// Called repeatedly when this Command is scheduled to run
void ShooterSucker::Execute()
{
	num = oi->getShoot();
	if(num==4){
		highGoalBool = true;
	}
	else if(!highGoalBool)
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
	else if(highGoalBool){//high goal shooter
		time.Start();
		ballSuckerShooter->setLowGoalShoot(-.15);
		ballSuckerShooter->setHighGoalShoot(.9);//winds ball back while starting high goal motor
		if(time.Get() >= .3&&time.Get()<1)
		{
			ballSuckerShooter->setHighGoalShoot(.9);//stops winding ball back

		}
		if(time.Get() >= 1&&time.Get() < 1.25)
		{
			ballSuckerShooter->setLowGoalShoot(.5);
			ballSuckerShooter->setHighGoalShoot(.9);//shoots ball forward into high goal motor to shoot ball out
		}
		if(time.Get() >= 1.25)
		{
			ballSuckerShooter->setPickupMotorSpeed(0);
			ballSuckerShooter->setLowGoalShoot(0);
			ballSuckerShooter->setHighGoalShoot(0);
			highGoalBool = false;
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
