#ifndef CHASSIS_H
#define CHASSIS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "OI.h"
#include <cstdlib>

class Chassis: public Subsystem
{
private:
	CANTalon can1;
	CANTalon can2;
	CANTalon can3;
	CANTalon can4;
	RobotDrive robotDrive;

public:
	Chassis();
	void InitDefaultCommand();
	void tankDrive(float left, float right);
	void reverse180();
	void turnClockwise();
	void turnCounterClockwise();
};

#endif
