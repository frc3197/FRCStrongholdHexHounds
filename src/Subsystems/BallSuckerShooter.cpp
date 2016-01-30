#include "BallSuckerShooter.h"
#include "../RobotMap.h"
#include "Commands/ShooterSucker.h"

BallSuckerShooter::BallSuckerShooter() :
		Subsystem("BallSuckerShooter"),
		can5(5), can6(6), can7(7)
{

}

void BallSuckerShooter::InitDefaultCommand()
{
	SetDefaultCommand(new ShooterSucker());

}

void BallSuckerShooter::setPickupMotorSpeed(float val)
{
	can5.Set(val); //sets pickup motor speed
}

void  BallSuckerShooter::setLowGoalShoot(float val)
{
	can6.Set(val);//sets low goal motor speed
}

void BallSuckerShooter::setHighGoalShoot(float val)
{
	can7.Set(val);//sets high goal motor speed
}


