#include "Climber.h"

#define TIME 2.5
#define CLIMBER_SPEED 1

Climber::Climber()
{
	Requires(climberUp);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Climber::Initialize()
{
	time.Reset();
}

// Called repeatedly when this Command is scheduled to run
void Climber::Execute()
{
	if(oi->getButton9() && !oi->getButton10())
	{
		time.Start();
		climberUp->setCANTalon7(CLIMBER_SPEED);
	}
	else if(oi->getButton10())
	{
		time.Start();
		climberUp->setCANTalon7(-CLIMBER_SPEED);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Climber::IsFinished()
{
	if(time.Get() >= TIME)
	{
		climberUp->setCANTalon7(0);
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void Climber::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Climber::Interrupted()
{

}
