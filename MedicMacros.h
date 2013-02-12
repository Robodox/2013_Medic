#ifndef MEDIC_MACROS_H
#define MEDIC_MACROS_H

//Digital Sidecar
#define DIGITAL_SIDECAR_SLOT_4					(1)//TODO:dummy number	

//Motors
#define DRIVE_FRONT_LEFT_MOTOR_CHANNEL          (1)//TODO:dummy number
#define DRIVE_REAR_LEFT_MOTOR_CHANNEL           (2)//TODO:dummy number
#define DRIVE_FRONT_RIGHT_MOTOR_CHANNEL         (3)//TODO:dummy number
#define DRIVE_REAR_RIGHT_MOTOR_CHANNEL          (4)//TODO:dummy number
#define ROLLER_VICTOR_CHANNEL					(7)//TODO:dummy number
#define	LOADER_VICTOR_CHANNEL					(8)//TODO:dummy number
#define	CONVEYER_VICTOR_CHANNEL 				(9)//TODO:dummy number
#define SHOOTER_WHEEL_VICTOR_CHANNEL_A			(10)//TODO:dummy number
#define SHOOTER_WHEEL_VICTOR_CHANNEL_B			(11)//TODO:dummy number
#define SHOOTER_WHEEL_IR_CHANNEL				(12)//TODO:dummy number

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
#define AUTO_DRIVE_DEADZONE						(1)//TODO:dummy number
#define AUTO_TURN_DEADZONE						(1) //TODO:dummy number
													//degrees

#define AIM_DEADZONE							(10)
#define TICKS_DEADZONE							(10)


	//INS
#define GYRO_CHANNEL							(1)//TODO:dummy number

	//Pneumatics
#define CLIMBER_SOLENOID_CHANNEL_A				(3)//TODO:dummy number 
#define CLIMBER_SOLENOID_CHANNEL_B				(4)//TODO:dummy number
#define FEEDER_SOLENOID_CHANNEL_A       		(1)//TODO:dummy number
#define FEEDER_SOLENOID_CHANNEL_B       		(2)//TODO:dummy number

//Digitial IO
	//Slots
#define PNUEMATICS_FEEDER_SLOT					(1)//TODO:dummy number
#define PNUEMATICS_CLIMBER_SLOT					(1)//TODO:dummy number
#define ANALOG_BUMPER_SLOT       				(1)//TODO:dummy number
	
   //Encoders
#define LEFT_DRIVE_ENCODER_CHANNEL_A			(4)//TODO:dummy number
#define LEFT_DRIVE_ENCODER_CHANNEL_B			(5)//TODO:dummy number
#define RIGHT_DRIVE_ENCODER_CHANNEL_A		    (6)//TODO:dummy number
#define RIGHT_DRIVE_ENCODER_CHANNEL_B           (7)//TODO:dummy number
#define SHOOTER_ENCODER_CHANNEL_A				(2)//TODO:dummy number
#define SHOOTER_ENCODER_CHANNEL_B       		(3)//TODO:dummy number

	//PID
#define kP                              		(1)//TODO:dummy number
#define kI										(1)//TODO:dummy number
#define kD										(1)//TODO:dummy number


	//Misc
#define SYNC_STATE_OFF          		        (0)
#define DRIVE_BASE_WIDTH			  		    (18.99952)
#define INCHES_PER_TICK                			(0.075398)   // circumference of wheel / total ticks per rev
													//6pi / 250
#define TICKS_PER_DEGREE				   	    (4.398037)   //width wheel to wheel * ticks * DEGREES_TO_RADIANS
												//18.99952 * (250 / (180 * 6))
#define FULL_SPEED 							    (1)
#define REDUCTION							    (.75)

#define DESIRED_VOLTAGE							(11) //max voltage
#define BATTERY_COMPENSATION					(DESIRED_VOLTAGE / oi->getBatteryVoltage())   //

#define SHOOTER_AD_CHANNEL						(1)//TODO:dummy number
#define ANGLE_POT_CHANNEL						(1)//TODO:dummy number
#define SHOOTER_POT_DEGREES_PER_VOLT		    (1)//TODO:dummy number
#define SHOOTER_DEGREES_PER_BIT					(1)//SHOOTER_POT_DEGREES_PER_VOLT * (20v / 4096b)
#define ELEVATION_DEADZONE						(1)//TODO:dummy number
#define SHOOTER_MAX_ELEVATION					(45)//TODO:DUMMY
#define SHOOTER_MIN_ELEVATION					(0)//TODO:DUMMY
#define ELEVATION_SPEED							(1)//TODO:DUMMY
#endif
