#pragma config(Motor,  port1,           BLDrive,       tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           FLDrive,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LMG,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           RMG,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           FStrafe,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           BStrafe,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           FRDrive,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          BRDrive,       tmotorVex393_HBridge, openLoop, reversed)

void LDrive(int prw)
{
	motor[BLDrive] = motor[FLDrive] = prw;
}
void RDrive(int prw)//function to turn on the right drive
{
	motor[BRDrive] = motor[FRDrive] = prw;
}
void MGIntake(int pwr)
{
	motor[LMG] = motor[RMG] = pwr;
}
void Strafe(int pwr)
{
	motor[FStrafe] = motor[BStrafe] = -pwr;
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
void GoMGI(int pwr, int time)
{
	MGIntake(pwr);
	wait1Msec(time);
	MGIntake(0);
	wait1Msec(20);
}
void GoStrafe(int pwr, int time)
{
	Strafe(pwr);
	wait1Msec(time);
	Strafe(0);
	wait1Msec(20);
}
void EmergAuton()
{
	goRobit(127, 127, 1750);
	GoMGI(127, 250);
	goRobit(127, 127, 300);
	GoMGI(-127, 250);
	goRobit(-127, 127, 750);
	goRobit(127, 127, 2250);
	GoMGI(127, 250);
}

task main()
{
	wait1Msec(1000);
	EmergAuton();
}
