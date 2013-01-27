#include "WPILib.h"

#include "MedicDrive.h"
#include "MedicManipulator.h"
#include "MedicOperatorInterface.h"
#include "MedicShooter.h"
#include "MedicPIDOutput.h"
#include "MedicMacros.h"


class Medic: public IterativeRobot
{
	MedicShooter *shooter;
	MedicDrive *drive;
	MedicManipulator *manipulator;
	MedicOperatorInterface *oi;
	MedicPIDOutput *pid;
	Compressor *comp599;

public:

	Medic()
	{
		drive = new MedicDrive();
		manipulator = new MedicManipulator();
		oi = new MedicOperatorInterface();
		shooter = new MedicShooter();
		pid = new MedicPIDOutput();
		comp599 = new Compressor(1, 1);//TODO: add real values
		
		comp599->Start();

	}
	
	void RobotInit()
	{
		
	}
	
	void DisabledInit()
	{
		
	}
	
	void AutonomousInit()
	{

		
	}
	
	void TeleopInit()
	{
		while(IsOperatorControl())
		{
			intake();
			shoot();
		
		}
		
	}
   
	void TestInit()
	{
		
	}
	
	void DisabledPeriodic()
	{
		
	}
	
	void AutonomousPeriodic()
	{
		
	}
	
	void TeleopPeriodic()
	{
		while(IsOperatorControl())
		{
		  teleDrive();
		}
	}
	
	void TestPeriodic()
	{
		
	}
	
	void teleDrive()
	{
		drive->setLinVelocity(oi->getDriveJoystick()->GetY());
		drive->setTurnSpeed(oi->getDriveJoystick()->GetX(), oi->getDriveJoystickButton(1));//TODO: Actual button value needed
		drive->drive();
		drive->shift(oi->getDriveJoystickButton(1), oi->getDriveJoystickButton(1));
	}
	
	void setPID()
	{
		pid->PIDWrite(.1); //0
		
	}
	
	float getPID()
	{
		return pid->result;
	}
	
	void shoot()
	{
		if(oi->readPIDToggle(1))//TODO: Macro goes here
		{
			shooter->setTarget((oi->getManipJoystick()->GetThrottle()+1)/2);
			shooter->setVelocity(shooter->pidOutput->readOutput());
			shooter->shootDisc();
		}
		else
		{
			shooter->setVelocity((oi->getManipJoystick()->GetThrottle()+1)/2);
			shooter->shootDisc();
		}
		
	}
	
	void intake()
	{
		if(oi->getManipJoystickButton(1) == 1)
		{
			manipulator->intakeDisc(true); // intake
			manipulator->conveyer(true); // move
			manipulator->loadMagazine(true, false); // load, unload
			manipulator->feedShooter(true); // feed
		}
		else
		{
			manipulator->intakeDisc(false); // intake
			manipulator->conveyer(false); // move
			manipulator->loadMagazine(false, true); // load, unload
			manipulator->feedShooter(false); // feed				
		}

	}		
	
	    		
};

START_ROBOT_CLASS(Medic);
