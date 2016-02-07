#include "Climber.h"

#define TIME 2.5
#define CLIMBER_SPEED .5

Climber::Climber()
{
	Requires(climberUp);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Climber::Initialize()
{
	bottomSwitchPressed = climberUp->getBottomSwitch();
	topSwitchPressed = climberUp->getTopSwitch();
	middleSwitchPressed = climberUp->getMiddleSwitch();
	time.Reset();
}

// Called repeatedly when this Command is scheduled to run
void Climber::Execute()
{
	bottomSwitchPressed = climberUp->getBottomSwitch();
	topSwitchPressed = climberUp->getTopSwitch();
	middleSwitchPressed = climberUp->getMiddleSwitch();

	if(oi->getButton9())
	{		if(middleSwitchPressed && !endMiddleSwitch)
		{
			time.Start();
			climberUp->setCANTalon7(0);
		}
		else if(time.Get() >= .75)
		{
			climberUp->setCANTalon7(CLIMBER_SPEED);
			endMiddleSwitch = true;
		}
		else if(topSwitchPressed)
		{
			climberUp->setCANTalon7(0);
			finish = true;
		}
		else
		{
			climberUp->setCANTalon7(CLIMBER_SPEED);
		}
	}
	else if(oi->getButton10())
	{
		if (middleSwitchPressed  && !endMiddleSwitch)
		{
			climberUp->setCANTalon7(0);
			time.Start();
		}
		else if (time.Get() >= .75)
		{
			climberUp->setCANTalon7(-CLIMBER_SPEED);
			endMiddleSwitch = true;
		}
		else if (bottomSwitchPressed)
		{
			climberUp->setCANTalon7(0);
			finish = true;
		}
		else
		{
			climberUp->setCANTalon7(-CLIMBER_SPEED);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Climber::IsFinished()
{
	return finish;
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
