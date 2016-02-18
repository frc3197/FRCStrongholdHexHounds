#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/ExampleSubsystem.h"

#include "Subsystems/Chassis.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/BallSuckerShooter.h"
#include "Subsystems/ClimberUp.h"

class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();

	static ExampleSubsystem *examplesubsystem;

	static OI *oi;
	static Chassis *chassis;
	static BallSuckerShooter *ballSuckerShooter;
	static ClimberUp *climberUp;

};

#endif
