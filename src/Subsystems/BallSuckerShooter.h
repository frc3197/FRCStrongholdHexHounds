#ifndef BALL_SHOOTER_SUCKER_H
#define BALL_SHOOTER_SUCKER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BallSuckerShooter: public Subsystem
{
private:
	CANTalon can1;
	CANTalon can2;
	CANTalon can3;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	BallSuckerShooter();
	void InitDefaultCommand();
	void setPickupMotorSpeed(float val);
	void setLowGoalShoot(float val);
	void setHighGoalShoot(float val);
};

#endif
