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
	float voltage;
	float range;
	float voltage2;
	float range2;
	DigitalOutput dio;
	ADXRS450_Gyro gyro;
	AnalogGyro elevationGyro;

	bool inverse = false;
	bool LB = false;
	bool autoAlignBot = false;

	bool newButton1;
	bool newButton2;
	bool newButton3;
	bool newButton4;
	bool newButton5;



public:
	OI();
	float getLeft();
	float getRight();
	int getShoot();
	void rangeSensor();
	bool getBoolean();
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
};

#endif
