#ifndef MEDIC_DRIVE_H
#define MEDIC_DRIVE_H
#include "WPILib.h"
#include "MedicMacros.h"


class MedicDrive
{
public:
	MedicDrive();
	~MedicDrive();

	bool shift(UINT8 highButton, UINT8 lowButton);
	
	void setLinVelocity(double linVal);
	double getLinVelocity();
	
	void setTurnSpeed(double turn, bool turboButton);		
	double getTurnSpeed();	
	
	void drive();
	
	double getJagCmd(bool leftSide);
	
	double getVelocity();		
	double reduceTurn(double reduceBy);

	
	DoubleSolenoid *shifter;
	
private:	
	Talon *frontLeftMotor;
	Talon *rearLeftMotor;
	Talon *frontRightMotor;
	Talon *rearRightMotor;
	
	double linearVelocity; 
	double turnSpeed; 
	
	double frontLeftCmd;
	double rearLeftCmd;
	double frontRightCmd;
	double rearRightCmd;
};
#endif
