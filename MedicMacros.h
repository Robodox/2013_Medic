#ifndef MEDIC_MACROS_H
#define MEDIC_MACROS_H

//Digital Sidecar
#define DIGITAL_SIDECAR_SLOT_4					(1)//dummy number //like a boss	

//Motors
#define DRIVE_FRONT_LEFT_MOTOR_CHANNEL          (1)
#define DRIVE_REAR_LEFT_MOTOR_CHANNEL           (2)
#define DRIVE_FRONT_RIGHT_MOTOR_CHANNEL         (3)
#define DRIVE_REAR_RIGHT_MOTOR_CHANNEL          (4)
#define CLIMBER_VICTOR_CHANNEL_A				(5)//TODO: Change to Solenoids
#define CLIMBER_VICTOR_CHANNEL_B				(6)//TODO: Change to Solenoids
#define ROLLER_VICTOR_CHANNEL					(7)
#define	LOADER_VICTOR_CHANNEL					(8)
#define	CONVEYER_VICTOR_CHANNEL 				(9)
#define SHOOTER_WHEEL_VICTOR_CHANNEL			(10)//dummy number

//Manipulator
#define LOADER_UP               	            (-1)
#define LOADER_DOWN     		                (1)
#define LOADER_OFF                  	        (0)
#define CONVEYER_MOVE							(1)
#define CONVEYER_STOP							(0)
#define INTAKE_MOVE								(1)
#define INTAKE_STOP								(0)

	//Drive
#define DRIVE_SPEED						        (1) //TODO: dummy number
#define TURN_SPEED						        (1) //TODO: dummy number
#define AUTO_DRIVE_DEADZONE						(1)
#define AUTO_TURN_DEADZONE						(1) //degrees

#define AIM_DEADZONE							(10)


	//INS
#define GYRO_CHANNEL							(1)//dummy number

	//Pneumatics
#define CLIMBER_A_MOVE							(1)
#define CLIMBER_B_MOVE							(1)
#define CLIMBER_A_STOP							(0)
#define CLIMBER_B_STOP							(0)
#define FEEDER_SOLENOID_CHANNEL_A       		(1)//dummy number
#define FEEDER_SOLENOID_CHANNEL_B       		(2)//dummy number

//Digitial IO
	//Slots
#define PNUEMATICS_FEEDER_SLOT					(1)//dummy number
#define ANALOG_BUMPER_SLOT       				(1)//dummy number
   //Encoders
#define LEFT_DRIVE_ENCODER_CHANNEL_A			(4)
#define LEFT_DRIVE_ENCODER_CHANNEL_B			(5)
#define RIGHT_DRIVE_ENCODER_CHANNEL_A		    (6)
#define RIGHT_DRIVE_ENCODER_CHANNEL_B           (7)
#define CLIMBER_ENCODER_A						(8)//dummy number
#define CLIMBER_ENCODER_B						(9)//dummy number
#define SHOOTER_ENCODER_CHANNEL_A				(2)
#define SHOOTER_ENCODER_CHANNEL_B       		(3)

	//PID
#define kP                              		(1)
#define kI										(1)
#define kD										(1)


	//Misc
#define SYNC_STATE_OFF          		        (0)
#define DRIVE_BASE_WIDTH			  		    (18.99952)
#define INCHES_PER_TICK                			(0.075398)   // circumference of wheel / total ticks per rev
													//6pi / 250
#define TICKS_PER_DEGREE				   	    (4.398037)   //width wheel to wheel * ticks * DEGREES_TO_RADIANS
												//18.99952 * (250 / (180 * 6))
#define FULL_SPEED 							    (1)
#define REDUCTION							    (.75)


#endif
