#ifndef MEDIC_RPM_SOURCE_H
#define MEDIC_RPM_SOURCE_H
#include "WPILib.h"

class MedicRPMSource : public PIDSource
{
public:
	MedicRPMSource(Encoder *source);
	virtual ~MedicRPMSource();
	void inputRPM(double input);
	double PIDGet();
	Encoder *rpmSource;
private:
	double rpm;
};
#endif
