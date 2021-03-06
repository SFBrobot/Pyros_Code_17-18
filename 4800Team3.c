#pragma config(Motor,  port1,           FLWheel,       tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           BLWheel,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           URLift,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           ULLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           BRLift,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           BLLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           FRWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          BRWheel,       tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Vex_Competition_Includes.c"

void LDrive(int prw)
{
	motor[FLWheel] = motor[BLWheel] = prw;
}
void RDrive(int prw)//function to turn on the right drive
{
	motor[FRWheel] = motor[BRWheel] = prw;
}
void UpperLift(int pwr)//function for the lift
{
	motor[BLLift] = motor[BRLift] = pwr;
}
void LowerLift(int pwr)
{
	motor[ULLift] = motor[URLift] = pwr;
}
void claw(int pwr)
{
	motor[Claw] = pwr;
}
void goRobit(int pwrR, int pwrL, int time)
{
	LDrive(pwrL);
	RDrive(pwrR);
	wait1Msec(time);
	LDrive(0);
	RDrive(0);
}
void goLowerLift(int pwr, int time)
{
	LowerLift(pwr);
	wait1Msec(time);
	LowerLift(0);
}
void goUpperLift(int pwr, int time)
{
	UpperLift(pwr);
	wait1Msec(time);
	UpperLift(0);
}
void goClaw(int pwr, int time)
{
	claw(pwr);
	wait1Msec(time);
	claw(0);
}
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

void pre_auton()
{

}

task autonomous()
{

}

task usercontrol()
{
	while(true)
	{
		if (vexRT[Btn6D] != 0)//lower lift control, btn 6
			LowerLift(-127);
		else if (vexRT[Btn6U] != 0)
			LowerLift(127);
		else
			LowerLift(0);
		if (vexRT[Btn5U] != 0)//Upper Lift control, btn 5
			UpperLift(-127);
		else if (vexRT[Btn5D] != 0)
			UpperLift(127);
		else
			UpperLift(0);
		claw(-vexRT[Ch4]);
		arcade(vexRT[Ch2], vexRT[Ch1]);
	}
}
