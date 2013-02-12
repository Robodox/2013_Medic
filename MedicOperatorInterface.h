#ifndef MEDIC_OPERATOR_INTERFACE_H
#define MEDIC_OPERATOR_INTERFACE_H


#include "WPILib.h"
#include "MedicMacros.h"
#include "SmartDashboard/SmartDashboard.h"
#include "SmartDashboard/NamedSendable.h"
#include "SmartDashboard/Sendable.h"
#include "SmartDashboard/SendableChooser.h"

class MedicOperatorInterface
{
	
public:
	MedicOperatorInterface();	
	~MedicOperatorInterface();
	
	enum ShooterTargeting { highGoal = 1, middleGoal = 2, manualTargeting = 3}shooterTarget;
	
	/*
	 * Joystick getDriveJoystick
	 * Parameters: N/A
	 * Summary: Gets the Drive Joystick 
	 */
	Joystick *getDriveJoystick();
	
	/*
	 * Joystick getDriveJoystickButton
	 * Parameters: UINT8 button - could be any button on the joysticks
	 * Summary: Returns the raw drive button.
	 */
	UINT8 getDriveJoystickButton(UINT8 button);
	
	
	UINT8 getDriveJoystickButtonReleased(UINT8 button);
	

	/*
	 * Joystick getManipJoystick
	 * Parameters: N/A
	 * Summary: Gets the Manipulator Joystick 
	 */
	Joystick *getManipJoystick();
	
	/*
	 * Joystick getManipJoystickButton
	 * Parameters: UINT8 button - could be any button on the joysticks
	 * Summary: Returns the raw manipulator button.
	 */
	UINT8 getManipJoystickButton(UINT8 button);
	
	UINT8 getManipJoystickButtonReleased(UINT8 button);

	/*
	 * bool getPIDToggle
	 * Parameters: UINT8 toggle
	 * Summary: is the PID toggled?
	 */
	bool readPIDToggle(UINT8 toggle);
	bool readClimbSafetyEnable(UINT8 toggle);
	
	int readShooterTargeting(UINT8 toggle1, UINT8 toggle2);
	
	double readTargetDistance();
	double readTargetCenterX();
	double readTargetCenterY();
	bool readAutoAimToggle();
	float getBatteryVoltage();
	
	DriverStationLCD *dsLCD;
	SmartDashboard *dashboard;

private:
	Joystick *joyDrive;
	Joystick *joyManip;
	DriverStationEnhancedIO *ds;
};
#endif
