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
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

