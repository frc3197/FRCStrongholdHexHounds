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
	SendableChooser autoChooser;

private:
	//int num = 0;
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		autoChooser.InitTable(NetworkTable::GetTable("Position Chooser"));
		autoChooser.AddDefault("Position 1", (void*)"1");
		autoChooser.AddObject("Position 2", (void*)"2");
		autoChooser.AddObject("Position 3", (void*)"3");
		autoChooser.AddObject("Position 4", (void*)"4");
		autoChooser.AddObject("Position 5", (void*)"5");

		string p = (const char*)autoChooser.GetSelected();

		//SmartDashboard::PutString("Is Running", "Not yet");
		CommandBase::init();
		autonomousCommand = new autoDrive(p);
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		//SmartDashboard::PutString("Is Running", "Yes");
		if (autonomousCommand != NULL)
		{
			//SmartDashboard::PutString("Auto Initiated", "Yes");
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic()
	{
		//num++;
		//SmartDashboard::PutNumber("Executing Num", num);
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

