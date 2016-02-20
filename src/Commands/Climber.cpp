#include "Climber.h"

#define TIME 2.5
#define CLIMBER_SPEED 1
#define STOPTIME 1


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
	endMiddleSwitch = false;
	state = 1;
	up = false;
	down = false;
}

// Called repeatedly when this Command is scheduled to run
void Climber::Execute()
{//gets limit switches
	bottomSwitchPressed = climberUp->getBottomSwitch();
	topSwitchPressed = climberUp->getTopSwitch();
	middleSwitchPressed = climberUp->getMiddleSwitch();

if(oi->getClimberButton1())
{
	climberUp->setCANTalon7(CLIMBER_SPEED);
}
else if(oi->getClimberButton4())
{
	climberUp->setCANTalon7(-CLIMBER_SPEED);
}
else
{
	climberUp->setCANTalon7(0);
}

/*up = oi->getClimberButton1();//should climb up
down = oi->getClimberButton4();//should climb down
if(up)
{//moves up
	switch(state)
	{
		case 1://climbs up until middle switch is pressed
			climberUp->setCANTalon7(CLIMBER_SPEED);
			if(middleSwitchPressed)
			{
				state = 2;
			}
		break;

		case 2://waits
			time.Start();
			climberUp->setCANTalon7(0);
			if(time.Get() >= STOPTIME)
			{
				state = 3;
			}
		break;

		case 3://climbs up until top switch is pressed
			climberUp->setCANTalon7(CLIMBER_SPEED);
			if(topSwitchPressed)
			{
				finish = true;
				state = 4;
			}
		break;

		default:

		break;
	}
}
else if(down)
{//moves down/pulls up
	switch(state)
	{
		case 1://pulls bot up until middle switch is pressed
			climberUp->setCANTalon7(-CLIMBER_SPEED);
			if(middleSwitchPressed)
			{
				finish = true;
				state = 2;
			}
		break;

		default:

		break;
	}
}
else
{}*/

}

// Make this return true when this Command no longer needs to run execute()
bool Climber::IsFinished()
{
	if(finish)
	{
		climberUp->setCANTalon7(0);
	}
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
