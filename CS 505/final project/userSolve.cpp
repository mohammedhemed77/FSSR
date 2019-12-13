//return true if movement valid
bool checkMove(StackLinked<int> &t1,StackLinked<int> &t2)
{
	//topOfT1 represent pop element
	//topOfT2 represent push element
	int topOfT1=0,topOfT2=0;
	t1.getTop(topOfT1);
	t2.getTop(topOfT2);
	
    //special cases
    if(topOfT1==0) return 0; //you can't push zero
	else if(topOfT1>=1&&topOfT2==0) return 1; //push large disk over small disk
        
	else if(topOfT1<topOfT2) return 1; //element (pop) less than element that will (push) over it
	else if(topOfT1>=topOfT2) return 0;
}

void userSolve(int &disks)
{
	bool winning=0,flag=0;
	int diskNum=disks, userMoves=0, fromTower, toTower, retDisk;
	StackLinked<int> t1, t2, t3;
	
	if(disks<=8)
	{
		cout<<"Please note that if you want to stop playing at any time enter 0\n";
		//create first tower and draw it
		while(diskNum>=1)
			t1.push(diskNum--);
		drawingTowers(t1,t2,t3,disks);
		
		while(!checkEmpty(t1,t2))
		{
			cout<<"Enter move as (FROM TO): ";
			cin>>fromTower>>toTower;
			
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
					cout<<"No change occurred <invalid movement>\n";
					flag=1;
				}
			}

			else if(fromTower==2&&toTower==1)
			{
				if(!checkMove(t2,t1))
				{
					cout<<"No change occurred <invalid movement>\n";
					flag=1;
				}
			}

			else if(fromTower==2&&toTower==3)
			{
				if(!checkMove(t2,t3))
				{
					cout<<"No change occurred <invalid movement>\n";
					flag=1;
				}
			}
			
			else if(fromTower==3&&toTower==1)
			{
				if(!checkMove(t3,t1))
				{
					cout<<"No change occurred <invalid movement>\n";
					flag=1;
				}
			}

			else if(fromTower==3&&toTower==2)
			{
				if(!checkMove(t3,t2))
				{
					cout<<"No change occurred <invalid movement>\n";
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
			cout<<"\nCongratulations! You done the best moves\n";
		else
		{
			cout<<"\nDifference between your moves and best moves = "<<userMoves-(pow(2,disks)-1);
			cout<<"\nDon't worry you can try again to do the best moves\n";
		}
	}
}