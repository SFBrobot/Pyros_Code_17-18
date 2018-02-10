#pragma config(Motor,  port1,           D1,            tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           D2,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           D3,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           D4,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           D5,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           D6,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           D7,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RLift,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          D8,            tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Vex_Competition_Includes.c"//gets the vex competition package

void LDrive(int pwr)
{
	if(pwr > 27)
		motor[D1] = motor[D2] = motor[D3] = motor[D4] = (pwr-27);
	else
		motor[D1] = motor[D2] = motor[D3] = motor[D4] = pwr;
}
void RDrive(int pwr)//function to turn on the right drive
{
	if(pwr>27)
		motor[D5] = motor[D6] = motor[D7] = motor[D8] = (pwr-27);
	else
		motor[D5] = motor[D6] = motor[D7] = motor[D8] = pwr;
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
void auton()
{
	GoRobit(127, 127, 1000);//estimated 5.33 ft/sec for this configuration
	GoRobit(127, 500);//claw out
	GoRobit(127, 127, 300);//forward to grab cone
	GoRobit(-127, 500);//claw in
	GoRobit(127, -127, 500);//turns around
	GoRobit(127, 127, 1250);//back to start
	GoRobit(127, -127, 300);//turns 45^o
	GoRobit(127, 127, 250);//JUMP THE BAR
	GoRobit(127, 500);//CLAW OUT
	GoRobit(-127, -127, 1000);//back out without retracting claw to keep the cone in the 10, and jump the bar
}
void pre_auton()
{

}
task autonomous()
{
	//auton();
}
task usercontrol()
{
	while(true)
	{
		arcade(-vexRT[Ch3], vexRT[Ch4]);
		if(vexRT[Btn6U])
			Lift(100);
		else if(vexRT[Btn6D])
			Lift(-100);
		else
			Lift(0);
		if(vexRT[Btn7U])
			auton();
	}
}
