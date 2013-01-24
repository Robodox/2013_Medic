#include "MedicManipulator.h"


MedicManipulator::MedicManipulator()
{
	MedicManipulator(ROLLER_VICTOR_CHANNEL, LOADER_VICTOR_CHANNEL, CONVEYER_VICTOR_CHANNEL, 
			         PNUEMATICS_FEEDER_SLOT, FEEDER_SOLENOID_CHANNEL_A, FEEDER_SOLENOID_CHANNEL_B);
}

MedicManipulator::MedicManipulator(UINT8 intakeVictorChannel, UINT8 loaderVictorChannel, 
								   UINT8 conveyerVictorChannel, UINT8 pnuemSlot, 
								   UINT8 feederSolA, UINT8 feederSolB)
{		
	intakeRoller = new Victor(intakeVictorChannel);
	horizontalVerticalConveyer = new Victor(conveyerVictorChannel);
	loaderRoller = new Victor(loaderVictorChannel);
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
