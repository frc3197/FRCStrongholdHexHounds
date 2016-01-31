#ifndef AUTO_DRIVE_TO_DEFENSE_H
#define AUTO_DRIVE_TO_DEFENSE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <Encoder.h>
#include "OI.h"


class AutoDriveToDefense: public Subsystem
{
private:
	Encoder encode;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	AutoDriveToDefense();
	void InitDefaultCommand();
};

#endif
