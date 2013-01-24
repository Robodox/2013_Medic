#ifndef MEDIC_MANIPULATOR_H
#define MEDIC_MANIPULATOR_H
#include "WPILib.h"
#include "MedicMacros.h"


class MedicManipulator
{
public:
	MedicManipulator();
	MedicManipulator(UINT8 intakeVictorChannel, UINT8 loaderVictorChannel, UINT8 conveyerVictorChannel,
			         UINT8 climberVictorChannelA, UINT8 climberVictorChannelB, UINT32 climberEncoderA,
			         UINT32 climberEncoderB, UINT8 pnuemSlot, UINT8 feederSolA, UINT8 feederSolB);
	~MedicManipulator();
	
	void intakeDisc(bool intake);
    void conveyer(bool move);
	void loadMagazine(bool load, bool unload);
	void climbPyramidA(bool climbA);
	void climbPyramidB(bool climbB);
	void feedShooter(bool feed);
	
private:
	Victor *intakeRoller;
	Victor *horizontalVerticalConveyer;
	Victor *loaderRoller;
	Victor *climberA;
	Victor *climberB;
	Encoder *climberEncoder;
	DoubleSolenoid *feeder;
};
#endif
