#ifndef SHOOTER_SUCKER_H
#define SHOOTER_SUCKER_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"

class ShooterSucker: public CommandBase
{
private:
	Timer time;
	int buttonNum = 0;
	bool highGoalBool = false;
	SendableChooser autoChooser;
	float HIGHGOALPUSHSPEED = 0.625;

public:
	ShooterSucker();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
