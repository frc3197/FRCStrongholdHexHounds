#ifndef DRIVE_WITH_JOYSTICK_H
#define DRIVE_WITH_JOYSTICK_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"


class driveWithJoystick: public CommandBase
{
private:

	bool inverse;
	float TURNAMOUNT = 170;
	bool LBPressed = false;
	bool resetLB = true;//useless variable to set LB to false
	bool LBLast = false;

public:
	driveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
