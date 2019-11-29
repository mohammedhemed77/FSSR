#include "stack.cpp"

int main()
{

	StackA<int> s1 ;
    int num ;


    try {s1.pop(num);}
    catch(invalid_argument &e) {
    	cout << e.what() << endl << endl ;
    }

    try {s1.top(num);}
    catch(invalid_argument &e)
    {
    	cout << "Exception : " <<e.what() << endl << endl ;
    }
	cout << "top element  = " << num << endl ;


    for (int i = 0 ; i <= 100 ; i++)
    {
    try {s1.push(i);}
    catch(invalid_argument &e)
    {
    	cout << e.what() << endl << endl ;
    }
    }

    try {s1.push(1000);}
    catch(invalid_argument &e)
    {
    	cout  <<e.what() << endl << endl ;
    }





    try {s1.top(num);}
    catch(invalid_argument &e)
    {
    	cout << "Exception : " <<e.what() << endl << endl ;
    }
	cout << "top element  = " << num << endl ;


    try{s1.pop(num);}
	catch(invalid_argument &e)
	{
    	cout <<e.what() << endl << endl ;
    }

    cout << "element pop  = " << num << endl ;

	return 0;
}
