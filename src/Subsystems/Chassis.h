#ifndef CHASSIS_H
#define CHASSIS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "OI.h"

class Chassis: public Subsystem
{
private:
	Joystick stick;
	RobotDrive robotDrive;
	CANTalon can1;
	CANTalon can2;
	CANTalon can3;
	CANTalon can4;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Chassis();
	void InitDefaultCommand();
	void tankDrive();
	OI *oi;
};

#endif
