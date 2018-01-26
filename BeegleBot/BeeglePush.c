#pragma config(Motor,  port1,           D1,            tmotorVex393_HBridge, openLoop, reversed)//every other motor reversed, because they are geared together
#pragma config(Motor,  port2,           D2,            tmotorVex393_MC29, openLoop)							//may have to adjust wiring to match
#pragma config(Motor,  port3,           D3,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           D4,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           D5,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           D6,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           D7,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           D8,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           LLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          RLift,         tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Vex_Competition_Includes.c"//gets the vex competition package

void LDrive(int prw)
{
	motor[D1] = motor[D2] = motor[D3] = motor[D4] = prw;
}
void RDrive(int prw)//function to turn on the right drive
{
	motor[D5] = motor[D6] = motor[D7] = motor[D8] = prw;
}
void Lift(int pwr)
{
	motor[LLift] = motor[RLift] = pwr;
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
void lift(int pwr)
{
	Lift(pwr);
}
void GoRobit(int lpwr, int rpwr, int time)
{
	LDrive(lpwr);
	RDrive(rpwr);
	wait1Msec(time);
	LDrive(0);
	RDrive(0);
}
void GoRobit(int liftpwr, int time)
{
	Lift(liftpwr);
	wait1Msec(time);
	Lift(0);
}
void GoRobit(int lpwr, int rpwr, int dtime, int liftpwr, int ltime)
{
	LDrive(lpwr);
	RDrive(rpwr);
	Lift(liftpwr);
	if(dtime<ltime)
	{
		wait1Msec(dtime);
		LDrive(0);
		RDrive(0);
	}
	else if(dtime>ltime)
	{
		wait1Msec(ltime);
		Lift(0);
	}
	else
	{
		wait1Msec(dtime);
		LDrive(0);
		RDrive(0);
		Lift(0);
	}
	if(dtime<ltime)
	{
		wait1Msec(ltime-dtime);
		Lift(0);
	}
	else if(dtime>ltime)
	{
		wait1Msec(dtime-ltime);
		RDrive(0);
		LDrive(0);
	}
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
		arcade(vexRT[Ch3], vexRT[Ch1]);
		if(vexRT[Btn6U])
			Lift(127);
		else if(vexRT[Btn6D])
			Lift(-127);
		else
			Lift(0);
	}
}