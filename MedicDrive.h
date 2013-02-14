#ifndef MEDIC_DRIVE_H
#define MEDIC_DRIVE_H
#include "WPILib.h"
#include "MedicMacros.h"


class MedicDrive
{
public:
	MedicDrive();
	~MedicDrive();

	/*
	 * bool shift
	 * Parameters: UINT8 highButton - high gear button
	 * 			   UINT8 lowButton - low gear button
	 * Summary: Sets the shift in high or low gear. 
	 */
	bool shift(UINT8 highButton, UINT8 lowButton);
	
	/*
	 * void setLinVelocity 
	 * Parameters: double linVal - the linear value
	 * Summary: Sets Deadzones and neutral zone.
	 */
	void setLinVelocity(double linVal);
	
	double getLinVelocity();

	/*
	 * void setTurnSpeed
	 * Parameters: double turn - regular turning speed
	 * 		       bool turboButton - is the turbo switched on?
	 * Summary: Sets the turning speed, and/or off.
	 */
	void setTurnSpeed(double turn, bool turboButton);		
	
	double getTurnSpeed();	
	
	/*
	 * void drive
	 * Parameters: N/A
	 * Summary: Sets the speed of the wheels seperately.
	 */
	void drive();
	
	double getJagCmd(bool leftSide);
	
	/*
	 * double getVelocity
	 * Parameters: N/A
	 * Summary: Returns the linear velocity.
	 */
	double getVelocity();		

	/*
	 * double reduceTurn
	 * Parameters: double reduceBy - value to reduce turn speed by
	 * Summary: Reduces the turning speed.
	 */
	double reduceTurn(double reduceBy);
	void autoDrive(double target, double speed);
	void autoTurn(double target, double speed);
	
	enum autoFunctions{ linear, turn }functions;
	bool isAtTarget(autoFunctions functionType);	
	
	void resetAtTarget();
	
	DoubleSolenoid *shifter;

	Encoder *leftEncoder;
	Encoder *rightEncoder;
	double currentTicks ; //average of encoder values; used in auton
		double targetTicks;  //target encoder values; used in auton
		double deltaTicks;   //change in encoder values; used in auton
		double error;        //the offset of target ticks relative to current ticks; used in auton

		bool isAtDriveTarget;
		bool isAtTurnTarget;
private:	
	Jaguar *frontLeftMotor; //TODO: Talon
	Jaguar *rearLeftMotor;//TODO: Talon
	Jaguar *frontRightMotor;//TODO: Talon
	Jaguar *rearRightMotor;//TODO: Talon
	
	double linearVelocity; 
	double turnSpeed; 
	
	double frontLeftCmd;
	double rearLeftCmd;
	double frontRightCmd;
	double rearRightCmd;
	
};
#endif
