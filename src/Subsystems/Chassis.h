#ifndef CHASSIS_H
#define CHASSIS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "OI.h"

class Chassis: public Subsystem
{
private:
	CANTalon can1;
	CANTalon can2;
	CANTalon can3;
	CANTalon can4;
	RobotDrive robotDrive;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Chassis();
	void InitDefaultCommand();
	void tankDrive(float left, float right);
	void reverse180();
	void turnClockwise();
	void turnCounterClockwise();
};

#endif
