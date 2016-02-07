#ifndef CLIMBER_H
#define CLIMBER_H

#include "../CommandBase.h"
#include "WPILib.h"

class Climber: public CommandBase
{
private:
	bool bottomSwitchPressed;
	bool topSwitchPressed;
	bool middleSwitchPressed;
	Timer time;
	bool finish = false;
	bool endMiddleSwitch = false;

public:
	Climber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
