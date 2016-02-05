#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"

class Autonomous: public CommandGroup
{
private:
	int num = 0;

public:
	Autonomous();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
