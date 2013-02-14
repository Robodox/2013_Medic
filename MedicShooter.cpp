#include "MedicShooter.h"

MedicShooter::MedicShooter()
{
	MedicShooter(SHOOTER_WHEEL_VICTOR_CHANNEL);
}

MedicShooter::MedicShooter(UINT8 shooterWheelVictorChannel)
{
<<<<<<< HEAD
<<<<<<< HEAD
	shooterWheelA = new Victor(shooterWheelVictorChannelA);
	shooterWheelB = new Victor(shooterWheelVictorChannelB);
=======
	shooterEncoder = new Encoder(SHOOTER_ENCODER_CHANNEL_A, SHOOTER_ENCODER_CHANNEL_B, false,Encoder::k1X);
	shooterWheel = new Victor(shooterWheelVictorChannel);
>>>>>>> parent of 3678615... Elevation function worked on
=======
	shooterEncoder = new Encoder(SHOOTER_ENCODER_CHANNEL_A, SHOOTER_ENCODER_CHANNEL_B, false,Encoder::k1X);
	shooterWheel = new Victor(shooterWheelVictorChannel);
>>>>>>> parent of 3678615... Elevation function worked on
	pidOutput = new MedicPIDOutput();
	rpmSource = new MedicRPMSource(shooterEncoder);
	pidController = new PIDController(kP, kI, kD, rpmSource, pidOutput, .05);
}

MedicShooter::~MedicShooter()
{
	delete shooterWheel;
	delete pidController;
	delete pidOutput;
	delete rpmSource;
	
	shooterWheel = NULL;
	pidController = NULL;
	pidOutput = NULL;
	rpmSource = NULL;
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
<<<<<<< HEAD
<<<<<<< HEAD
	shooterWheelA->Set(targetVelocity, SYNC_STATE_OFF);//big one
	shooterWheelB->Set(FULL_SPEED, SYNC_STATE_OFF);//little one
=======
	shooterWheel->Set(targetVelocity, SYNC_STATE_OFF);
>>>>>>> parent of 3678615... Elevation function worked on
=======
	shooterWheel->Set(targetVelocity, SYNC_STATE_OFF);
>>>>>>> parent of 3678615... Elevation function worked on
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
