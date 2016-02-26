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
	float HIGHGOALPUSHSPEED = 0.80;//change high goal speed here
	float STARTTIME = .27;
	float REVTIME = 3.5;
	float SHOOTFINISH = 4.6;
	//Preferences *prefs;

public:
	ShooterSucker();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
