#include <Subsystems/Chassis.h>
#include "../Commands/drivewithJoystick.h"
#include "../RobotMap.h"

#define MOTOR_SPEED .5
#define MOTOR_SPEED_FAST .8

#define FPS 10

Chassis::Chassis():
	Subsystem("Chassis"),
	can1(1), can2(2), can3(3), can4(4),
	robotDrive(can1,can2,can3,can4),
	encode(1, 2, false, Encoder::k1X),
	encode2(3, 4, false, Encoder::k1X),
	usbCam1("USB Camera 1", true),
	usbCam2("USB Camera 2", true)
{
	robotDrive.SetSafetyEnabled(false);

	encoderRevolution = gearRatio * wheelDiameter * pi;
	encoderRevolution /= enconderPulses;
	//encode.SetDistancePerPulse(encoderRevolution);
	//encode2.SetDistancePerPulse(encoderRevolution);
	encode.SetDistancePerPulse(SmartDashboard::GetNumber("Distance_per_pulse", encoderRevolution));
	encode2.SetDistancePerPulse(SmartDashboard::GetNumber("Distance_per_pulse", encoderRevolution));
}

void Chassis::InitDefaultCommand()
{
	SetDefaultCommand(new driveWithJoystick());

}

void Chassis::tankDrive(float left, float right)
{//tele-op tank drive
	robotDrive.TankDrive(-left, -right, true);
}

void Chassis::tankDrive2(float left, float right)
{//auto tank drive
	robotDrive.TankDrive(-left, -right, false);
}

void Chassis::reverse180() //auto reverses 180 degrees
{
	robotDrive.TankDrive(MOTOR_SPEED_FAST, -MOTOR_SPEED_FAST, true);
}

void Chassis::turnClockwise() //auto-aligns if right sensor>left sensor
{
	robotDrive.TankDrive(MOTOR_SPEED_FAST, -MOTOR_SPEED_FAST, false);
}

void Chassis::turnCounterClockwise() //auto-aligns if left sensor > right sensor
{
	robotDrive.TankDrive(-MOTOR_SPEED_FAST, MOTOR_SPEED_FAST, false);
}

void Chassis::SetCan1Speed(float speed)
{
	can1.Set(speed);
}

void Chassis::SetCan2Speed(float speed)
{
	can2.Set(speed);
}

void Chassis::SetCan3Speed(float speed)
{
	can3.Set(-speed);
}

void Chassis::SetCan4Speed(float speed)
{
	can4.Set(-speed);
}

float Chassis::GetEncodeDistance()
{//gets encoder distance
	float distance = encode.GetDistance();
	float distance2 = encode2.GetDistance();
	SmartDashboard::PutNumber("Encoder 1 Value", distance);
	SmartDashboard::PutNumber("Encoder 2 Value", distance2);
	SmartDashboard::PutNumber("Average Encoder Value", (distance + distance)/2);
	return (distance+distance2)/2;
}

void Chassis::ResetEncoder()
{//resets encoder
	encode.Reset();
	encode2.Reset();
	encode.SetDistancePerPulse(encoderRevolution);
	encode2.SetDistancePerPulse(encoderRevolution);
}

void Chassis::Turn()
{//turns robot
	robotDrive.TankDrive(MOTOR_SPEED_FAST, -MOTOR_SPEED_FAST, true);
}

void Chassis::changeCam()
{
	if(activeCam == 1)
	{
		usbCam1.CloseCamera();
		usbCam1.StopCapture();
		usbCam2.StartCapture();
		usbCam2.OpenCamera();
		usbCam2.SetFPS(FPS);
	}
	else
	{
		usbCam2.CloseCamera();
		usbCam2.StopCapture();
		usbCam1.StartCapture();
		usbCam1.OpenCamera();
		usbCam1.SetFPS(FPS);
	}
}
