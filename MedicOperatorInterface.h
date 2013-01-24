#ifndef MEDIC_OPERATOR_INTERFACE_H
#define MEDIC_OPERATOR_INTERFACE_H


#include "WPILib.h"
#include "MedicMacros.h"

class MedicOperatorInterface
{
public:
	MedicOperatorInterface();	
	~MedicOperatorInterface();
	Joystick *getDriveJoystick();
	UINT8 getDriveJoystickButton(UINT8 button);
	UINT8 getDriveJoystickButtonReleased(UINT8 button);
	Joystick *getManipJoystick();
	UINT8 getManipJoystickButton(UINT8 button);
	UINT8 getManipJoystickButtonReleased(UINT8 button);
	bool getPIDToggle(UINT8 toggle);
	bool getBridgeToggle;
	DriverStationLCD *dsLCD;
private:
	Joystick *joyDrive;
	Joystick *joyManip;
	DriverStationEnhancedIO *ds;
};
#endif
