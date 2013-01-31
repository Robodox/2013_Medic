#ifndef MEDIC_MACROS_H
#define MEDIC_MACROS_H

//Digital IO
#define SHOOTER_ENCODER_CHANNEL_A		(1)
#define SHOOTER_ENCODER_CHANNEL_B       (1)
//Channels
	//Manipulator
#define ROLLER_VICTOR_CHANNEL			(1)
#define	LOADER_VICTOR_CHANNEL			(1)
#define	CONVEYER_VICTOR_CHANNEL 		(1)
#define CLIMBER_VICTOR_CHANNEL_A		(1)//dummy number
#define CLIMBER_VICTOR_CHANNEL_B		(1)//dummy number
#define FEEDER_SOLENOID_CHANNEL_A       (1)//dummy number
#define FEEDER_SOLENOID_CHANNEL_B       (1)//dummy number
#define CLIMBER_ENCODER_A				(1)//dummy number
#define CLIMBER_ENCODER_B				(1)//dummy number
	//Shooter
#define SHOOTER_WHEEL_VICTOR_CHANNEL	(1)//dummy number

//Manipulator
	//Intake
#define INTAKE_MOVE						(1)
#define INTAKE_STOP						(0)

	//Conveyer
#define CONVEYER_MOVE					(1)
#define CONVEYER_STOP					(0)

	//Loader
#define LOADER_DOWN                     (1)
#define LOADER_UP                       (-1)
#define LOADER_OFF                      (0)

	//Climber
#define CLIMBER_A_MOVE							(1)
#define CLIMBER_B_MOVE							(1)
#define CLIMBER_A_STOP							(0)
#define CLIMBER_B_STOP							(0)

//Drive
#define DRIVE_SPEED						    (1) //TODO: dummy number
#define TURN_SPEED						    (1) //TODO: dummy number

// PID
#define kP                              (1)
#define kI								(1)
#define kD								(1)

//Slots
#define PNUEMATICS_FEEDER_SLOT			(1)//dummy number

//  Misc
#define SYNC_STATE_OFF                 (0)
#define INCHES_PER_TICK                (0.075398)   // 6pi / 250
#define TICKS_PER_DEGREE			   (4.398037)   //18.99952 * (250 / (180 * 6))
#define FULL_SPEED 					   (1)


#endif
