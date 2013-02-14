#include "WPILib.h"

#include "MedicDrive.h"
#include "MedicManipulator.h"
#include "MedicOperatorInterface.h"
#include "MedicShooter.h"
#include "MedicPIDOutput.h"
#include "MedicMacros.h"

int step;
//double timerGoal;

class Medic: public IterativeRobot
{
	MedicShooter *shooter;
	MedicManipulator *manipulator;
	MedicOperatorInterface *oi;
	MedicDrive *drive;
	MedicPIDOutput *pidOutput;
	Compressor *comp599;
//	Timer *timer;

public:

	Medic()
	{
		manipulator = new MedicManipulator();
		oi = new MedicOperatorInterface();
		drive = new MedicDrive(oi);
		shooter = new MedicShooter();
		pidOutput = new MedicPIDOutput();
		comp599 = new Compressor(1, 1, 1, 1);//TODO: add real values
		
		oi->dashboard->init();
		comp599->Start();
		

	}
	
	void RobotInit()
	{
		
	}
	
	void DisabledInit()
	{
		drive->leftEncoder->Start();
		drive->rightEncoder->Start();		
	}
	
	void AutonomousInit()
	{
		step = 0;
		drive->leftEncoder->Reset();
		drive->rightEncoder->Reset();
		drive->isAtLinearTarget = false;
	}
	
	void TeleopInit()
	{
		drive->setLinVelocity(0);
		drive->setTurnSpeed(0, false);
		drive->drive();
	}
   
	void TestInit()
	{
		
	}
	
	void DisabledPeriodic()
	{
		step = 0;
		drive->leftEncoder->Reset();
		drive->rightEncoder->Reset();
		drive->isAtTimeLinearTarget = false;
		smartDashboardPrint();

	}
	
	void AutonomousPeriodic()
	{
		//shoot(true);					//shoot preloads
		
		//drive->autoTurn(55, TURN_SPEED); 	
		smartDashboardPrint();

	/*	if(step == 1)
		{
			drive->autoLinear(24, .5);//TODO: dummy number
			if(drive->isAtLinearTarget)
			{
			drive->resetAtTarget();
			step++;
			}
		}
*/		if(step == 0)
		{
			drive->timeLinear(.2, 2000);//TODO: dummy number
			if(drive->isAtTimeLinearTarget)
			{
			  drive->resetAtTarget();
			  step++;
			}
		}
//		drive->autoTurn(-90, TURN_SPEED); 		
//		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 		//get the weirdly angled discs OF DOOM
//		intake(true);					
//		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 		
//		
//		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 
//		drive->autoTurn(55, TURN_SPEED); 		//aim and then shoot discs of doom 
//		shoot(true);	
//	
//		drive->autoTurn(55, TURN_SPEED); 
//		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 
//		drive->autoTurn(-90, TURN_SPEED); 
//		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 		//get OTHER weirdly angled discs of doom
//		intake(true);	
//		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number 
//		
//		drive->autoDrive(1, DRIVE_SPEED);//TODO: dummy number
//		drive->autoTurn(55, TURN_SPEED);			//aim and shoot OTHER weirdly angled discs of doom
//		shoot(true);		
		//like a boss
	}
	
	void TeleopPeriodic()
	{
		  oi->dsLCD->Printf(DriverStationLCD::kUser_Line4, 1, "printing works!1 woot");	
		  oi->dsLCD->UpdateLCD();
		  comp599->Start();
		  while(IsOperatorControl())
		{
			  //if(oi->readAutoAimToggle())
			  //{
			//	  autoAim(oi->readTargetCenterX(), oi->readTargetCenterY());
			  //}
			  //else
			  //{
				  teleDrive();
			//  }
			  oi->dsLCD->Printf(DriverStationLCD::kUser_Line3, 1,  "linearVelocity :%f", drive->getLinVelocity());
			  oi->dsLCD->PrintfLine(DriverStationLCD::kUser_Line1, "Left Encoder %f", drive->leftEncoder->GetRaw());
			  oi->dsLCD->PrintfLine(DriverStationLCD::kUser_Line2, "Right Encoder %f", drive->rightEncoder->GetRaw());
			  oi->dsLCD->UpdateLCD();
		  oi->dashboard->PutNumber("Linear Velocity", drive->getLinVelocity());
		  oi->dashboard->PutNumber("Turn", drive->getTurnSpeed());
		  oi->dashboard->PutNumber("Joy Y", oi->getDriveJoystick()->GetY(Joystick::kRightHand));
		  oi->dashboard->PutNumber("joy X", oi->getDriveJoystick()->GetX(Joystick::kRightHand));
		  oi->dashboard->PutNumber("Left Encoder", drive->leftEncoder->Get());
		  oi->dashboard->PutNumber("Right Encoder", drive->rightEncoder->Get());
		}
	}
	
	void TestPeriodic()
	{
		
	}
	
	void teleDrive()
	{
		drive->setLinVelocity(-oi->getDriveJoystick()->GetY(Joystick::kRightHand));
		drive->setTurnSpeed(oi->getDriveJoystick()->GetX(Joystick::kRightHand), oi->getDriveJoystickButton(1));//TODO: Actual button value needed
		drive->drive();
		drive->shift(oi->getDriveJoystickButton(8), oi->getDriveJoystickButton(9));
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
		}
		else
		{
			manipulator->intakeDisc(false); // intake
			manipulator->conveyer(false); // move
		}

	}	
	
	void intake(bool autonIntake)
	{
		if(autonIntake)
		{
			manipulator->intakeDisc(true); // intake
			manipulator->conveyer(true); // move	
		}
		else
		{
			manipulator->intakeDisc(false); // intake
			manipulator->conveyer(false); // move
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
	
	void autoAim(double targetX, double targetY)
	{
		if(targetX < 320 - AIM_DEADZONE)
		{
			//turn left
			drive->setTurnSpeed(-.3, false);
			drive->drive();
		}
		else if(targetX > 320 + AIM_DEADZONE)
		{
			//turn right
			drive->setTurnSpeed(.3, false);
			drive->drive();
		}
		else
		{
			//stop
			drive->setTurnSpeed(0, false);
			drive->drive();
		}
		if(targetY < 240 - AIM_DEADZONE)
		{
			//aim down
			drive->setLinVelocity(.3);
			drive->drive();
		}
		else if(targetY > 240 + AIM_DEADZONE)
		{
			//aim up
			drive->setLinVelocity(-.3);
			drive->drive();
		}
		else
		{
			//stop
			drive->setLinVelocity(0);
			drive->drive();
		}
	}
	
	void smartDashboardPrint()
	{
		oi->dashboard->PutNumber("Linear Velocity", drive->getLinVelocity());
		oi->dashboard->PutNumber("Left Encoder", drive->leftEncoder->Get());
		oi->dashboard->PutNumber("Right Encoder", drive->rightEncoder->Get());
		oi->dashboard->PutBoolean("isAtTargetD", drive->isAtLinearTarget);
		oi->dashboard->PutNumber("step", step);
		oi->dashboard->PutNumber("currentTicksD", drive->currentTicksLinear);
		oi->dashboard->PutNumber("targetTicksD", drive->targetTicksLinear);
		oi->dashboard->PutNumber("deltaTicksD", drive->deltaTicksLinear);
		oi->dashboard->PutNumber("errorD", drive->errorLinear);
		oi->dashboard->PutNumber("errorDuplicateD", drive->errorLinear);
		
		oi->dashboard->PutNumber("currentTimeD", drive->currentTimeLinear);
		oi->dashboard->PutNumber("targetTimeD", drive->targetTimeLinear);
		oi->dashboard->PutNumber("deltaTimeD", drive->deltaTimeLinear);
		oi->dashboard->PutNumber("errorTimeD", drive->errorTimeLinear);
		
		oi->dashboard->PutNumber("Battery_Voltage", oi->getBatteryVoltage());
		//oi->dashboard->PutNumber("POT_Voltage", manipulator->getShooterAngle());
		
		oi->dashboard->PutBoolean("isAtTargetT", drive->isAtTurnTarget);
		oi->dashboard->PutNumber("currentTicksT", drive->currentTicksTurn);
		oi->dashboard->PutNumber("targetTicksT", drive->targetTicksTurn);
		oi->dashboard->PutNumber("deltaTicksT", drive->deltaTicksTurn);
		oi->dashboard->PutNumber("errorT", drive->errorTurn);
		oi->dashboard->PutNumber("errorDuplicateT", drive->errorTurn);
	}
	    		
};

START_ROBOT_CLASS(Medic);
