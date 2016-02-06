#ifndef AUTODRIVEDEFENSE_H
#define AUTODRIVEDEFENSE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDriveDefense: public CommandBase
{
private:
	int position = 1;
	int state = 1;
	bool finish = false;
	Timer time;

public:
	AutoDriveDefense();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
