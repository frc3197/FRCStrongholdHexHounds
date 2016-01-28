#ifndef AUTO_TURN_H
#define AUTO_TURN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "OI.h"

class AutoTurn: public Subsystem
{
private:
	CANTalon can1;
	CANTalon can2;
	CANTalon can3;
	CANTalon can4;
	RobotDrive drive;
	Timer time;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	AutoTurn();
	void InitDefaultCommand();
	void reverse180();
	void turnClockwise();
	void turnCounterClockwise();
};

#endif
