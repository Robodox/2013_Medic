#include "MedicShooter.h"

MedicShooter::MedicShooter()
{
	MedicShooter(SHOOTER_WHEEL_VICTOR_CHANNEL);
}

MedicShooter::MedicShooter(UINT8 shooterWheelVictorChannel)
{
	shooterEncoder = new Encoder(SHOOTER_ENCODER_CHANNEL_A, SHOOTER_ENCODER_CHANNEL_B, false,Encoder::k1X);
	shooterWheel = new Victor(shooterWheelVictorChannel);
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

void MedicShooter::shootDisc()
{
	setVictors();
}

double MedicShooter::getVelocity()
{
	return targetVelocity;
}

void MedicShooter::setTarget(double rpm)
{
	pidController->SetSetpoint(rpm); 
}

void MedicShooter::setVelocity(double input)
{
	targetVelocity = input;
}

void MedicShooter::setVictors()
{
	shooterWheel->Set(targetVelocity, SYNC_STATE_OFF);
}

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
