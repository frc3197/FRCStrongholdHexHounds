#ifndef AUTO_ALIGN_H
#define AUTO_ALIGN_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"

class AutoAlign: public CommandBase
{
private:
	Timer time;
	bool oneButtonOnly = false;
	float rangeDiffErrorRange = 1.5;
	int eToThePii = -1;

public:
	AutoAlign();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
