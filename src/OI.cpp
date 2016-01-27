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
	ultra(0), ultra2(1), dio(0)
{
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
		currButton = "X"; //High Goal
		return 3;
	}
	else if(newButton4){
		currButton = "Y";
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

void OI::rangeSensor()
{
	voltage = ultra.GetVoltage();
	SmartDashboard::PutNumber("Voltage", voltage);
	range = voltage*100;
	SmartDashboard::PutNumber("Range", range);

	voltage2 = ultra2.GetVoltage();
	SmartDashboard::PutNumber("Voltage 2", voltage2);
	range2 = voltage2*100;
	SmartDashboard::PutNumber("Range 2", range2);
}

/*void OI::rangeSensor()
{
	dio.Pulse(1.6);
	voltage = ultra.GetVoltage();
	SmartDashboard::PutNumber("Voltage", voltage);
	range = voltage*100;
	SmartDashboard::PutNumber("Range", range);

	voltage2 = ultra2.GetVoltage();
	SmartDashboard::PutNumber("Voltage 2", voltage2);
	range2 = voltage2*100;
	SmartDashboard::PutNumber("Range 2", range2);
}*/

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
