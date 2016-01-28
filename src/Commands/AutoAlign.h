#ifndef AUTO_ALIGN_H
#define AUTO_ALIGN_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"

class AutoAlign: public CommandBase
{
public:
	AutoAlign();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
