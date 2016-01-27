#ifndef AUTO_TURN_H
#define AUTO_TURN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AutoTurn: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	AutoTurn();
	void InitDefaultCommand();
	void reverse180();
	void align();
};

#endif
