#ifndef MEDIC_MANIPULATOR_H
#define MEDIC_MANIPULATOR_H
#include "WPILib.h"
#include "MedicMacros.h"


class MedicManipulator
{
public:
	MedicManipulator();
	MedicManipulator(UINT8 intakeVictorChannel, UINT8 loaderVictorChannel, 
			         UINT8 conveyerVictorChannel, UINT8 pnuemSlot, UINT8 feederSolA, UINT8 feederSolB);
	~MedicManipulator();
	
	void intakeDisc(bool intake);
    void conveyer(bool move);
	void loadMagazine(bool load, bool unload);
	void feedShooter(bool feed);
	
private:
	Victor *intakeRoller;
	Victor *horizontalVerticalConveyer;
	Victor *loaderRoller;
	Victor *climberA;
	Victor *climberB;
	Encoder *climberEncoder;
	DigitalInput *climberSwitch;
	DoubleSolenoid *feeder;
};
#endif
