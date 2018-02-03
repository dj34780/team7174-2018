/*
 * drivetrain.h
 *
 *  Created on: Jan 27, 2018
 *      Author: Chad
 */

#include "WPILib.h"
#include <cmath>
#include "ctre/Phoenix.h"

#ifndef SRC_DRIVETRAIN_H_
#define SRC_DRIVETRAIN_H_

#define DRIVE_ENCODER_CONVERSION 1.0 // Needs to be updated

#define DISTANCE_P 0.5
#define DISTANCE_I 0
#define DISTANCE_D 0

#define ANGLE_P 0.5
#define ANGLE_I 0
#define ANGLE_D 0.0

#define LEFT_DRIVE1 14
//#define LEFT_DRIVE2 2
#define RIGHT_DRIVE1 15
//#define RIGHT_DRIVE2 3

#define LEFT_ENCODER 11 // Encoder values need to be updated
#define RIGHT_ENCODER 12

class Drivetrain {
public:
	Drivetrain();
	virtual ~Drivetrain();

	void ArcadeDrive(double speed, double angle);
	void driveForward(double speed);
	void stop();

	double getRawEncoderValues();
	double getLeftEncoder();
	double getRightEncoder();
	double getAverageDistance();
	void setSpeed(double speed);
	void setDistancePIDSpeed(double speed);
private:

	class DistancePIDWrapper : public PIDSource, public PIDOutput {
	public:
		DistancePIDWrapper(Drivetrain* drivetrain);
		virtual ~DistancePIDWrapper();
		double PIDGet() override;
		void PIDWrite(double output) override;
	private:
		Drivetrain* m_drivetrain;
	};

	/*class AnglePIDWrapper : public PIDSource, public PIDOutput {
	public:
		AnglePIDWrapper(Drivetrain* drivetrain);
		virtual ~AnglePIDWrapper();
		double PIDGet() override;
		void PIDWrite(double output) override;
	private:
		Drivetrain* m_drivetrain;
	};*/

	double m_speed;
	double m_turn;

	double distancePIDSpeed = 0.8;
	double distancePIDOutput = 0.0;

	WPI_TalonSRX m_lDrive1;
	//WPI_TalonSRX m_lDrive2;
	WPI_TalonSRX m_rDrive1;
	//WPI_TalonSRX m_rDrive2;

	RobotDrive m_drive;

	Encoder m_lEncoder;
	Encoder m_rEncoder;

	//DistancePIDWrapper m_distancePIDWrapper;
	//AnglePIDWrapper m_anglePIDWrapper;
};

#endif /* SRC_DRIVETRAIN_H_ */
