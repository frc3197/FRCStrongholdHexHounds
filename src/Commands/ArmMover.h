#ifndef ARM_MOVER_H
#define ARM_MOVER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmMover: public CommandBase
{
private:
	bool limitSwitchUp = false;
	bool limitSwitchDown = false;
	bool finish = false;

public:
	ArmMover();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
