#include "Solution.h"
//destructor
Solution::~Solution()
{
	winning=0, flag=0;

    moveNum=0, diskNum=0,
	arrOne[8]={0}, arrTwo[8]={0}, arrThree[8]={0},
	retOne=0, retTwo=0, retThree=0,
	topOfT1=0, topOfT2=0,
	userMoves=0, fromTower=0, toTower=0, retDisk=0,
	bottomSpace=0, index=0, counter=0,
	diffSpaceOne=0, diffSpaceTwo=0, diffSpaceThree=0, diffSpaceFour=0,
	arrSize=8, base=0, bigSpace=0;
}

//this section is responsible for drawing towers that have less than or equal 8 disks
/**************************************************************************************/
void Solution::drawingTowers(StackLinked<int> &t1,StackLinked<int> &t2,StackLinked<int> &t3,int disks)
{
   	t1.convertToArr(arrOne);
	t2.convertToArr(arrTwo);
	t3.convertToArr(arrThree);

	//temp lines between to comments to display arrays sent to draw function
	/*--------------------------------------------------------------------------
	printLine();
	cout<<"Array one: \n";
	for(index=0;index<8;index++)
		cout<<arrOne[index]<<"\t";
	cout<<endl;

	cout<<"Array two: \n";
	for(index=0;index<8;index++)
		cout<<arrTwo[index]<<"\t";
	cout<<endl;

	cout<<"Array three: \n";
	for(index=0;index<8;index++)
		cout<<arrThree[index]<<"\t";
	cout<<endl;
	printLine();
	--------------------------------------------------------------------------*/
	draw(arrOne,arrTwo,arrThree,disks);
	for(index=0;index<8;index++)
	{
		arrOne[index]=0;
		arrTwo[index]=0;
		arrThree[index]=0;
	}
}

//this section is responsible for displaying towers that have more than 8 disks
/**************************************************************************************/


/**********************************************************************************************
void Solution::enqueueStep(int fromTower,int toTower,QueueLinked <string> &solutionQueue )
{
    ++moveNum;
    string str1 = to_string(moveNum);
    string str2 = to_string(fromTower);
    string str3 = to_string(toTower);
    string step = (str1 + "- Move disk from tower " + str2 + " to tower " + str3);
	//cout<<"\n"<<++moveNum<<"- Move disk from tower "<<fromTower<<" to tower "<<toTower<<"\n";
	solutionQueue.enQueue(step);

}
********************************************************************************/

/***************************************************************************
void Solution::dequeueSteps(QueueLinked <string> &solutionQueue)
 {
    string retEle ;
 	cout<<"dequeue elements from queue\n";
    solutionQueue.deQueue(retEle);
    cout << retEle << endl;

 }

 **************************************************************************/
//this section is responsible for checking end of game
/**************************************************************************************/
bool Solution::checkEmpty(StackLinked<int> &t1,StackLinked<int> &t2)
{
    if(t1.isEmpty()&&t2.isEmpty())
		return 1;
    else
		return 0;
}

//this section is responsible for algorithms of solving
/**************************************************************************************/
void Solution::fromAToB(StackLinked<int> &t1,StackLinked<int> &t2)
{
    retOne=0, retTwo=0;
    t1.getTop(retOne);
    t2.getTop(retTwo);

    if (checkMove (t1,t2))
    {
        t1.pop(retOne);
        t2.push(retOne);
		fromTower=1;
		toTower=2;
    }
    else if (checkMove(t2,t1))
    {
    	t2.pop(retTwo);
        t1.push(retTwo);
		fromTower=2;
		toTower=1;
    }
}

void Solution::fromAToC(StackLinked<int> &t1,StackLinked<int> &t3)
{
    retOne=0, retThree=0;
    t1.getTop(retOne);
    t3.getTop(retThree);

    if (checkMove(t1,t3))
    {
    	t1.pop(retOne);
        t3.push(retOne);
		fromTower=1;
		toTower=3;
    }
    else if (checkMove(t3,t1))
    {
        t3.pop(retThree);
        t1.push(retThree);
		fromTower=3;
		toTower=1;

    }
}

void Solution::fromBToC(StackLinked<int> &t2,StackLinked<int> &t3)
{
    retTwo=0, retThree=0;
    t2.getTop(retTwo);
    t3.getTop(retThree);

    if (checkMove(t2,t3))
    {
    	t2.pop(retTwo);
        t3.push(retTwo);
		fromTower=2;
		toTower=3;
    }
    else if (checkMove(t3,t2))
    {
		t3.pop(retThree);
        t2.push(retThree);
		fromTower=3;
		toTower=2;
    }
}

//this section is responsible for constructing of all methods
/**************************************************************************************/


bool Solution::machineSolve(int &disks)
{
    diskNum=disks;
          /* if disks are even */
			/*
			A ---> B
			A ---> C
			B ---> C
			*/

    if(disks>0)
	{
        while(diskNum>=1)
			t1.push(diskNum--);

		//drawing towers if disks less than or equal 8
		if(disks<=8)
			drawingTowers(t1,t2,t3,disks);

        while(!checkEmpty(t1,t2))
		{
            if(disks%2==0)
			{
                if(checkEmpty(t1,t2)) break;
				fromAToB(t1,t2);
				displayStep(fromTower,toTower);
				if(disks<=8) drawingTowers(t1,t2,t3,disks);


                if(checkEmpty(t1,t2)) break;
                fromAToC(t1,t3);
				displayStep(fromTower,toTower);
				if(disks<=8) drawingTowers(t1,t2,t3,disks);

				if(checkEmpty(t1,t2)) break;
                fromBToC(t2,t3);
				displayStep(fromTower,toTower);
				if(disks<=8) drawingTowers(t1,t2,t3,disks);
            }
            /* if disks are odd */
            /*
				A ---> C
				A ---> B
				B ---> C
            */
			else if(disks%2>0)
			{
                if(checkEmpty(t1,t2)) break;
                fromAToC(t1,t3);
				displayStep(fromTower,toTower);
				if(disks<=8) drawingTowers(t1,t2,t3,disks);

				if(checkEmpty(t1,t2)) break;
                fromAToB(t1,t2);
				displayStep(fromTower,toTower);
				if(disks<=8) drawingTowers(t1,t2,t3,disks);

				if(checkEmpty(t1,t2)) break;
                fromBToC(t2,t3);
				displayStep(fromTower,toTower);
				if(disks<=8) drawingTowers(t1,t2,t3,disks);
            }
        }
    }

	else
		return 0;
}

//return true if movement valid
bool Solution::checkMove(StackLinked<int> &t1,StackLinked<int> &t2)
{
	//topOfT1 represent pop element
	//topOfT2 represent push element
	topOfT1=0, topOfT2=0;
	t1.getTop(topOfT1);
	t2.getTop(topOfT2);

    //special cases
    if(topOfT1==0) return 0; //you can't push zero
	else if(topOfT1>=1&&topOfT2==0) return 1; //push large disk over small disk
	else if (topOfT1 == 0 && topOfT2 == 0 ) return 0 ;

	else if(topOfT1<topOfT2) return 1; //element (pop) less than element that will (push) over it
	else return 0;
}

void Solution::userSolve(int &disks)
{
	winning=0,flag=0;
	diskNum=disks;

	if(disks<=8)
	{
		cout<<"Please note that if you want to stop playing at any time enter 0\n";
		//create first tower and draw it
		while(diskNum>=1)
			t1.push(diskNum--);
		drawingTowers(t1,t2,t3,disks);

		while(!checkEmpty(t1,t2))
		{
			cout<<userMoves<<": Enter move as (FROM TO): ";
			cin>>fromTower>>toTower; cout<<"\a";

			//stop game
			if(fromTower==0||toTower==0)
			{
				cout<<"You stop game\n";
				break;
			}

			else if(fromTower>3||toTower>3||fromTower<0||toTower<0)
			{
				cout<<"No change occurred <typo>\n";
				flag=1;
			}

			//checking validation of movement
			/*probabilities
			(1,1)(2,2)(3,3)
			(1,2)	  (1,3)
			(2,1)	  (2,3)
			(3,1)	  (3,2)
			*/
			else if(fromTower==toTower)
			{
				cout<<"No change occurred <invalid movement>\n";
				flag=1;
			}

			else if(fromTower==1&&toTower==2)
			{
				if(!checkMove(t1,t2))
				{
					cout<<"No change occurred <invalid movement>\n";
					flag=1;
				}
			}

			else if(fromTower==1&&toTower==3)
			{
				if(!checkMove(t1,t3))
				{
					throw invalid_argument("No change occurred <invalid movement>\n");
					flag=1;
				}
			}

			else if(fromTower==2&&toTower==1)
			{
				if(!checkMove(t2,t1))
				{
					throw invalid_argument("No change occurred <invalid movement>\n");
					flag=1;
				}
			}

			else if(fromTower==2&&toTower==3)
			{
				if(!checkMove(t2,t3))
				{
					throw invalid_argument("No change occurred <invalid movement>\n");
					flag=1;
				}
			}

			else if(fromTower==3&&toTower==1)
			{
				if(!checkMove(t3,t1))
				{
					throw invalid_argument("No change occurred <invalid movement>\n");
					flag=1;
				}
			}

			else if(fromTower==3&&toTower==2)
			{
				if(!checkMove(t3,t2))
				{
					throw invalid_argument("No change occurred <invalid movement>\n");
					flag=1;
				}
			}

			if(!flag)
			{
				if(fromTower==1) t1.pop(retDisk);
				else if(fromTower==2) t2.pop(retDisk);
				else if(fromTower==3) t3.pop(retDisk);

				if(toTower==1) t1.push(retDisk);
				else if(toTower==2) t2.push(retDisk);
				else if(toTower==3) t3.push(retDisk);

				userMoves++;
			}

			flag=0;
			retDisk=0;
			drawingTowers(t1,t2,t3,disks);
			if(checkEmpty(t1,t2)) winning=1;
		}
	}

	else
		cout<<"Sorry you enter more than 8 disks or invalid number\n";

	if(winning)
	{
		cout<<"Congratulations! you solve TOWER OF HANOI\nYour moves = "<<userMoves;
		if(userMoves==(pow(2,disks)-1))
			cout<<"\nYou done the best moves\n";
		else
		{
			cout<<"\nDifference between your moves and best moves = "<<userMoves-(pow(2,disks)-1);
			cout<<"\nKeep trying to do the optimal moves\n";
		}
	}
}

void Solution::ascendingOrder(int *&arr,int arrSize)
{
    for(index=0;index<arrSize;index++)
		for(counter=index+1;counter<arrSize;counter++)
			if(arr[counter]<arr[index])
			{
				//swap without temp
				arr[counter]+=arr[index];
				arr[index]=arr[counter]-arr[index];
				arr[counter]-=arr[index];
			}
}

void Solution::drawPeaks(int &bigSpace)
{
	for(counter=0;counter<bigSpace;counter++)
		cout<<" ";
	cout<<"|";

	for(counter=0;counter<bigSpace;counter++)
		cout<<" ";
	cout<<"|";

	for(counter=0;counter<bigSpace;counter++)
		cout<<" ";
	cout<<"|";

	for(counter=0;counter<bigSpace;counter++)
		cout<<" ";
	cout<<endl;
}

void Solution::drawBottoms()
{
	bottomSpace=(screenWidth-(3*8))/4;

	diffSpaceOne=bottomSpace-underEveryBase;
	diffSpaceTwo=bottomSpace-(2*underEveryBase);
	diffSpaceThree=bottomSpace-(2*underEveryBase);
	diffSpaceFour=bottomSpace-underEveryBase;

	//draw first bottom
	for(counter=diffSpaceOne;counter>0;counter--)
		cout<<" ";

	for(counter=underEveryBase;counter>0;counter--)
		cout<<"-";
	cout<<"-";

	for(counter=underEveryBase;counter>0;counter--)
		cout<<"-";

	//draw second bottom
	for(counter=diffSpaceTwo;counter>0;counter--)
		cout<<" ";

	for(counter=underEveryBase;counter>0;counter--)
		cout<<"-";
	cout<<"-";

	for(counter=underEveryBase;counter>0;counter--)
		cout<<"-";

	//draw third bottom
	for(counter=diffSpaceThree;counter>0;counter--)
		cout<<" ";

	for(counter=underEveryBase;counter>0;counter--)
		cout<<"-";
	cout<<"-";

	for(counter=underEveryBase;counter>0;counter--)
		cout<<"-";

	for(counter=diffSpaceFour;counter>0;counter--)
		cout<<" ";
	cout<<endl;
}
/*
void enqueueStep (QueueLinked<string> &solutionQueue)
{
 solutionQueue.enQueue();
}
*/
void Solution::draw(int towerOne[],int towerTwo[],int towerThree[],int diskNumbers)
{
	base=diskNumbers*2,
	bigSpace=(screenWidth-(3*8))/4;

	ascendingOrder(towerOne,diskNumbers);
	ascendingOrder(towerTwo,diskNumbers);
	ascendingOrder(towerThree,diskNumbers);

	drawPeaks(bigSpace);
	drawPeaks(bigSpace);

	/*
	line equation
		bigSpace + diffSpaceOne + towerOne[index] + "|" + towerOne[index] +
		bigSpace + diffSpaceTwo + towerTwo[index] + "|" + towerTwo[index] +
		bigSpace + diffSpaceThree + towerThree[index] + "|" + towerThree[index] +
		bigSpace + diffSpaceFour + newLine
	*/

	for(index=0;index<diskNumbers;index++)
	{
		diffSpaceOne=bigSpace-towerOne[index];
		diffSpaceTwo=bigSpace-(towerOne[index]+towerTwo[index]);
		diffSpaceThree=bigSpace-(towerTwo[index]+towerThree[index]);
		diffSpaceFour=bigSpace-towerThree[index];

		if(towerOne[index]==0&&towerTwo[index]==0&&towerThree[index]==0)
		{
			drawPeaks(bigSpace);
			continue;
		}

		for(counter=0;counter<diffSpaceOne;counter++)
			cout<<" ";

		for(counter=0;counter<towerOne[index];counter++)
			cout<<"*";
		cout<<"|";

		for (counter=0;counter<towerOne[index];counter++)
			cout<<"*";

		for (counter=0;counter<diffSpaceTwo;counter++)
			cout<<" ";

		for(counter=0;counter<towerTwo[index];counter++)
			cout<<"*";
		cout<<"|";

		for(counter=0;counter<towerTwo[index];counter++)
			cout<<"*";

		for(counter=0;counter<diffSpaceThree;counter++)
			cout<<" ";

		for(counter=0;counter<towerThree[index];counter++)
			cout<<"*";
		cout<<"|";

		for(counter=0;counter<towerThree[index];counter++)
			cout<<"*";

		for(counter=0;counter<diffSpaceFour;counter++)
			cout<<" ";
		cout<<endl;
	}
	drawBottoms();
}


//this section is responsible for make full screen
/**************************************************************************************/
void Solution::startingScreen()
{
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
	intro();
}

//this section is responsible for make intro screen
/**************************************************************************************/
void Solution::intro()
{
    cout<<"******************************************************************************************************************************************************************************************************************\n";
    cout<<"******************************************************************************************************************************************************************************************************************\n";
    cout<<"**************************************************************************                                                               *************************************************************************\n";
    cout<<"**************************************************************************               WELCOME TO TOWER OF HANOI GAME                  *************************************************************************\n";
    cout<<"**************************************************************************     DESIGNED BY:                                              *************************************************************************\n";
    cout<<"**************************************************************************     1- MOHAMED SAYED HEMED                                    *************************************************************************\n";
    cout<<"**************************************************************************     2- SHERIF MOSTAFA SAMY                                    *************************************************************************\n";
    cout<<"**************************************************************************                                                               *************************************************************************\n";
    cout<<"**************************************************************************                    CAIRO UNIVERSITY                           *************************************************************************\n";
    cout<<"**************************************************************************                                                               *************************************************************************\n";
    cout<<"******************************************************************************************************************************************************************************************************************\n";
    cout<<"******************************************************************************************************************************************************************************************************************\n";
}

void Solution::printLine()
{
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void display(string ele)
{
    cout<<ele<<endl;
}
