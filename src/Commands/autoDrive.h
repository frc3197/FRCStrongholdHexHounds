#ifndef AUTO_DRIVE_H
#define AUTO_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"


class autoDrive: public CommandBase
{
private:
	float angle = 0.0;
	bool onRamp = false;
	bool finish = false;
	float elevationAngle = 0.0;
	bool goingDownRamp = false;
	int number = 1;
	Timer time;

public:
	autoDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
