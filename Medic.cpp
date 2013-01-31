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
	MedicPIDOutput *pidOutput;
	Compressor *comp599;

public:

	Medic()
	{
		drive = new MedicDrive();
		manipulator = new MedicManipulator();
		oi = new MedicOperatorInterface();
		shooter = new MedicShooter();
		pidOutput = new MedicPIDOutput();
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
	
	//TODO: write auton drive(angle, speed) & drive(distance, speed)
	void AutonomousPeriodic()
	{
		shoot(true);					//shoot preloads
		
		drive->autoTurn(55, TURN_SPEED); 		
		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number		 		
		drive->autoTurn(-90, TURN_SPEED); 		
		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 		//get the weirdly angled discs OF DOOM
		intake(true);					
		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 		
		
		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 
		drive->autoTurn(55, TURN_SPEED); 		//aim and then shoot discs of doom 
		shoot(true);	
		
		drive->autoTurn(55, TURN_SPEED); 
		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 
		drive->autoTurn(-90, TURN_SPEED); 
		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 		//get OTHER weirdly angled discs of doom
		intake(true);	
		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 
		
		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number
		drive->autoTurn(55, TURN_SPEED);			//aim and shoot OTHER weirdly angled discs of doom
		shoot(true);	
		
		
		//like a boss
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
		if(oi->getManipJoystickButton(1) == 1)//TODO: Macro goes here
		{
			manipulator->intakeDisc(true); // intake
			manipulator->conveyer(true); // move
			manipulator->loadMagazine(true, false); // load, unload			
		}
		else
		{
			manipulator->intakeDisc(false); // intake
			manipulator->conveyer(false); // move
			manipulator->loadMagazine(false, true); // load, unload
		}

	}	
	
	void intake(bool autonIntake)
	{
		if(autonIntake)
		{
			manipulator->intakeDisc(true); // intake
			manipulator->conveyer(true); // move
			manipulator->loadMagazine(true, false); // load, unload			
		}
		else
		{
			manipulator->intakeDisc(false); // intake
			manipulator->conveyer(false); // move
			manipulator->loadMagazine(false, true); // load, unload
		}
	
	}	
	
	void shoot(bool isPID)
	{
		if(isPID)
		{
			shooter->setTarget(FULL_SPEED);
			shooter->setVelocity(shooter->pidOutput->readOutput());
			shooter->shootDisc();
		}
		else
		{
			shooter->setVelocity(FULL_SPEED);
			shooter->shootDisc();
		}
		
	}	
	    		
};

START_ROBOT_CLASS(Medic);
