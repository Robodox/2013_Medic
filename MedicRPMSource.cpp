#include "MedicRPMSource.h"

MedicRPMSource::MedicRPMSource(Encoder *source)
{
	rpmSource = source;
}

MedicRPMSource::~MedicRPMSource()
{
	delete rpmSource;
	
	rpmSource = NULL;
}

void MedicRPMSource::inputRPM(double input)
{
	rpm =  input;
}

double MedicRPMSource::PIDGet()
{
	return rpm;
}
