#ifndef AUTO_DRIVE_H
#define AUTO_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"

class autoDrive: public CommandBase
{
public:
	autoDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
