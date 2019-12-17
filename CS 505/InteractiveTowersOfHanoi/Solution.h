#ifndef SOLUTION_H
#define SOLUTION_H

#include <windows.h>
#include <cmath>
#include "StackLinked.cpp"
#include "QueueLinked.cpp"
#include <string> 

class Solution
{
public:
	~Solution();
	void intro();
	void printLine();
	void startingScreen();
	bool machineSolve(int &disks);
	void userSolve(int&);
	    

private:
	void fromAToB(StackLinked<int>&,StackLinked<int>&);
	void fromAToC(StackLinked<int>&,StackLinked<int>&);
	void fromBToC(StackLinked<int>&,StackLinked<int>&);

	//void enqueueStep(int fromTower,int toTower,QueueLinked<string>&);
	//void dequeueSteps(QueueLinked<string> &);

	bool checkEmpty(StackLinked<int>&,StackLinked<int>&);
	bool checkMove(StackLinked<int>&,StackLinked<int>&);
	void ascendingOrder(int*&,int);

	void displayStep(int,int);
	void drawingTowers(StackLinked<int>&,StackLinked<int>&,StackLinked<int>&,int);
	void drawPeaks(int&);
	void drawBottoms();
	void draw(int[],int[],int[],int);

	bool winning=0, flag=0;
	int arrOne[8]={0}, arrTwo[8]={0}, arrThree[8]={0},
	moveNum=0, diskNum=0,
	retOne=0, retTwo=0, retThree=0,
	topOfT1=0, topOfT2=0,
	userMoves=0, fromTower=0, toTower=0, retDisk=0,
	bottomSpace=0, index=0, counter=0,
	diffSpaceOne=0, diffSpaceTwo=0, diffSpaceThree=0, diffSpaceFour=0,
	arrSize=8, base=0, bigSpace=0;
	StackLinked<int> t1, t2, t3;
	QueueLinked <string> solutionQueue ;
	enum towerSpecs
	{
		screenWidth=221, underEveryBase=10
	};
};

#endif
