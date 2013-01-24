#include "MedicPIDOutput.h"

MedicPIDOutput::MedicPIDOutput()
{
	
}

MedicPIDOutput::~MedicPIDOutput()
{
	
}

void MedicPIDOutput::PIDWrite(float output)
{
	result = output;
}

double MedicPIDOutput::readOutput()
{
	return result;
}
