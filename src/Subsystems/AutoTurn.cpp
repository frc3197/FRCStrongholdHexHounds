#include "AutoTurn.h"
#include "../RobotMap.h"
#include "../Commands/AutoAlign.h"

AutoTurn::AutoTurn() :
		Subsystem("AutoTurn")
{

}

void AutoTurn::InitDefaultCommand()
{
	SetDefaultCommand(new AutoAlign());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void AutoTurn::reverse180()
{

}

void AutoTurn::align()
{

}
// Put methods for controlling this subsystem
// here. Call these from Commands.

