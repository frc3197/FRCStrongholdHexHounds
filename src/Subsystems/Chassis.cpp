#include <Subsystems/Chassis.h>
#include "../Commands/drivewithJoystick.h"
#include "../RobotMap.h"

#define MOTOR_SPEED .5
#define MOTOR_SPEED_FAST .8

#define FPS 10

Chassis::Chassis():
	Subsystem("Chassis"),
	can1(1), can2(2), can3(3), can4(4),
	robotDrive(can3,can2,can1,can4),
	encode(1, 2, false, Encoder::k4X)
	//usbCam1("USB Camera 1", true),
	//usbCam2("USB Camera 2", true)
{
	robotDrive.SetSafetyEnabled(false);
}

void Chassis::InitDefaultCommand()
{
	SetDefaultCommand(new driveWithJoystick());

}

void Chassis::tankDrive(float left, float right)
{//tele-op tank drive
	robotDrive.TankDrive(left, right, true);
}

void Chassis::tankDrive2(float left, float right)
{//auto tank drive
	robotDrive.TankDrive(-left, -right, false);
}

void Chassis::reverse180() //auto reverses 180 degrees
{
	robotDrive.TankDrive(MOTOR_SPEED_FAST, -MOTOR_SPEED_FAST, true);
	SmartDashboard::PutString("Counter Clockwise", "*Slow Clap* You turned around!");
}

void Chassis::turnClockwise() //auto-aligns if right sensor>left sensor
{
	SmartDashboard::PutString("Turn CLockwise", "turn clockwise executed");
	robotDrive.TankDrive(MOTOR_SPEED_FAST, -MOTOR_SPEED_FAST, false);
}

void Chassis::turnCounterClockwise() //auto-aligns if left sensor > right sensor
{
	SmartDashboard::PutString("Turn Counter CLockwise", "turn counter clockwise executed");
	robotDrive.TankDrive(-MOTOR_SPEED_FAST, MOTOR_SPEED_FAST, false);
}

void Chassis::SetCan1Speed(float speed)
{
	can1.Set(speed);
}

void Chassis::SetCan2Speed(float speed)
{
	can2.Set(-speed);
}

void Chassis::SetCan3Speed(float speed)
{
	can3.Set(-speed);
}

void Chassis::SetCan4Speed(float speed)
{
	can4.Set(speed);
}

float Chassis::GetEncodeDistance()
{//gets encoder distance
	float distance = encode.Get();
	return distance;
}

void Chassis::ResetEncoder()
{//resets encoder
	encode.Reset();
}

void Chassis::Turn()
{//turns robot
	robotDrive.TankDrive(MOTOR_SPEED_FAST, -MOTOR_SPEED_FAST, true);
}
/*
void Chassis::Forward()
{
	robotDrive.TankDrive(MOTOR_SPEED, MOTOR_SPEED, true);
}
void Chassis::Backward()
{
	robotDrive.TankDrive(-MOTOR_SPEED, -MOTOR_SPEED, true);
}
*/

/*void Chassis::changeCam()
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
}*/
