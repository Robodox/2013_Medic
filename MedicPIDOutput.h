#ifndef MEDICPIDOUTPUT_H
#define MEDICPIDOUTPUT_H
#include "WPILib.h"

class MedicPIDOutput : public PIDOutput
{
public:
	MedicPIDOutput();
	virtual ~MedicPIDOutput();
	void PIDWrite(float output);
	double readOutput();
	double result;
};

#endif
