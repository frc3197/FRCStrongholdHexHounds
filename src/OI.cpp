#include "OI.h"
#include "SPI.h"
#include <unistd.h>

#define DEADZONE .1
#define VOLTAGEMULT 104
#define INCHESOFF 2
#define SCALING .92

OI::OI():
	stick(0),//joystick 1
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
	climberStick(1),//joystick 2
	climberButton1(&climberStick, BUTTON1),//A
	climberButton4(&climberStick, BUTTON4),//Y
	climberButton2(&climberStick, BUTTON2),//B
	climberButton3(&climberStick, BUTTON3),//X
	ultra(2),//left sensor
	ultra2(1),//right sensor
	rangeFinder(0),//ball sensor
	pulseGenerator(0),//pulse generator
	gyro(0),//horizontal gyro
	elevationGyro(SPI::kOnboardCS0)//elevation gyro
{
	gyro.Calibrate();
	gyro.Reset();
	elevationGyro.Calibrate();
	elevationGyro.Reset();

	/*pulseGenerator.Set(Relay::kOff);//sets up pulse
	Wait(.001);
	pulseGenerator.Set(Relay::kForward);
	Wait(.001);
	pulseGenerator.Set(Relay::kOff);*/
	// Process operator interface input here.
}

float OI::getLeft()//gets left stick Y value
	{
	float yVal = stick.GetRawAxis(1);
	if((yVal < DEADZONE)&&(yVal > -DEADZONE))
	{
		yVal = 0;
	}
	return yVal*SCALING;//scales value down
	}

float OI::getRight()//gets right stick Y value
	{
	float yVal = stick.GetRawAxis(5);
	if((yVal < DEADZONE)&&(yVal > -DEADZONE))
	{
		yVal = 0;
	}
	return yVal*SCALING;//scales value down
}

int OI::getShoot()
{//returns which button is pressed
	newButton6 = button6.Get();//gets RB
	newButton5 = button5.Get();//gets LB
	currButton = "";

	if(newButton6)
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
	{//default value
		currButton = " ";
		return 0;
	}
}

void OI::rangeSensor()
{
	pulseGenerator.Pulse(1.6);//sets up pulse
	voltage = ultra.GetAverageVoltage();//gets range sensor 1
	range = voltage * VOLTAGEMULT + INCHESOFF;
	SmartDashboard::PutNumber("Range", range);

	voltage2 = ultra2.GetAverageVoltage();//gets range sensor 2
	range2 = voltage2 * VOLTAGEMULT + INCHESOFF;
	SmartDashboard::PutNumber("Range 2", range2);

	if(rangeFinder.Get() == 1)//gets whether there is a ball or not
	{
		SmartDashboard::PutString("ULTRA BALLS", "YES");
	}
	else
	{
		SmartDashboard::PutString("ULTRA BALLS", "NO");
	}
}

bool OI::getBooleanA()
{//changes bool value when button6 is pressed
	bool newButton = button1.Get();
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
{//returns X
	if(button3.Get())
	{
		autoAlignBot = true;
	}
	return autoAlignBot;
}

bool OI::getButtonY()
{//returns LB
	return button4.Get();
}

float OI::getRangeDif()
{//returns difference between the range sensors
	return (ultra.GetAverageVoltage() * VOLTAGEMULT + INCHESOFF) - (ultra2.GetAverageVoltage() * VOLTAGEMULT  + INCHESOFF);
}

float OI::getAngle()
{//returns SPI gyro angle
	SmartDashboard::PutNumber("Gyro Angle", gyro.GetAngle());
	return (gyro.GetAngle());
}

void OI::resetButtonX()
{//resets button X
	autoAlignBot = false;
}

void OI::gyroReset()
{//resets SPI gyro
	gyro.Reset();
}

void OI::elevationGyroReset()
{//resets elevation gyro
	elevationGyro.Reset();
}

float OI::getElevationAngle()
{//gets elevation gyro angle
	SmartDashboard::PutNumber("Elevation Angle", elevationGyro.GetAngle());
	return elevationGyro.GetAngle();
}

bool OI::getButton10()
{//returns right stick button
	return button10.Get();
}

bool OI::GetLT()
{//returns whether RT > .5
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
{//returns left stick pressed
	return button9.Get();
}

bool OI::getClimberButton1()
{//returns stick #2 button A
	return climberButton1.Get();
}

bool OI::getClimberButton4()
{//returns stick #2 button Y
	return climberButton4.Get();
}

unsigned int OI::getCameraNumber()
{//returns current camera #/ changes cam # if button A is pressed
	if(button1.Get() && !currentButtonA)
	{
		if(activeCam == 1)
		{
			activeCam = 2;
		}
		else
		{
			activeCam = 1;
		}
	}
	currentButtonA = button1.Get();
	return activeCam;
}

bool OI::getClimberButton2()
{//moves arm down
	return climberButton2.Get();
}

bool OI::getClimberButton3()
{//moves arm up
	return climberButton3.Get();
}

void OI::RumbleOn()
{
	climberStick.SetRumble(Joystick::kLeftRumble, 0.5);
}
void OI::RumbleOff()
{
	climberStick.SetRumble(Joystick::kLeftRumble, 0);
}
