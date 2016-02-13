#ifndef AUTO_DRIVE_H
#define AUTO_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"
#include "math.h"
#include <string>


class autoDrive: public CommandBase
{
private:
	float angle = 0.0;
	bool onRamp = false;
	bool finish = false;
	float elevationAngle = 0.0;
	float oldElevationAngle = 0.0;
	bool goingDownRamp = false;
	Timer time;
	int number = 1;
	int position = 0;
	string p = "";
	int command = 1;
	int state = 1;
	int shoot = 1;
	int terrainType = 1;//not rough terrain


public:
	autoDrive(string pos);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
