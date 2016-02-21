#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <iostream>
#include <string>
#include  <SPI.h>

using namespace std;

class OI
{
private:
	static const int JOYSTICK = 0;
	static const int BUTTON1 = 1;
	static const int BUTTON2 = 2;
	static const int BUTTON3 = 3;
	static const int BUTTON4 = 4;
	static const int BUTTON5 = 5;
	static const int BUTTON6 = 6;
	static const int BUTTON7 = 7;
	static const int BUTTON8 = 8;
	static const int BUTTON9 = 9;
	static const int BUTTON10 = 10;

	Joystick stick;

	JoystickButton button1; //A
	JoystickButton button2; //B
	JoystickButton button3; //X
	JoystickButton button4; //Y
	JoystickButton button5; //LB
	JoystickButton button6; //RB
	JoystickButton button7; //Back
	JoystickButton button8; //Start
	JoystickButton button9; //Left Stick Click
	JoystickButton button10; //Right Stick Click

	Joystick climberStick;
	JoystickButton climberButton1; //a
	JoystickButton climberButton4; //y


	string currButton;
	AnalogInput ultra;
	AnalogInput ultra2;
	DigitalInput rangeFinder;
	float voltage = 0.0;
	float range = 0.0;
	float voltage2 = 0.0;
	float range2 = 0.0;
	DigitalOutput pulseGenerator;
	AnalogGyro gyro;
	ADXRS450_Gyro elevationGyro;


	bool inverse = false;
	bool LB = false;
	bool autoAlignBot = false;

	bool newButton5 = false;
	bool newButton6 = false;
	unsigned int activeCam = 1;
	bool currentButtonA = false;

public:
	OI();
	float getLeft();
	float getRight();
	int getShoot();
	void rangeSensor();
	bool getBooleanA();
	bool getButtonX();
	bool getButtonY();
	float getRangeDif();
	float getAngle();
	void gyroReset();
	void resetButtonX();
	bool getButton10();
	void elevationGyroReset();
	float getElevationAngle();
	bool GetLT();
	bool getButton9();
	bool getClimberButton1();
	bool getClimberButton4();
	unsigned int getCameraNumber();
};

#endif
