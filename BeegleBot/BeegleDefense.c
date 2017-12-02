#pragma config(Sensor, dgtl1,  leftJumper,     sensorDigitalIn)
#pragma config(Motor,  port1,           BLDrive,       tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           FLDrive,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           MLDrive,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LMG,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           RMG,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           MRDrive,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           FRDrive,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          BRDrive,       tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Vex_Competition_Includes.c"

void LDrive(int prw)
{
	motor[BLDrive] = motor[FLDrive] = motor[MLDrive] = prw;
}
void RDrive(int prw)//function to turn on the right drive
{
	motor[BRDrive] = motor[FRDrive] = motor[MRDrive] = prw;
}
void MGIntake(int pwr)
{
	motor[LMG] = motor[RMG] = pwr;
}
//Auton funcs
void goRobit(int pwrL, int pwrR, int time)
{
	LDrive(pwrL);
	RDrive(pwrR);
	wait1Msec(time);
	LDrive(0);
	RDrive(0);
	wait1Msec(20);
}
void goRobit(int pwrL, int pwrR, int time, bool useSideSwitcher)//overloaded function for turning
{
	if(useSideSwitcher && SensorValue[leftJumper])
	{
		pwrR *= -1;
		pwrL *= -1;
	}
	LDrive(pwrL);
	RDrive(pwrR);
	wait1Msec(time);
	LDrive(0);
	RDrive(0);
	wait1Msec(20);
}
void GoMGI(int pwr, int time)
{
	MGIntake(pwr);
	wait1Msec(time);
	MGIntake(0);
	wait1Msec(20);
}
//Driver Control funcs
void arcade(int move, int rot)
{
	LDrive(move + rot);
	RDrive(move - rot);
}
void tank(int pwrL, int pwrR)
{
	LDrive(pwrL);
	RDrive(pwrR);
}
//Autons
//Write all code like it's on the right side of the field
void ForwardAuton()
{
	goRobit(127, 127, 3500);
}
void TwentyPointAuton()
{
	goRobit(127, 127, 2000);
	GoMGI(127, 400);
	goRobit(127, 127, 500);
	GoMGI(-127, 400);//pick up the MG
	goRobit(-127, -127, 2000);//back up near starting
	goRobit(-127, 127, 1000, true);//turn 135 degrees to the left
	goRobit(127, 127, 750);//forward near center of scoring zone
	goRobit(-127, 127, 750, true);//turn 90 degrees to face 20 point zone
	goRobit(127, 127, 2000);//forward to 20 point zone
	GoMGI(127, 400);//drop mobile goal
	goRobit(-127, -127, 2000);//back up
}
//Competition funcs/tasks
void pre_auton(){}
task autonomous()
{
	ForwardAuton();
}
task usercontrol()
{
	while(true)
	{
		arcade(vexRT[Ch3], vexRT[Ch4]);
		if(vexRT[Btn6U])
			MGIntake(127);
		else if(vexRT[Btn6D])
			MGIntake(-127);
		else
			MGIntake(0);
	}
}
