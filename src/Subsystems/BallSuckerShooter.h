#ifndef BALL_SHOOTER_SUCKER_H
#define BALL_SHOOTER_SUCKER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BallSuckerShooter: public Subsystem
{
private:

	CANTalon can5; //Ball Pickup
	CANTalon can6; //high Goal Shooter

public:
	BallSuckerShooter();
	void InitDefaultCommand();
	void setPickupMotorSpeed(float val);
	void setHighGoalShoot(float val);
};

#endif
