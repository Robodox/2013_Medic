#include "MedicManipulator.h"


MedicManipulator::MedicManipulator()
{
<<<<<<< HEAD
<<<<<<< HEAD
	MedicManipulator(INTAKE_ROLLER_VICTOR_CHANNEL, ELEVATOR_VICTOR_CHANNEL, CONVEYER_VICTOR_CHANNEL,
					 CLIMBER_SOLENOID_CHANNEL_A, CLIMBER_SOLENOID_CHANNEL_B,
					 PNUEMATICS_CLIMBER_SLOT, PNUEMATICS_FEEDER_SLOT, 
			         FEEDER_SOLENOID_CHANNEL_A, FEEDER_SOLENOID_CHANNEL_B,
			         ANGLE_POT_CHANNEL);
}


MedicManipulator::MedicManipulator(UINT8 intakeRollerVictorChannel, UINT8 elevatorVictorChannel,
								   UINT8 conveyerVictorChannel, UINT8 climberSolA, 
								   UINT8 climberSolB, UINT8 pnuemClimberSlot, 
								   UINT8 pnuemFeederSlot, UINT8 feederSolA,
								   UINT8 feederSolB, UINT8 anglePotChannel)
=======
	MedicManipulator(ROLLER_VICTOR_CHANNEL, LOADER_VICTOR_CHANNEL, CONVEYER_VICTOR_CHANNEL,
					 CLIMBER_VICTOR_CHANNEL_A, CLIMBER_VICTOR_CHANNEL_B,
					 CLIMBER_ENCODER_A, CLIMBER_ENCODER_B,
			         PNUEMATICS_FEEDER_SLOT, FEEDER_SOLENOID_CHANNEL_A, FEEDER_SOLENOID_CHANNEL_B);
}


=======
	MedicManipulator(ROLLER_VICTOR_CHANNEL, LOADER_VICTOR_CHANNEL, CONVEYER_VICTOR_CHANNEL,
					 CLIMBER_VICTOR_CHANNEL_A, CLIMBER_VICTOR_CHANNEL_B,
					 CLIMBER_ENCODER_A, CLIMBER_ENCODER_B,
			         PNUEMATICS_FEEDER_SLOT, FEEDER_SOLENOID_CHANNEL_A, FEEDER_SOLENOID_CHANNEL_B);
}


>>>>>>> parent of 3678615... Elevation function worked on
MedicManipulator::MedicManipulator(UINT8 intakeVictorChannel, UINT8 loaderVictorChannel, 
								   UINT8 conveyerVictorChannel, UINT8 climberVictorChannelA, 
								   UINT8 climberVictorChannelB, UINT32 climberEncoderA, 
								   UINT32 climberEncoderB, UINT8 pnuemSlot,
								   UINT8 feederSolA, UINT8 feederSolB)
<<<<<<< HEAD
>>>>>>> parent of 3678615... Elevation function worked on
=======
>>>>>>> parent of 3678615... Elevation function worked on
{		
	intakeRoller = new Victor(intakeRollerVictorChannel);
	elevatorMotor = new Victor(elevatorVictorChannel);
	horizontalVerticalConveyer = new Victor(conveyerVictorChannel);
<<<<<<< HEAD
<<<<<<< HEAD
	climber = new DoubleSolenoid(pnuemClimberSlot, climberSolA, climberSolB);
	feeder = new DoubleSolenoid(pnuemFeederSlot, feederSolA, feederSolB);
	anglePot = new AnalogChannel(anglePotChannel);
=======
=======
>>>>>>> parent of 3678615... Elevation function worked on
	loaderRoller = new Victor(loaderVictorChannel);
	climberA = new Victor(climberVictorChannelA);
	climberB = new Victor(climberVictorChannelB);
	climberEncoder = new Encoder(climberEncoderA, climberEncoderB, false, Encoder::k1X);
	feeder = new DoubleSolenoid(pnuemSlot, feederSolA, feederSolB);
<<<<<<< HEAD
>>>>>>> parent of 3678615... Elevation function worked on
=======
>>>>>>> parent of 3678615... Elevation function worked on
}

MedicManipulator::~MedicManipulator()
{	
	delete intakeRoller;
	delete elevatorMotor;
	delete horizontalVerticalConveyer;
<<<<<<< HEAD
<<<<<<< HEAD
	delete climber;
=======
	delete loaderRoller;
>>>>>>> parent of 3678615... Elevation function worked on
=======
	delete loaderRoller;
>>>>>>> parent of 3678615... Elevation function worked on
	delete feeder;
	
	intakeRoller = NULL;
	elevatorMotor = NULL;
	horizontalVerticalConveyer = NULL;
<<<<<<< HEAD
<<<<<<< HEAD
	climber = NULL;
=======
	loaderRoller = NULL;
>>>>>>> parent of 3678615... Elevation function worked on
=======
	loaderRoller = NULL;
>>>>>>> parent of 3678615... Elevation function worked on
	feeder = NULL;
}

/*
 * void intakeDisc
 * Parameters: bool intake - do we intake a disc?
 * Summary: intakes a disc with a roller
 */
void MedicManipulator::intakeDisc(bool intake)
{	
	if(intake)
	{
		intakeRoller->Set(INTAKE_MOVE, SYNC_STATE_OFF); 
	}
	else
	{
		intakeRoller->Set(INTAKE_STOP, SYNC_STATE_OFF);  
	}
}

/*
 * void conveyer
 * Parameters: bool move - do we move the two conveyers? 
 * Summary: Moves the horizontal and vertical conveyers
 */
void MedicManipulator::conveyer(bool move)
{	
	if(move)
	{
		horizontalVerticalConveyer->Set(CONVEYER_MOVE, SYNC_STATE_OFF);
	}
	else
	{
		horizontalVerticalConveyer->Set(CONVEYER_STOP, SYNC_STATE_OFF);
	}
}	


/*
 * void climbPyramidA
 * Parameters: bool climbA - does the first climbing arm move?
 * Summary: Move or stop the first climbing arm.
 */
void MedicManipulator::climbPyramidA(bool climbA)
{
	if(climbA)
	{
		climberA->Set(CLIMBER_A_MOVE, SYNC_STATE_OFF);
	}
	else
	{
		climberA->Set(CLIMBER_A_STOP, SYNC_STATE_OFF);
	}
}

/*
<<<<<<< HEAD
 * void climbPyramidB
 * Parameters: bool climbB - does the second climbing arm move?
 * Summary: Move or stop the second climbing arm.
 */
void MedicManipulator::climbPyramidB(bool climbB)
{
	if(climbB)
	{
		climberB->Set(CLIMBER_B_MOVE, SYNC_STATE_OFF);
	}
	else
	{
		climberB->Set(CLIMBER_B_STOP, SYNC_STATE_OFF);
	}
}

=======
 * void climbPyramidA
 * Parameters: bool climbA - does the first climbing arm move?
 * Summary: Move or stop the first climbing arm.
 */
void MedicManipulator::climbPyramidA(bool climbA)
{
	if(climbA)
	{
		climberA->Set(CLIMBER_A_MOVE, SYNC_STATE_OFF);
	}
	else
	{
		climberA->Set(CLIMBER_A_STOP, SYNC_STATE_OFF);
	}
}

/*
 * void climbPyramidB
 * Parameters: bool climbB - does the second climbing arm move?
 * Summary: Move or stop the second climbing arm.
 */
void MedicManipulator::climbPyramidB(bool climbB)
{
	if(climbB)
	{
		climberB->Set(CLIMBER_B_MOVE, SYNC_STATE_OFF);
	}
	else
	{
		climberB->Set(CLIMBER_B_STOP, SYNC_STATE_OFF);
	}
}

>>>>>>> parent of 3678615... Elevation function worked on
/*
 * void feedShooter
 * Parameters: bool feed - do we feed the shooter? 
 * Summary: Feeds a disc from the mag to the shooter.
 */
void MedicManipulator::feedShooter(bool feed)
{
	if(feed)
	{
		feeder->Set(DoubleSolenoid::kForward);
	}
	else 
	{
		feeder->Set(DoubleSolenoid::kReverse);
	}
}
<<<<<<< HEAD
<<<<<<< HEAD

void MedicManipulator::shooterElevationControl(double goal, double speed = ELEVATION_SPEED)
{
	//Make function use boolean value to either go up or down at a certain rate from
	//joystick button used as source of boolean
	static double error = 0;
	double motorSpeed = 0;
	double angle = 0;
	angle = getShooterAngle();
	error = goal - angle;

    if(error < -ELEVATION_DEADZONE)
	{
    	motorSpeed = speed;
	}
	else if(error > ELEVATION_DEADZONE) 
	{
		motorSpeed = -speed;
	}
	else 
	{
		motorSpeed = 0;
	}
	
    if (angle > SHOOTER_MAX_ELEVATION && motorSpeed > 0)
	{
		motorSpeed = 0;
	}
	else if (angle < SHOOTER_MIN_ELEVATION && motorSpeed < 0)
	{
		motorSpeed = 0;
	}
    
    elevatorMotor->Set(motorSpeed, SYNC_STATE_OFF);//In Deadzone(0)	
}

float MedicManipulator::getShooterAngle()
{
  return anglePot->GetVoltage();// * SHOOTER_POT_DEGREES_PER_VOLT;
}

=======
>>>>>>> parent of 3678615... Elevation function worked on
=======
>>>>>>> parent of 3678615... Elevation function worked on
