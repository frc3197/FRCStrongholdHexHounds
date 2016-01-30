#ifndef DRIVE_WITH_JOYSTICK_H
#define DRIVE_WITH_JOYSTICK_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"

class driveWithJoystick: public CommandBase
{
private:
	bool inverse;
	static const int eToThePii = -1;
	bool oneButtonOnly = false;
	float rangeDiffErrorRange = 1.5;

public:
	driveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
