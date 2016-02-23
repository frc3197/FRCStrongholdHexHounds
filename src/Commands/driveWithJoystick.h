#ifndef DRIVE_WITH_JOYSTICK_H
#define DRIVE_WITH_JOYSTICK_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"


class driveWithJoystick: public CommandBase
{
private:

	bool inverse = false;
	float TURNAMOUNT = 180;
	bool YPressed = false;
	bool resetY = true;//useless variable to set LB to false
	bool YLast = false;
	float absInput = 0.0;
	float oldOutput = 0.0;
	float output = 0.0;
	float elevationAngle = 0.0;
	Timer time;
	bool changeCameras = true;
	float encodeDistance = 0.0;

public:
	driveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
