#include "MedicShooter.h"

MedicShooter::MedicShooter()
{
	MedicShooter(SHOOTER_WHEEL_VICTOR_CHANNEL_A, SHOOTER_WHEEL_VICTOR_CHANNEL_B, SHOOTER_WHEEL_IR_CHANNEL);
}

MedicShooter::MedicShooter(UINT8 shooterWheelVictorChannelA, UINT8 shooterWheelVictorChannelB, UINT32 shooterWheelIRChannel)
{
	shooterWheelA = new Victor(shooterWheelVictorChannelA);
	shooterWheelB = new Victor(shooterWheelVictorChannelB);
	pidOutput = new MedicPIDOutput();
	rpmSource = new MedicRPMSource(shooterEncoder);
	pidController = new PIDController(kP, kI, kD, rpmSource, pidOutput, .05);
	shooterWheelIR = new DigitalInput(shooterWheelIRChannel);
}

MedicShooter::~MedicShooter()
{
	delete shooterWheelA;
	delete shooterWheelB;
	delete pidController;
	delete pidOutput;
	delete rpmSource;
	delete shooterWheelIR;
	
	shooterWheelA = NULL;
	shooterWheelB = NULL;
	pidController = NULL;
	pidOutput = NULL;
	rpmSource = NULL;
	shooterWheelIR = NULL;
}

/*
 * void shootDisc
 * Parameters: N/A
 * Summary: Calls setVictors function.
 */
void MedicShooter::shootDisc()
{
	setVictors();
}

/*
 * double getVelocity
 * Parameters: N/A
 * Summary: returns the target velocity.
 */
double MedicShooter::getVelocity()
{
	return targetVelocity;
}

/*
 * void setTarget
 * Parameters: rpm - the RPM of the shooter motor
 * Summary: Sets the RPM.
 */
void MedicShooter::setTarget(double rpm)
{
	pidController->SetSetpoint(rpm); 
}

/*
 * void setVelocity
 * Parameters: input - the velocity 
 * Summary: Sets the target velocity to input.
 */
void MedicShooter::setVelocity(double input)
{
	targetVelocity = input;
}

/*
 * void setVictors
 * Parameters: N/A
 * Summary: sets target velocity to shooter wheel
 */
void MedicShooter::setVictors()
{
	shooterWheelA->Set(targetVelocity, SYNC_STATE_OFF);//big one
	shooterWheelB->Set(FULL_SPEED, SYNC_STATE_OFF);//little one
}

/*
 * bool isUpToSpeed
 * Parameters: N/A
 * Summary: checks if current velocity has reached target velocity
 */
bool MedicShooter::isUpToSpeed()
{
	if(targetVelocity == velocity)
	{
		return true;
	} 
	else 
	{
		return false;
	}
}
