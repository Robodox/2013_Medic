#ifndef MEDIC_MANIPULATOR_H
#define MEDIC_MANIPULATOR_H
#include "WPILib.h"
#include "MedicMacros.h"


class MedicManipulator
{
public:
	MedicManipulator();
	MedicManipulator(UINT8 intakeRollerVictorChannel, UINT8 elevatorVictorChannel, 
			         UINT8 conveyerVictorChannel, UINT8 climberSolA, 
			         UINT8 climberSolB, UINT8 pnuemClimberSlot, 
			         UINT8 pnuemFeederSlot, UINT8 feederSolA, UINT8 feederSolB,
			         UINT8 anglePotChannel);
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
	 * void climbPyramid
	 * Parameters: bool climb - do we start climbing?
	 * Summary: climbs the pyramid
	 */
	void climbPyramid(bool climb);

	/*
	 * void feedShooter
	 * Parameters: bool feed - do we feed the shooter? 
	 * Summary: Feeds a disc from the mag to the shooter.
	 */
	void feedShooter(bool feed);
	
	void shooterElevationControl(double goal, double speed);
	
	float getShooterAngle();
	
private:
	Victor *intakeRoller;
	Victor *horizontalVerticalConveyer;
	Victor *elevatorMotor;
	DoubleSolenoid *climber;
	DigitalInput *climberSwitch;
	DoubleSolenoid *feeder;
	AnalogChannel *anglePot;
};
#endif
