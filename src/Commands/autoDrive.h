#ifndef AUTO_DRIVE_H
#define AUTO_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"
#include "math.h"
#include <string>


class autoDrive: public CommandBase
{
private:
	float angle = 0.0;
	bool onRamp = false;
	bool finish = false;
	float elevationAngle = 0.0;
	float oldElevationAngle = 0.0;
	bool goingDownRamp = false;
	Timer time;
	int number = 1;
	int position = 0;
	string p = "";
	string p2 = "";
	int defenseNumber = 1;
	int state = 1;
	int shoot = 1;
	int terrainType = 1;//not rough terrain

	string s1 = "1";
	string s2 = "2";
	string s3 = "3";
	string s4 = "4";
	string s5 = "5";
	string st0 = "0";
	string st1 = "1";

	bool firstRun = true;

	//smartdashboard variables

	double POSITION1FIRSTDISTANCE = 0;
	double POSITION1FIRSTTURNANGLE = 0;
	double POSITION1SECONDDISTANCE = 0;


public:
	SendableChooser autoChooser;
	SendableChooser autoChooser2;
	autoDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif
