#include "Solution.cpp"

int main()
{
    char mode='0', again='Y';
    int disks;
    Solution sol;
    sol.startingScreen();


    while(again=='Y'||again=='y')
    {
        cout<<"\n1- Automated solving\n"<<"2- User solving\n"<<"Select mode: ";
        cin>>mode;
        sol.printLine();
        switch(mode)
        {
            case '1':
                cout<<"Enter number of disks: ";
                cin>>disks;
                if(disks<=0||disks>15)
                {
                    cout<<"Sorry you enter invalid number of disks\n";
                    break;
                }
                cout<<"Minimum moves = "<<(pow(2,disks)-1)<<endl;
				sol.printLine();
                sol.machineSolve(disks);
                sol.~Solution();
                break;

            case '2':
                cout<<"Enter number of disks: ";
                cin>>disks;
                if(disks<=0||disks>15)
                {
                    cout<<"Sorry you enter invalid number of disks\n";
                    break;
                }
                cout<<"Minimum moves = "<<(pow(2,disks)-1)<<endl;
                sol.printLine();
                try
                    {
                    sol.userSolve(disks);
                    }
                catch(invalid_argument &e)
                    {
                    cout <<e.what() ;
                    }
                sol.~Solution();
                break;

            default:
                cout<<"Select mode error\n";
        }
        sol.printLine();

        cout<<"Do you want to try again Y/N: ";
        cin>>again;
        sol.printLine();
    }
    return 0;
}
