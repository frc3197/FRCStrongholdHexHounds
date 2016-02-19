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
	Encoder encode2;
	USBCamera usbCamFront;
	USBCamera usbCamBack;

	//camera objects declaration
	//Image image;
//	IMAQdxSession session;
	const char* CAM_ONE = "cam1";
	const char* CAM_TWO = "cam2";

	int activeCam = 1;
	double pi = 3.14159265358979323846;
	double gearRatio = 13.0 / 24.0;
	double wheelDiameter = 11.75;
	int enconderPulses = 1440;
	double encoderRevolution; //in inches

public:
	Chassis();
	void InitDefaultCommand();
	void tankDrive(float left, float right);
	void tankDrive2(float left, float right);
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
	void changeCam();
	void startCam();
};

#endif
