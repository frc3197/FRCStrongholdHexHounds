#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Autonomous.h"
#include "CommandBase.h"


//comment
//comment2

//TestComment


class Robot: public IterativeRobot
{
private:
	int num = 0;
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		SmartDashboard::PutString("Is Running", "Not yet");
		CommandBase::init();
		autonomousCommand = new Autonomous();
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		SmartDashboard::PutString("Is Running", "Yes");
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		num++;
		SmartDashboard::PutNumber("Executing Num", num);
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

