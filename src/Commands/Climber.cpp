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
{//gets limit switches
	bottomSwitchPressed = climberUp->getBottomSwitch();
	topSwitchPressed = climberUp->getTopSwitch();
	middleSwitchPressed = climberUp->getMiddleSwitch();
	time.Reset();
}

// Called repeatedly when this Command is scheduled to run
void Climber::Execute()
{//gets limit switches
	bottomSwitchPressed = climberUp->getBottomSwitch();
	topSwitchPressed = climberUp->getTopSwitch();
	middleSwitchPressed = climberUp->getMiddleSwitch();

	if(oi->getClimberButton4())
	{//only runs if left stick is held
		if(middleSwitchPressed && !endMiddleSwitch)
		{//stops running motor for .75 sec when middle switch is hit
			time.Start();
			climberUp->setCANTalon7(0);
		}
		else if(time.Get() >= .75)
		{//continues to run motor and sets endMiddleSwitch to true to stop previous code
			climberUp->setCANTalon7(CLIMBER_SPEED);
			endMiddleSwitch = true;
		}
		else if(topSwitchPressed)
		{//stops code when top switch is pressed
			climberUp->setCANTalon7(0);
			finish = true;
		}
		else
		{//runs normally
			climberUp->setCANTalon7(CLIMBER_SPEED);
		}
	}
	else if(oi->getClimberButton1())
	{//only runs if right stick is hit
		if (middleSwitchPressed  && !endMiddleSwitch)
		{//stops reversing for .75 sec when middle switch is hit
			climberUp->setCANTalon7(0);
			time.Start();
		}
		else if (time.Get() >= .75)
		{//continues reversing and stops previous code
			climberUp->setCANTalon7(-CLIMBER_SPEED);
			endMiddleSwitch = true;
		}
		else if (bottomSwitchPressed)
		{//stops when bottom switch is hit
			climberUp->setCANTalon7(0);
			finish = true;
		}
		else
		{//reverses normally
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
