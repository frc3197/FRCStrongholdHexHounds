#include "AutoDriveDefense.h"

AutoDriveDefense::AutoDriveDefense()
{
	Requires(autoDriveToDefense);
	Requires(chassis);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AutoDriveDefense::Initialize()
{
	oi->gyroReset();
	chassis->ResetEncoder();
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveDefense::Execute()
{
	chassis->SetCan1Speed(-.6);
	chassis->SetCan2Speed(-.6);
	chassis->SetCan3Speed(-.6);
	chassis->SetCan4Speed(-.6);
	//oi->gyroReset();
	/*switch(position)
	{
	case 1://low bar position 1
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() < (149.34))
				{
					chassis->tankDrive(.8, .8);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() < 120)
				{
					chassis->tankDrive(.8, -.8);
				}
				else
				{
				chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() < 149.34 + 68.1 - 17)
				{
					chassis->tankDrive(.8, .8);
				}
				else
				{
					finish = true;
				}
			break;

			default:

			break;
		}
	break;

	case 2://position 2
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() < (137.59))
				{
					chassis->tankDrive(.8, .8);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() < 120)
				{
					chassis->tankDrive(.8, -.8);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() < 36.34 - 17)
				{
					chassis->tankDrive(.8, .8);
				}
				else
				{
					finish = true;
				}
			break;

			default:

			break;
		}
	break;

	case 3://position 3
		switch(state)
		{
			case 1:
				if(chassis->GetEncoderDistance() <= 27.33)
				{
					chassis->SetCan1Speed(-.8);
					chassis->SetCan2Speed(-.8);
					chassis->SetCan3Speed(-.8);
					chassis->SetCan4Speed(-.8);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() <= 45)
				{
					chassis->SetCan1Speed(-.8);
					chassis->SetCan2Speed(.8);
					chassis->SetCan3Speed(.8);
					chassis->SetCan4Speed(-.8);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncoderDistance() <= 54)
				{
					chassis->SetCan1Speed(-.8);
					chassis->SetCan2Speed(-.8);
					chassis->SetCan3Speed(-.8);
					chassis->SetCan4Speed(-.8);
				}
				else
				{
					oi->gyroReset();
					state = 4;
				}
			break;

			case 4:
				if(oi->getAngle() >= -45)
				{
					chassis->SetCan1Speed(.8);
					chassis->SetCan2Speed(-.8);
					chassis->SetCan3Speed(-.8);
					chassis->SetCan4Speed(.8);
				}
				else
				{
					chassis->ResetEncoder();
					state = 5;
				}
			break;

			case 5:
				if(oi->GetEncoderDistance() <= 57.3 - 17)
				{
					chassis->SetCan1Speed(-.8);
					chassis->SetCan2Speed(-.8);
					chassis->SetCan3Speed(-.8);
					chassis->SetCan4Speed(-.8);
				}
				else
				{
					finish = true;
				}
			break;

			default:

			break;
		}
	break;

	case 4: //position 4
		switch(state)
		{
			case 1:
				if(chassis->GetEncoderDistance() <= 48.36)
				{
					chassis->SetCan1Speed(-.8);
					chassis->SetCan2Speed(-.8);
					chassis->SetCan3Speed(-.8);
					chassis->SetCan4Speed(-.8);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() >= -45)
				{
					chassis->SetCan1Speed(.8);
					chassis->SetCan2Speed(-.8);
					chassis->SetCan3Speed(-.8);
					chassis->SetCan4Speed(.8);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncoderDistance() <= 24.85)
				{
					chassis->SetCan1Speed(-.8);
					chassis->SetCan2Speed(-.8);
					chassis->SetCan3Speed(-.8);
					chassis->SetCan4Speed(-.8);
				}
				else
				{
					oi->gyroReset();
					state = 4;
				}
			break;

			case 4:
				if(oi->getAngle() <= 45)
				{
					chassis->SetCan1Speed(-.8);
					chassis->SetCan2Speed(.8);
					chassis->SetCan3Speed(.8);
					chassis->SetCan4Speed(-.8);
				}
				else
				{
					chassis->ResetEncoder();
					state = 5;
				}
			break;

			case 5:
				if(oi->GetEncoderDistance() <= 57.43 - 17)
				{
					chassis->SetCan1Speed(-.8);
					chassis->SetCan2Speed(-.8);
					chassis->SetCan3Speed(-.8);
					chassis->SetCan4Speed(-.8);
				}
				else
				{
					finish = true;
				}
			break;

			default:

			break;
		}
	break;

	case 5: //position 5
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() < (154.91 - 17))
				{
					chassis->tankDrive(.8, .8);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() < 116.45)
				{
					chassis->tankDrive(.8, -.8);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() < 9.34)
				{
					chassis->tankDrive(.8, .8);
				}
				else
				{
					finish = true;
				}
			break;

			default:

			break;
		}
	break;

	default:

	break;
	}*/
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveDefense::IsFinished()
{
	if(oi->getAngle() <= -90)
	{
		chassis->SetCan1Speed(0);
		chassis->SetCan2Speed(0);
		chassis->SetCan3Speed(0);
		chassis->SetCan4Speed(0);
		return true;
	}
	else
	{
		return false;
	}
	//return finish
}

// Called once after isFinished returns true
void AutoDriveDefense::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveDefense::Interrupted()
{

}
