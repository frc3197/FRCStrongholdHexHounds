#ifndef AUTO_SHOOT_H
#define AUTO_SHOOT_H

#include "../CommandBase.h"
#include "WPILib.h"

class autoShoot: public CommandBase
{
private:
	int shoot = 1;
	Timer time;
public:
	autoShoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
