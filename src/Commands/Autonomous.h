#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "../CommandBase.h"
#include "WPILib.h"



class Autonomous: public CommandGroup
{
public:
	Autonomous();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
