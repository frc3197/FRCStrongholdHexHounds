#include "OI.h"

OI::OI():
	stick(0),
	button1(&stick, BUTTON1),
	button2(&stick, BUTTON2),
	button3(&stick, BUTTON3),
	button4(&stick, BUTTON4),
	button5(&stick, BUTTON5),
	button6(&stick, BUTTON6),
	button7(&stick, BUTTON7),
	button8(&stick, BUTTON8),
	button9(&stick, BUTTON9),
	button10(&stick, BUTTON10),
	ultra(0), ultra2(1),
	rangeFinder(6),
	dio(0)
	//spi(0)
	//gyro(spi)
{
	//gyro.Calibrate();
	//gyro.Reset();
	// Process operator interface input here.
}

float OI::getLeft(){//gets left stick Y value
	float yVal = stick.GetRawAxis(1);
	if((yVal<.1)&&(yVal>-.1)){
		yVal = 0;
	}
	return -yVal;
}

float OI::getRight(){//gets right stick Y value
	float yVal = stick.GetRawAxis(5);
	if((yVal<.1)&&(yVal>-.1)){
		yVal = 0;
	}
	return -yVal;
}

int OI::getShoot()
{//returns which button is pressed
	bool newButton1 = button1.Get();
	bool newButton2 = button2.Get();
	bool newButton3 = button3.Get();
	bool newButton4 = button4.Get();
	bool newButton5 = button5.Get();
	currButton = "";
	if(newButton1)
	{
		currButton = "A"; //low goal
		return 1;
	}
	else if(newButton2)
	{
		currButton = "B"; //ball suck
		return 2;
	}
	else if(newButton3)
	{
		currButton = "X";
		return 3;
	}
	else if(newButton4){
		currButton = "Y"; //High Goal
		return 4;
	}
	else if(newButton5){
		currButton = "LB";
		return 5;
	}
	else
	{
		currButton = " ";
		return 0;
	}
	SmartDashboard::PutString("Button Pressed", currButton);
}

/*void OI::rangeSensor()
{
	voltage = ultra.GetAverageVoltage();//gets range sensor 1
	SmartDashboard::PutNumber("Voltage", voltage);
	range = voltage*100;
	SmartDashboard::PutNumber("Range", range);

	voltage2 = ultra2.GetAverageVoltage();//gets range sensor 2
	SmartDashboard::PutNumber("Voltage 2", voltage2);
	range2 = voltage2*100;
	SmartDashboard::PutNumber("Range 2", range2);

	if(rangeFinder.Get() == 1)//gets whether there is a ball or not
	{
		SmartDashboard::PutString("Range Finder Range", "You've got balls");
	}
	else
	{
		SmartDashboard::PutString("Range Finder Range", "Sorry, no balls");
	}
}*/

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
	if((button5.Get()) && (LB))
	{
		LB = false;
	}
	else if(button5.Get())
	{
		LB = false;
	}
	return LB;
}

float OI::getRangeDif()
{
	return (ultra.GetAverageVoltage()*104 + 2) - (ultra2.GetAverageVoltage()*104 + 2);
}

float OI::getAngle()
{
	//return (gyro.GetAngle());
	return 0;
}

void OI::resetButtonX()
{
	autoAlignBot = false;
}

void OI::gyroReset()
{
	//gyro.Calibrate();
	//gyro.Reset();
}


