#ifndef AUTO_SQUARED_ALIGN_H
#define AUTO_SQUARED_ALIGN_H

#include "../CommandBase.h"
#include "WPILib.h"

#include "Subsystems/Chassis.h"

class autoSquaredAlign: public CommandBase
{
public:
	autoSquaredAlign();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
