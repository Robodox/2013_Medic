#include "MedicManipulator.h"


MedicManipulator::MedicManipulator()
{
	MedicManipulator(ROLLER_VICTOR_CHANNEL, LOADER_VICTOR_CHANNEL, CONVEYER_VICTOR_CHANNEL,
					 CLIMBER_SOLENOID_CHANNEL_A, CLIMBER_SOLENOID_CHANNEL_B,
					 PNUEMATICS_CLIMBER_SLOT, PNUEMATICS_FEEDER_SLOT, 
			         FEEDER_SOLENOID_CHANNEL_A, FEEDER_SOLENOID_CHANNEL_B,
			         ANGLE_POT_CHANNEL);
}


MedicManipulator::MedicManipulator(UINT8 intakeVictorChannel, UINT8 loaderVictorChannel, 
								   UINT8 conveyerVictorChannel, UINT8 climberSolA, 
								   UINT8 climberSolB, UINT8 pnuemClimberSlot, 
								   UINT8 pnuemFeederSlot, UINT8 feederSolA,
								   UINT8 feederSolB, UINT8 anglePotChannel)
{		
	intakeRoller = new Victor(intakeVictorChannel);
	horizontalVerticalConveyer = new Victor(conveyerVictorChannel);
	loaderRoller = new Victor(loaderVictorChannel);
	climber = new DoubleSolenoid(pnuemClimberSlot, climberSolA, climberSolB);
	feeder = new DoubleSolenoid(pnuemFeederSlot, feederSolA, feederSolB);
	anglePot = new AnalogChannel(anglePotChannel);
}

MedicManipulator::~MedicManipulator()
{	
	delete intakeRoller;
	delete horizontalVerticalConveyer;
	delete loaderRoller;
	delete climber;
	delete feeder;
	
	intakeRoller = NULL;
	horizontalVerticalConveyer = NULL;
	loaderRoller = NULL;
	climber = NULL;
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
 * void climbPyramid
 * Parameters: bool climb - do we start climbing?
 * Summary: climbs the pyramid.
 */
void MedicManipulator::climbPyramid(bool climb)
{
	if(climb)
	{
		climber->Set(DoubleSolenoid::kForward);
	}
	else
	{
		climber->Set(DoubleSolenoid::kReverse);
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
double MedicManipulator::getShooterAngle()
{
  return 0;//TODO:Read Analog Pot	
}
