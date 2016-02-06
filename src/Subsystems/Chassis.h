#ifndef CHASSIS_H
#define CHASSIS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "OI.h"
#include <cstdlib>
#include <ADXL362.h>

class Chassis: public Subsystem
{
private:
	CANTalon can1;
	CANTalon can2;
	CANTalon can3;
	CANTalon can4;
	RobotDrive robotDrive;
	Encoder encode;
	ADXL362 accel;

public:
	Chassis();
	void InitDefaultCommand();
	void tankDrive(float left, float right);
	void reverse180();
	void turnClockwise();
	void turnCounterClockwise();
	void SetCan1Speed(float speed);
	void SetCan2Speed(float speed);
	void SetCan3Speed(float speed);
	void SetCan4Speed(float speed);
	float GetEncodeDistance();
	void ResetEncoder();
	void Turn();
	//void Forward();
	//void Backward();
	float getAccelerometerZ();
};

#endif
