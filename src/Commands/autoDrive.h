#ifndef AUTO_DRIVE_H
#define AUTO_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"


class autoDrive: public CommandBase
{
private:
	Timer time;
	float angle = 0.0;
	bool onRamp = false;
	float absInput = 0.0;
	float oldOutput = 0.0;
	float output = 0.0;
	bool finish = false;
	float elevationAngle = 0.0;

public:
	autoDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
