#include "OI.h"
#include "SPI.h"

#define DEADZONE .1

OI::OI():
	stick(0),
	button1(&stick, BUTTON1),//A
	button2(&stick, BUTTON2),//B
	button3(&stick, BUTTON3),//X
	button4(&stick, BUTTON4),//Y
	button5(&stick, BUTTON5),//LB
	button6(&stick, BUTTON6),//RB
	button7(&stick, BUTTON7),//Back
	button8(&stick, BUTTON8),//Start
	button9(&stick, BUTTON9),//Left Stick
	button10(&stick, BUTTON10),//Right Stick
	ultra(1), ultra2(2),
	rangeFinder(6),
	dio(0),
	gyro(SPI::kOnboardCS0),
	elevationGyro(0)
{
	gyro.Calibrate();
	gyro.Reset();
	// Process operator interface input here.
}

float OI::getLeft()//gets left stick Y value
	{
	float yVal = stick.GetRawAxis(1);
	if((yVal < DEADZONE)&&(yVal > -DEADZONE)) return 0;
	return -yVal;
	}

float OI::getRight()//gets right stick Y value
	{
	float yVal = stick.GetRawAxis(5);
	if((yVal<.1)&&(yVal>-.1)){
		yVal = 0;
	}
	return -yVal;
}

int OI::getShoot()
{//returns which button is pressed
	bool newButton1 = button6.Get();
	bool newButton2 = button2.Get();
	bool newButton3 = button3.Get();
	bool newButton4 = button4.Get();
	bool newButton5 = button5.Get();
	currButton = "";

	if(newButton1)
	{
		currButton = "RB"; //low goal shooter
		return 6;
	}
	else if(stick.GetRawAxis(3) >= .5)
	{
		currButton = "RT"; //ball suck
		return 7;
	}
	else if(newButton5){
		currButton = "LB"; //high goal shooter
		return 5;
	}
	else
	{
		currButton = " ";
		return 0;
	}
	SmartDashboard::PutString("Button Pressed", currButton);
}

void OI::rangeSensor()
{
	dio.Pulse(1.6);//sets up pulse

	voltage = ultra.GetAverageVoltage();//gets range sensor 1
	SmartDashboard::PutNumber("Voltage", voltage);
	range = voltage*104 + 2;
	SmartDashboard::PutNumber("Range", range);

	voltage2 = ultra2.GetAverageVoltage();//gets range sensor 2
	SmartDashboard::PutNumber("Voltage 2", voltage2);
	range2 = voltage2*104 + 2;
	SmartDashboard::PutNumber("Range 2", range2);

	if(rangeFinder.Get() == 1)//gets whether there is a ball or not
	{
		SmartDashboard::PutString("Range Finder Range", "You've got balls");
	}
	else
	{
		SmartDashboard::PutString("Range Finder Range", "Sorry, no balls");
	}
}

bool OI::getBoolean()
{
	bool newButton = button6.Get();
	if(inverse&&newButton)
	{
		inverse = false;
	}
	else if(newButton)
	{
		inverse = true;
	}
	return inverse;
}

bool OI::getButtonX()
{
	if(button3.Get())
	{
		autoAlignBot = true;
	}
	return autoAlignBot;
}

bool OI::getButtonLB()
{
	/*if((button5.Get()) && (LB))
	{
		LB = false;
	}
	else if(button5.Get())
	{
		LB = true;
	}*/
	return button5.Get();
}

float OI::getRangeDif()
{
	return (ultra.GetAverageVoltage()*104 + 2) - (ultra2.GetAverageVoltage()*104 + 2);
}

float OI::getAngle()
{
	SmartDashboard::PutNumber("Gyro Angle", gyro.GetAngle());
	return (gyro.GetAngle());
}

void OI::resetButtonX()
{
	autoAlignBot = false;
}

void OI::gyroReset()
{
	gyro.Reset();
}

void OI::elevationGyroReset()
{
	elevationGyro.Calibrate();
	elevationGyro.Reset();
}

float OI::getElevationAngle()
{
	return elevationGyro.GetAngle();
}

bool OI::getButton10()
{
	return button10.Get();
}

bool OI::GetRT()
{
	if(stick.GetRawAxis(2) >= .5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool OI::getButton9()
{
	return button9.Get();
}
