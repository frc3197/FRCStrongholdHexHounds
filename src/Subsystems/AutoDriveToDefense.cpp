#include "AutoDriveToDefense.h"
#include "../RobotMap.h"
#include "../Commands/autoDrive.h"

AutoDriveToDefense::AutoDriveToDefense() :
		Subsystem("AutoDriveToDefense"),
		encode(1, 2, false, Encoder::k4X)
{

}

void AutoDriveToDefense::InitDefaultCommand()
{
	SetDefaultCommand(new autoDrive());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

