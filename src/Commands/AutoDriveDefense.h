#ifndef AUTODRIVEDEFENSE_H
#define AUTODRIVEDEFENSE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDriveDefense: public CommandBase
{
private:
	int position = 0;
	int state = 0;
	bool finish = false;

public:
	AutoDriveDefense();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
