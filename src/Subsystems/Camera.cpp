#include "Camera.h"
#include "../RobotMap.h"
#include "Commands/CameraControl.h"

Camera::Camera() :
		Subsystem("Camera")
{

}

void Camera::InitDefaultCommand()
{
	SetDefaultCommand(new CameraControl());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

