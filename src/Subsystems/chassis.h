#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ExampleSubsystem: public Subsystem
{
private:
	Joystick leftStick;
	Joystick rightStick;
	RobotDrive robotDrive;
	CANTalon can1;
	CANTalon can2;
	CANTalon can3;
	CANTalon can4;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ExampleSubsystem();
	void InitDefaultCommand();
	void tankDrive();
};

#endif
