#include "MedicDrive.h"

MedicDrive::MedicDrive()
{
	linearVelocity = 0;
	turnSpeed = 0;
	isAtDriveTarget = false;
	isAtTurnTarget = false;
	
	currentTicks = 0; //average of encoder values; used in auton
	targetTicks = 0;  //target encoder values; used in auton
	deltaTicks = 0;   //change in encoder values; used in auton
	error = 0;        //the offset of target ticks relative to current ticks; used in auton

	shifter = new DoubleSolenoid(1, 2, 3); //PNEUMATICS_BUMPER_SLOT, SHIFTER_SOLENOID_CHANNEL_A, SHIFTER_SOLENOID_CHANNEL_B
	shifter->Set(DoubleSolenoid::kReverse);
																
	frontLeftMotor = new Jaguar(1, DRIVE_FRONT_LEFT_MOTOR_CHANNEL);   //TODO: Talon
	rearLeftMotor = new Jaguar(1, DRIVE_REAR_LEFT_MOTOR_CHANNEL);   //TODO: TALON
	frontRightMotor = new Jaguar(1, DRIVE_FRONT_RIGHT_MOTOR_CHANNEL); //TODO: Talon
	rearRightMotor = new Jaguar(1, DRIVE_REAR_RIGHT_MOTOR_CHANNEL);//TODO: Talon
	leftEncoder = new Encoder(LEFT_DRIVE_ENCODER_CHANNEL_A, LEFT_DRIVE_ENCODER_CHANNEL_B, true, Encoder::k1X);
	rightEncoder = new Encoder(RIGHT_DRIVE_ENCODER_CHANNEL_A, RIGHT_DRIVE_ENCODER_CHANNEL_B, false, Encoder::k1X);
	

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

/*
 * bool shift
 * Parameters: UINT8 highButton - high gear button
 * 			   UINT8 lowButton - low gear button
 * Summary: Sets the shift in high or low gear. 
 */
bool MedicDrive::shift(UINT8 highButton, UINT8 lowButton)
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

/*
 * void setLinVelocity 
 * Parameters: double linVal - the linear value
 * Summary: Sets Deadzones and neutral zone.
 */
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
		linearVelocity = 0; //NEUTRAL
	}
	
}

double MedicDrive::getLinVelocity()
{
	return linearVelocity;
}

/*
 * double reduceTurn
 * Parameters: double reduceBy - value to reduce turn speed by
 * Summary: Reduces the turning speed.
 */
double MedicDrive::reduceTurn(double reduceBy)
{
	return turnSpeed * reduceBy;
}

/*
 * void setTurnSpeed
 * Parameters: double turn - regular turning speed
 * 		       bool turboButton - is the turbo switched on?
 * Summary: Sets the turning speed, and/or off.
 */
void MedicDrive::setTurnSpeed(double turn, bool turboButton)
{
	if((turn > .1 && !turboButton) || (turn < -.1 && !turboButton)) //DEADZONE
	{
		turnSpeed = turn * REDUCTION;
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

double MedicDrive::getTurnSpeed()
{
	return turnSpeed;
}

/*
 * void drive
 * Parameters: N/A
 * Summary: Sets the speed of the wheels seperately.
 */
void MedicDrive::drive()
{
	frontLeftCmd = linearVelocity + turnSpeed;
	rearLeftCmd = linearVelocity + turnSpeed;
	frontRightCmd = linearVelocity - turnSpeed;
	rearRightCmd = linearVelocity - turnSpeed;
	
	frontLeftMotor->Set(-frontLeftCmd, SYNC_STATE_OFF);
	rearLeftMotor->Set(-rearLeftCmd, SYNC_STATE_OFF);
	frontRightMotor->Set(frontRightCmd, SYNC_STATE_OFF); 
	rearRightMotor->Set(rearRightCmd, SYNC_STATE_OFF); 
}

void MedicDrive::autoDrive(double target, double speed)
{
	static bool init = true;
	static double initTicks = 0;
	
	currentTicks = (leftEncoder->Get() + rightEncoder->Get()) / 2;
	
	if(init)
	{
		initTicks = currentTicks;	
		targetTicks = target / INCHES_PER_TICK;
		init = false;
	}
	else
	{	
		deltaTicks = currentTicks - initTicks;
		error = targetTicks - deltaTicks;
		if(error < 0 - AUTO_DRIVE_DEADZONE / INCHES_PER_TICK)
		{
			setLinVelocity(-speed);
			isAtDriveTarget = false;
		}
		else if(error > 0 + AUTO_DRIVE_DEADZONE / INCHES_PER_TICK)
		{
			setLinVelocity(speed);
			isAtDriveTarget = false;
		}
		else
		{
			setLinVelocity(0);
			isAtDriveTarget = true;
			init = true;
		}
		drive();
	}
}
void MedicDrive::autoTurn(double target, double speed)
{
	static bool init = true;
	static double initTicks = 0;
	static double currentTicks = 0;
	static double deltaTicks = 0;
	static double targetTicks = 0;	
	static double error = 0;
	
	if(init)
	{
		initTicks = leftEncoder->Get() - rightEncoder->Get();
		targetTicks = target / TICKS_PER_DEGREE;
		init = false;
	}
	else
	{
		currentTicks = leftEncoder->Get() - rightEncoder->Get();
		deltaTicks = currentTicks - initTicks;
		error = targetTicks - deltaTicks;
		if(error < 0 - AUTO_TURN_DEADZONE / TICKS_PER_DEGREE)
		{
			setTurnSpeed(-speed, false);
			isAtTurnTarget = false;

		}
		else if(error > 0 + AUTO_TURN_DEADZONE / TICKS_PER_DEGREE)
		{
			setTurnSpeed(speed, false);
			isAtTurnTarget = false;
		}
		else
		{
			setTurnSpeed(0, false);
			isAtTurnTarget = true;
			init = true;
		}
		drive();
	}
}
bool MedicDrive::isAtTarget(autoFunctions functionType)
{
	if(functionType == linear)
	{
		if(isAtDriveTarget)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(functionType == turn)
	{
		if(isAtTurnTarget)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void MedicDrive::resetAtTarget()
{
	isAtDriveTarget = false;
	isAtTurnTarget = false;
}

/*
 * double getVelocity
 * Parameters: N/A
 * Summary: Returns the linear velocity.
 */
double MedicDrive::getVelocity()
{
	return linearVelocity;
}
