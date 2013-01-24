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
	MedicShooter(UINT8 shooterWheelVictorChannel);
	~MedicShooter();
	
	void shootDisc();	
	double getVelocity();
	void setVelocity(double input);
	void setVictors();
	bool isUpToSpeed();
	void setTarget(double rpm);
	MedicPIDOutput *pidOutput;
private:	
	Victor *shooterWheel;
	PIDController *pidController;

	MedicRPMSource *rpmSource;
	Encoder *shooterEncoder;
	double targetVelocity;
	double velocity;
	double rpm;
};
#endif
