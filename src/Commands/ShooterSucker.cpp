#include "ShooterSucker.h"
#include <string>

#define STOPSPEED 0
#define FULLSPEED 1

#define LOWGOALRETRACTSPEED 0.5
#define LOWGOALPUSHSPEED 0.5
#define LOWHIGHGOALPUSHSPEED -1

#define STARTTIME 0.2
#define REVTIME 3
#define SHOOTFINISH 3.75

#define HIGH

#define BUTTONA 1
#define BUTTONB 2
#define BUTTONX 3
#define BUTTONY 4
#define BUTTONLB 5
#define BUTTONRB 6
#define BUTTONRT 7

ShooterSucker::ShooterSucker()
{
	Requires(ballSuckerShooter);

	/*string p1 = ".80";
	string p2 = ".75";
	string p3 = ".70";
	string p4 = ".65";
	string p5 = ".85";
	string p6 = ".90";

	//sets up power table
	autoChooser.InitTable(NetworkTable::GetTable("High Goal Power"));
	autoChooser.AddDefault("Power: .80", &p1);
	autoChooser.AddObject("Power: .75", &p2);
	autoChooser.AddObject("Power: .70", &p3);
	autoChooser.AddObject("Power: .65", &p4);
	autoChooser.AddObject("Power: .85", &p5);
	autoChooser.AddObject("Power: .90", &p6);
	SmartDashboard::PutData("Power Chooser", &autoChooser);//sets up power % chooser*/
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ShooterSucker::Initialize()
{
	//initializes speeds to 0
	ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
	ballSuckerShooter->setHighGoalShoot(STOPSPEED);
	buttonNum = 0;
}

// Called repeatedly when this Command is scheduled to run
void ShooterSucker::Execute()
{
	/*string* p = (string *)(autoChooser).GetSelected();//gets power %
	if((p->compare(".80")) == 0)
	{
		HIGHGOALPUSHSPEED = 0.8;
	}
	else if((p->compare(".75")) == 0)
	{
		HIGHGOALPUSHSPEED = 0.75;
	}
	else if((p->compare(".60")) == 0)
	{
		HIGHGOALPUSHSPEED = 0.60;
	}
	else if((p->compare(".65")) == 0)
	{
		HIGHGOALPUSHSPEED = 0.65;
	}
	else if((p->compare(".85")) == 0)
	{
		HIGHGOALPUSHSPEED = 0.85;
	}
	else if((p->compare(".90")) == 0)
	{
		HIGHGOALPUSHSPEED = 0.9;
	}
	//SmartDashboard::PutString("Power String", *p);
	SmartDashboard::PutNumber("High Goal Motor Speed", HIGHGOALPUSHSPEED);*/

	buttonNum = oi->getShoot();//gets button number for button that is pressed

	if(buttonNum == BUTTONLB)
	{//sets high goal bool to true if LB is pressed
		highGoalBool = true;
	}
	else if(!highGoalBool)
	{//if LB isn't pressed, time starts and motor speeds are set to 0
		time.Reset();
		ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
		ballSuckerShooter->setHighGoalShoot(STOPSPEED);
	}
	SmartDashboard::PutNumber("Button Number", buttonNum);//prints out button #

	if(buttonNum==BUTTONRB)//low goal
	{
		ballSuckerShooter->setPickupMotorSpeed(FULLSPEED);
	}
	else if(buttonNum == BUTTONRT)//ball suck
	{
		ballSuckerShooter->setPickupMotorSpeed(-FULLSPEED);
	}

	else if(highGoalBool) //high goal shooter
	{
		time.Start();

		if(time.Get() <STARTTIME)
		{
			ballSuckerShooter->setPickupMotorSpeed(LOWGOALRETRACTSPEED);//starts sucking down
		}
		else if((time.Get() >= STARTTIME) && (time.Get()<REVTIME))
		{
			ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);//stops sucking down
			ballSuckerShooter->setHighGoalShoot(HIGHGOALPUSHSPEED);//starts winding up high goal motor
		}
		else if((time.Get() >= REVTIME) && (time.Get() < SHOOTFINISH))
		{
			ballSuckerShooter->setPickupMotorSpeed(LOWHIGHGOALPUSHSPEED);//shoots ball forward into high goal motor to shoot ball out
			ballSuckerShooter->setHighGoalShoot(HIGHGOALPUSHSPEED);//continues running high goal motor
		}
		else
		{//stops motors
			ballSuckerShooter->setPickupMotorSpeed(STOPSPEED);
			ballSuckerShooter->setHighGoalShoot(STOPSPEED);
			highGoalBool = false;
			time.Reset();
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterSucker::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterSucker::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterSucker::Interrupted()
{

}
