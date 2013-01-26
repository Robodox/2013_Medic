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
bool MedicOperatorInterface::getPIDToggle(UINT8 toggle)
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

double readTargetDistance()
{
	return dashboard->GetNumber("TargetDistance");
}

double readTargetHeight()
{
	
}

double readTargetWidth()
{
	
}
