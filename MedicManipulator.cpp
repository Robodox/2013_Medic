#include "MedicManipulator.h"


MedicManipulator::MedicManipulator()
{
	MedicManipulator(ROLLER_VICTOR_CHANNEL, LOADER_VICTOR_CHANNEL, CONVEYER_VICTOR_CHANNEL,
					 CLIMBER_VICTOR_CHANNEL_A, CLIMBER_VICTOR_CHANNEL_B,
					 CLIMBER_ENCODER_A, CLIMBER_ENCODER_B,
			         PNUEMATICS_FEEDER_SLOT, FEEDER_SOLENOID_CHANNEL_A, FEEDER_SOLENOID_CHANNEL_B);
}

MedicManipulator::MedicManipulator(UINT8 intakeVictorChannel, UINT8 loaderVictorChannel, 
								   UINT8 conveyerVictorChannel, UINT8 climberVictorChannelA, 
								   UINT8 climberVictorChannelB, UINT32 climberEncoderA, 
								   UINT32 climberEncoderB, UINT8 pnuemSlot,
								   UINT8 feederSolA, UINT8 feederSolB)
{		
	intakeRoller = new Victor(intakeVictorChannel);
	horizontalVerticalConveyer = new Victor(conveyerVictorChannel);
	loaderRoller = new Victor(loaderVictorChannel);
	climberA = new Victor(climberVictorChannelA);
	climberB = new Victor(climberVictorChannelB);
	climberEncoder = new Encoder(climberEncoderA, climberEncoderB, false, Encoder::k1X);
	feeder = new DoubleSolenoid(pnuemSlot, feederSolA, feederSolB);
}

MedicManipulator::~MedicManipulator()
{	
	delete intakeRoller;
	delete horizontalVerticalConveyer;
	delete loaderRoller;
	delete feeder;
	
	intakeRoller = NULL;
	horizontalVerticalConveyer = NULL;
	loaderRoller = NULL;
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
 * void loadMagazine
 * Parameters: bool load - do we load the mag? 
 * 			   bool unload - do we unload the mag?
 * Summary: Loads and unloads the Magazine.
 */
void MedicManipulator::loadMagazine(bool load, bool unload)
{
	if(load)
	{
		loaderRoller->Set(LOADER_DOWN, SYNC_STATE_OFF);
	}
	else if(unload)
	{
	    loaderRoller->Set(LOADER_UP, SYNC_STATE_OFF);
	}
	else
	{
		loaderRoller->Set(LOADER_OFF, SYNC_STATE_OFF);
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
