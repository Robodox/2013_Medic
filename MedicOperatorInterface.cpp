#include "MedicOperatorInterface.h"

MedicOperatorInterface::MedicOperatorInterface()
{
	joyDrive = new Joystick(1);//TODO:real value
	joyManip = new Joystick(2);//TODO:real value
	DriverStation *dsSimple = DriverStation::GetInstance();
	ds = &dsSimple->GetEnhancedIO();
	dsLCD = DriverStationLCD::GetInstance();	
	dashboard->init();
}


MedicOperatorInterface::~MedicOperatorInterface()
{
	delete dsLCD;
	delete joyDrive;
	delete joyManip;
	
	dsLCD = NULL;
	joyDrive = NULL;
	joyManip = NULL;	
}

/*
 * Joystick getDriveJoystick
 * Parameters: N/A
 * Summary: Gets the Drive Joystick 
 */
Joystick *MedicOperatorInterface::getDriveJoystick()
{
    return joyDrive;
}

/*
 * Joystick getManipJoystick
 * Parameters: N/A
 * Summary: Gets the Manipulator Joystick 
 */
Joystick *MedicOperatorInterface::getManipJoystick()
{
	return joyManip;
}

/*
 * Joystick getDriveJoystickButton
 * Parameters: UINT8 button - could be any button on the joysticks
 * Summary: Returns the raw drive button.
 */
UINT8 MedicOperatorInterface::getDriveJoystickButton(UINT8 button)
{
	return joyDrive->GetRawButton(button);		
}

/*
 * Joystick getManipJoystickButton
 * Parameters: UINT8 button - could be any button on the joysticks
 * Summary: Returns the raw manipulator button.
 */
UINT8 MedicOperatorInterface::getManipJoystickButton(UINT8 button)
{
	return joyManip->GetRawButton(button);
}

/*
 * bool getPIDToggle
 * Parameters: UINT8 toggle
 * Summary: is the PID toggled?
 */
bool MedicOperatorInterface::readPIDToggle(UINT8 toggle)
{
	if(ds->GetDigital(toggle) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MedicOperatorInterface::readClimbSafetyEnable(UINT8 toggle)
{
	if(ds->GetDigital(toggle) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

int MedicOperatorInterface::readShooterTargeting(UINT8 toggle1, UINT8 toggle2)
{
	if(ds->GetDigital(toggle1) == 1 && ds->GetDigital(toggle2) == 0)
	{
		return highGoal;
	}
	else if(ds->GetDigital(toggle1) == 0 && ds->GetDigital(toggle2) == 0)
	{
		return middleGoal;
	}
	else if(ds->GetDigital(toggle1) == 0 && ds->GetDigital(toggle2) == 1)
	{
		return manualTargeting;
	}
	else
	{
		return -1;
	}
}


double MedicOperatorInterface::readTargetDistance()
{
	return dashboard->GetNumber("TargetDistance");
}

double MedicOperatorInterface::readTargetCenterX()
{
	return dashboard->GetNumber("TargetCenterX");
}

double MedicOperatorInterface::readTargetCenterY()
{
	return dashboard->GetNumber("TargetCenterY");
}

bool MedicOperatorInterface::readAutoAimToggle()
{
	if(ds->GetDigital(1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

float MedicOperatorInterface::getBatteryVoltage()
{
	return DriverStation::GetInstance()->GetBatteryVoltage();
	//return 0.0;
}
