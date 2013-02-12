#ifndef MEDIC_SHOOTER_H
#define MEDIC_SHOOTER_H
#include "WPILib.h"
#include "MedicMacros.h"
#include "MedicRPMSource.h"
#include "MedicPIDOutput.h"

class MedicShooter
{
public:
	MedicShooter();
	MedicShooter(UINT8 shooterWheelVictorChannelA, UINT8 shooterWheelVictorChannelB, UINT32 shooterWheelIRChannel);
	~MedicShooter();
	
	/*
	 * void shootDisc
	 * Parameters: N/A
	 * Summary: Calls setVictors function.
	 */
	void shootDisc();	
	
	/*
	 * double getVelocity
	 * Parameters: N/A
	 * Summary: returns the target velocity.
	 */
	double getVelocity();
	
	/*
	 * void setTarget
	 * Parameters: rpm - the RPM of the shooter motor
	 * Summary: Sets the RPM.
	 */
	void setVelocity(double input);
	
	/*
	 * void setVictors
	 * Parameters: N/A
	 * Summary: sets target velocity to shooter wheel
	 */
	void setVictors();
	
	/*
	 * bool isUpToSpeed
	 * Parameters: N/A
	 * Summary: checks if current velocity has reached target velocity
	 */
	bool isUpToSpeed();
	
	/*
	 * void setTarget
	 * Parameters: rpm - the RPM of the shooter motor
	 * Summary: Sets the RPM.
	 */
	void setTarget(double rpm);
	MedicPIDOutput *pidOutput;
private:	
	Victor *shooterWheelA;
	Victor *shooterWheelB;
	PIDController *pidController;
	
	DigitalInput *shooterWheelIR;
	MedicRPMSource *rpmSource;
	Encoder *shooterEncoder;
	double targetVelocity;
	double velocity;
	double rpm;
};
#endif
