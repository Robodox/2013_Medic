#include "MedicDrive.h"

MedicDrive::MedicDrive()
{
	linearVelocity = 0;
	turnSpeed = 0;

	shifter = new DoubleSolenoid(1, 2, 3); //PNEUMATICS_BUMPER_SLOT, SHIFTER_SOLENOID_CHANNEL_A, SHIFTER_SOLENOID_CHANNEL_B
	shifter->Set(DoubleSolenoid::kReverse);
																
	frontLeftMotor = new Talon(1);  //DRIVE_FRONT_LEFT_MOTOR_CHANNEL 
	rearLeftMotor = new Talon(1);   //DRIVE_REAR_LEFT_MOTOR_CHANNEL
	frontRightMotor = new Talon(1); //DRIVE_FRONT_RIGHT_MOTOR_CHANNEL
	rearRightMotor = new Talon(1);  //DRIVE_REAR_RIGHT_MOTOR_CHANNEL
								   	    			//DIGITAL_SIDECAR_SLOT_2, RIGHT_DRIVE_ENCODER_B_CHANNEL, CounterBase::k1X
}

MedicDrive::~MedicDrive()
{
	 delete shifter;
	 delete frontLeftMotor;
	 delete rearLeftMotor;
	 delete frontRightMotor;
	 delete rearRightMotor;
	 
	 shifter = NULL;
	 frontLeftMotor = NULL;
	 rearLeftMotor = NULL;
	 frontRightMotor = NULL;
	 rearRightMotor = NULL;
}

bool MedicDrive::shift (UINT8 highButton, UINT8 lowButton )
{
	 static bool lastGearWasHi = true;
	    
	    if(lowButton)
	    {
	        shifter->Set(DoubleSolenoid::kForward);
	        lastGearWasHi = false;
	    }
	    else if(highButton)
	    {
	        shifter->Set(DoubleSolenoid::kReverse);
	        lastGearWasHi = true;
	    }
	    
	    return lastGearWasHi;	
}

void MedicDrive::setLinVelocity(double linVal) 
{
	if(linVal > .1) //DEADZONE
	{
		linearVelocity = linVal;
	}
	else if(linVal < -.1) //DEADZONE
	{
		linearVelocity = linVal;
	}
	else 
	{
		linearVelocity = .1; //NEUTRAL
	}
	
}

double MedicDrive::reduceTurn(double reduceBy)
{
	return turnSpeed * reduceBy;
}

void MedicDrive::setTurnSpeed(double turn, bool turboButton)
{
	if((turn > .1 && !turboButton) || (turn < -.1 && !turboButton)) //DEADZONE
	{
		turnSpeed = turn;//*REDUCTION;
	}
	if(turn< .1 && turn > -.1) //DEADZONE
	{
		turnSpeed = 0; //NEUTRAL;
	}
	if((turn > .1 && turboButton) || (turn < -.1 && turboButton)) //DEADZONE
	{
		turnSpeed = turn;
	}
}

void MedicDrive::drive()
{
	frontLeftCmd = linearVelocity - turnSpeed;
	rearLeftCmd = linearVelocity - turnSpeed;
	frontRightCmd = -linearVelocity - turnSpeed;
	rearRightCmd = -linearVelocity - turnSpeed;
	
	frontLeftMotor->Set(frontLeftCmd, SYNC_STATE_OFF);
	rearLeftMotor->Set(rearLeftCmd, SYNC_STATE_OFF);
	frontRightMotor->Set(frontRightCmd, SYNC_STATE_OFF); 
	rearRightMotor->Set(rearRightCmd, SYNC_STATE_OFF); 
}

double MedicDrive::getVelocity()
{
	return linearVelocity;
}
