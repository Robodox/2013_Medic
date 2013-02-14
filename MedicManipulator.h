#ifndef MEDIC_MANIPULATOR_H
#define MEDIC_MANIPULATOR_H
#include "WPILib.h"
#include "MedicMacros.h"


class MedicManipulator
{
public:
	MedicManipulator();
<<<<<<< HEAD
	MedicManipulator(UINT8 intakeRollerVictorChannel, UINT8 elevatorVictorChannel, 
			         UINT8 conveyerVictorChannel, UINT8 climberSolA, 
			         UINT8 climberSolB, UINT8 pnuemClimberSlot, 
			         UINT8 pnuemFeederSlot, UINT8 feederSolA, UINT8 feederSolB,
			         UINT8 anglePotChannel);
=======
	MedicManipulator(UINT8 intakeVictorChannel, UINT8 loaderVictorChannel, 
			         UINT8 conveyerVictorChannel, UINT8 climberVictorChannelA, 
			         UINT8 climberVictorChannelB, UINT32 climberEncoderA,
			         UINT32 climberEncoderB, UINT8 pnuemSlot, 
			         UINT8 feederSolA, UINT8 feederSolB);
>>>>>>> parent of 3678615... Elevation function worked on
	~MedicManipulator();
	
	/*
	 * void intakeDisc
	 * Parameters: bool intake - do we intake a disc?
	 * Summary: intakes a disc with a roller
	 */
	void intakeDisc(bool intake);
	
	/*
	 * void conveyer
	 * Parameters: bool move - do we move the two conveyers? 
	 * Summary: Moves the horizontal and vertical conveyers
	 */
	void conveyer(bool move);
	
	/*
<<<<<<< HEAD
	 * void climbPyramid
	 * Parameters: bool climb - do we start climbing?
	 * Summary: climbs the pyramid
=======
	 * void loadMagazine
	 * Parameters: bool load - do we load the mag? 
	 * 			   bool unload - do we unload the mag?
	 * Summary: Loads and unloads the Magazine.
	 */
	void loadMagazine(bool load, bool unload);
	
	/*
	 * void climbPyramidA
	 * Parameters: bool climbA - does the first climbing arm move?
	 * Summary: Move or stop the first climbing arm.
>>>>>>> parent of 3678615... Elevation function worked on
	 */
	void climbPyramidA(bool climbA);
	
	/*
	 * void climbPyramidB
	 * Parameters: bool climbB - does the second climbing arm move?
	 * Summary: Move or stop the second climbing arm.
	 */
	void climbPyramidB(bool climbB);

	/*
	 * void feedShooter
	 * Parameters: bool feed - do we feed the shooter? 
	 * Summary: Feeds a disc from the mag to the shooter.
	 */
	void feedShooter(bool feed);
	
<<<<<<< HEAD
	void shooterElevationControl(double goal, double speed);
	
	float getShooterAngle();
	
private:
	Victor *intakeRoller;
	Victor *horizontalVerticalConveyer;
	Victor *elevatorMotor;
	DoubleSolenoid *climber;
=======
private:
	Victor *intakeRoller;
	Victor *horizontalVerticalConveyer;
	Victor *loaderRoller;
	Victor *climberA;
	Victor *climberB;
	Encoder *climberEncoder;
>>>>>>> parent of 3678615... Elevation function worked on
	DigitalInput *climberSwitch;
	DoubleSolenoid *feeder;
};
#endif
