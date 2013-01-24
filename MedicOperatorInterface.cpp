#include "MedicOperatorInterface.h"

MedicOperatorInterface::MedicOperatorInterface()
{
	joyDrive = new Joystick(1);//TODO:real value
	joyManip = new Joystick(2);//TODO:real value
	DriverStation *dsSimple = DriverStation::GetInstance();
	ds = &dsSimple->GetEnhancedIO();
	dsLCD = DriverStationLCD::GetInstance();	
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

Joystick *MedicOperatorInterface::getDriveJoystick()
{
    return joyDrive;
}

Joystick *MedicOperatorInterface::getManipJoystick()
{
	return joyManip;
}

UINT8 MedicOperatorInterface::getDriveJoystickButton(UINT8 button)
{
	return joyDrive->GetRawButton(button);		
}

UINT8 MedicOperatorInterface::getManipJoystickButton(UINT8 button)
{
	return joyManip->GetRawButton(button);
}

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
