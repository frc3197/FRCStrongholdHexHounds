#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/autoDrive.h"
#include "CommandBase.h"
#include "OI.h"
#include <string>

//comment
//comment2

//TestComment


class Robot: public IterativeRobot
{
public:

private:
	//int num = 0;
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		autonomousCommand = new autoDrive();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
		{
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

