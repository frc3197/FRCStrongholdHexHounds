#ifndef BALL_SHOOTER_SUCKER_H
#define BALL_SHOOTER_SUCKER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BallSuckerShooter: public Subsystem
{
private:

	CANTalon can5; //Ball Pickup
	CANTalon can6; //Low Goal Shooter
	CANTalon can7; //High Goal Shooter

public:
	BallSuckerShooter();
	void InitDefaultCommand();
	void setPickupMotorSpeed(float val);
	void setLowGoalShoot(float val);
	void setHighGoalShoot(float val);
};

#endif
