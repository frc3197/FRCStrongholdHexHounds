#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;

OI* CommandBase::oi = NULL;
Chassis* CommandBase::chassis = NULL;
BallSuckerShooter* CommandBase::ballSuckerShooter = NULL;
ClimberUp* CommandBase::climberUp = NULL;
Camera* CommandBase::camera = NULL;

CommandBase::CommandBase(char const *name) : Command(name)
{
}

CommandBase::CommandBase() : Command()
{

}

void CommandBase::init()
{

	chassis = new Chassis();
	oi = new OI();
	ballSuckerShooter = new BallSuckerShooter();
	camera = new Camera();
	//climberUp = new ClimberUp();



}
