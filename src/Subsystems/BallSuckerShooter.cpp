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
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void BallSuckerShooter::setPickupMotorSpeed(float val){
	can5.Set(val);
}

void  BallSuckerShooter::setLowGoalShoot(float val){
	can6.Set(val);
}

void BallSuckerShooter::setHighGoalShoot(float val){
	can7.Set(val);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

