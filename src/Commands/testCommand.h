#ifndef TEST_COMMAND_H
#define TEST_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

class testCommand: public CommandBase
{
public:
	testCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
