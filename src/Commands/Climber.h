#ifndef CLIMBER_H
#define CLIMBER_H

#include "../CommandBase.h"
#include "WPILib.h"

class Climber: public CommandBase
{
private:
	Timer time;

public:
	Climber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
