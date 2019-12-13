#include "draw.cpp"
int moveNum=1;
//this section is responsible for drawing towers that have less than or equal 8 disks
/**************************************************************************************/
int arrOne[8]={0},indexOne=0,
	arrTwo[8]={0},indexTwo=0,
	arrThree[8]={0},indexThree=0;

void insertIntoArrOne(int ele)
{
	arrOne[indexOne++]=ele;
}

void insertIntoArrTwo(int ele)
{
	arrTwo[indexTwo++]=ele;
}

void insertIntoArrThree(int ele)
{
	arrThree[indexThree++]=ele;
}

void drawingTowers(StackLinked<int> &t1,StackLinked<int> &t2,StackLinked<int> &t3,int disks)
{
	t1.traverse(&insertIntoArrOne);
	t2.traverse(&insertIntoArrTwo);
	t3.traverse(&insertIntoArrThree);

	indexOne=0;indexTwo=0;indexThree=0;

	//temp lines between to comments to display arrays sent to draw function
	//--------------------------------------------------------------------------
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"Array one: \n";
	for(int i=0;i<8;i++)
		cout<<arrOne[i]<<"\t";
	cout<<endl;

	cout<<"Array two: \n";
	for(int i=0;i<8;i++)
		cout<<arrTwo[i]<<"\t";
	cout<<endl;

	cout<<"Array three: \n";
	for(int i=0;i<8;i++)
		cout<<arrThree[i]<<"\t";
	cout<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	//--------------------------------------------------------------------------
	draw(arrOne,arrTwo,arrThree,disks);
	for(int i=0;i<8;i++)
	{
		arrOne[i]=0;
		arrTwo[i]=0;
		arrThree[i]=0;
	}
}

//this section is responsible for displaying towers that have more than 8 disks
/**************************************************************************************/
void displayTowers(int fromTower,int toTower) {
	cout<<moveNum<<"- Move disk from tower "<<fromTower<<" to tower "<<toTower<<"\n";
	moveNum++;
}

//this section is responsible for checking end of game
/**************************************************************************************/
bool checkEmpty(StackLinked<int> &t1, StackLinked<int> &t2) {
    if (t1.isEmpty() && t2.isEmpty()) return 1;
    else return 0;
}

//this section is responsible for algorithms of solving
/**************************************************************************************/
void fromAToB(StackLinked<int> &t1, StackLinked<int> &t2) {
    int retOne = 0, retTwo = 0;
    t1.getTop(retOne);
    t2.getTop(retTwo);

    if (retOne == 0 && retTwo == 0)
        return;
    else if (t1.isEmpty()) {
        t2.pop(retTwo);
        t1.push(retTwo);
    } else if (t2.isEmpty()) {
        t1.pop(retOne);
        t2.push(retOne);
    } else if (retOne < retTwo) {
        t1.pop(retOne);
        t2.push(retOne);
    } else if (retTwo < retOne) {
        t2.pop(retTwo);
        t1.push(retTwo);
    }
}

void fromAToC(StackLinked<int> &t1, StackLinked<int> &t3) {
    int retOne = 0, retThree = 0;
    t1.getTop(retOne);
    t3.getTop(retThree);

    if (retOne == 0 && retThree == 0)
        return;
    else if (t1.isEmpty()) {
        t3.pop(retThree);
        t1.push(retThree);
    } else if (t3.isEmpty()) {
        t1.pop(retOne);
        t3.push(retOne);
    } else if (retOne < retThree) {
        t1.pop(retOne);
        t3.push(retOne);
    } else if (retThree < retOne) {
        t3.pop(retThree);
        t1.push(retThree);
    }
}

void fromBToC(StackLinked<int> &t2, StackLinked<int> &t3) {
    int retTwo = 0, retThree = 0;
    t2.getTop(retTwo);
    t3.getTop(retThree);

    if (retTwo == 0 && retThree == 0)
        return;
    else if (t2.isEmpty()) {
        t3.pop(retThree);
        t2.push(retThree);
    } else if (t3.isEmpty()) {
        t2.pop(retTwo);
        t3.push(retTwo);
    } else if (retTwo < retThree) {
        t2.pop(retTwo);
        t3.push(retTwo);
    } else if (retThree < retTwo) {
        t3.pop(retThree);
        t2.push(retThree);
    }
}

//this section is responsible for construction of all previous functions
/**************************************************************************************/
bool machineSolve(int &disks) {
    int diskNum = disks;
    StackLinked<int> t1, t2, t3;

    if (disks > 0) {
        while (diskNum >= 1) t1.push(diskNum--);
		
		//drawing towers if disks less than or equal 8
		if (disks <= 8)
		{
			drawingTowers(t1,t2,t3,disks);
			cout<<"\n";
		}

        while (!checkEmpty(t1,t2)) {
            if (disks % 2 == 0) {
                if (checkEmpty(t1,t2)) break;
                fromAToB(t1, t2);
				displayTowers(1,2);
				if (disks <= 8) drawingTowers(t1,t2,t3,disks);

                if (checkEmpty(t1,t2)) break;
                fromAToC(t1, t3);
				displayTowers(1,3);
				if (disks <= 8) drawingTowers(t1,t2,t3,disks);

				if (checkEmpty(t1,t2)) break;
                fromBToC(t2, t3);
				displayTowers(2,3);
				if (disks <= 8) drawingTowers(t1,t2,t3,disks);

            } else if (disks % 2 > 0) {
                if (checkEmpty(t1,t2)) break;
                fromAToC(t1, t3);
				displayTowers(1,3);
				if (disks <= 8) drawingTowers(t1,t2,t3,disks);

				if (checkEmpty(t1,t2)) break;
                fromAToB(t1, t2);
				displayTowers(1,2);
				if (disks <= 8) drawingTowers(t1,t2,t3,disks);

				if (checkEmpty(t1,t2)) break;
                fromBToC(t2, t3);
				displayTowers(2,3);
				if (disks <= 8) drawingTowers(t1,t2,t3,disks);
            }
        }
		moveNum=1;
    } else return 0;
}
