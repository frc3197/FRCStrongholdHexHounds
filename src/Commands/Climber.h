#ifndef CLIMBER_H
#define CLIMBER_H

#include "../CommandBase.h"
#include "WPILib.h"

class Climber: public CommandBase
{
private:
	bool bottomSwitchPressed= false;
	bool middleSwitchPressed= false;
	Timer time;
	bool finish = false;
	bool endMiddleSwitch = false;
	int state = 0;
	bool up = false;
	bool down = false;

public:
	Climber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
