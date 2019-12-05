#include "StackL.cpp"

int main() {
/* create stack of type int */
StackL <int>    intStack ;
/* create stack of type float */
StackL <float>  floatStack;


int i = 0 ; 

floatStack.isEmpty()? cout << "floatStack is empty" << endl : cout << "floatStack isn't empty" << endl ;

intStack.isEmpty()? cout << "intStack is empty" << endl : cout << "inttStack isn't empty" << endl ;

    
    int intNum ;
    float floatNum; 
    
    /* try to use top method while stack is empty */ 
    try { floatStack.top(floatNum); } 
    catch(invalid_argument &e)   {cout << e.what() << endl << endl ;}

    try{intStack.top(intNum);} 
    catch(invalid_argument &e)   {cout << e.what() << endl << endl ;}
    
    
    /* push without try catch , as the linked list unlimited */
    for (i  = 0 ; i < 10 ; i++ )  intStack.push(i); 
    for (i = 0 ; i < 10 ; i++)     floatStack.push(i*0.5);

    /*try to pop element and catch error if no top element */
    for (i = 0 ; i < 10 ; i ++)
    {
    try{floatStack.pop(floatNum);    cout << "Element poped  = " << floatNum << endl ;}
    catch(invalid_argument &e) { cout << e.what() << endl << endl; }
    }
    
    /* check if stack is empty or not ? */
    floatStack.isEmpty()? cout << "floatStack is empty" << endl : cout << "floatStack isn't empty" << endl ;
    intStack.isEmpty()? cout << "intStack is empty" << endl : cout << "inttStack isn't empty" << endl ;



    return 0 ; 
}
