#include <iostream>
#include <ctype.h>
/* This code to add some features to Arrays */
/* ************************************ ************* */

/* * Check if Array is out of bound whatever its type */
/* * count character of any string */

/* By : Mohammed Hemed *************/
using namespace std;
#define SIZE   20
#define MAX_SIZE 1000


class ArrayFeatures {

public :


const int row = 3 ;
const int col = 3;
/* This function return the length of a string */
int stringLength (char *c)
{
 int n ;
 /* for loop is empty */
 for (n = 0 ; *c != '\0'; c++,n++) ;
 return n;

};
/* check if two arrays could be added - Subtarcted - divided */
bool IsOperationValid (int aRows, int aCols, int bRows , int bCols)
{
if ((aRows == bRows)&&(aCols == bCols)) return true ;
else return false ;
}

/* Array outOfBound Checking */
bool IsOutOfBound (int *arr,int arrSize ,int index)
{

if ((index <= (arrSize / (sizeof (int))-1)) && (index >= 0 ))
    return false ;
else return true ;

}

/* overloading */
/* Array outOfBound Checking but it takes char arrays */
bool IsOutOfBound (char *arr, int arrSize,int index)
{

if ((index <= (arrSize / (sizeof (char))-1)) && (index >= 0 ))
    return false ;
else return true ;
}

/* overloading */
/* Array outOfBound Checking but it takes double arrays */
bool IsOutOfBound (double *arr, int arrSize ,int index)
{
if ((index <= (arrSize / (sizeof (double))-1)) && (index >= 0 ))
    return false ;
else return true ;
}
/* print array content */
void printArray(int*arr, int arrSize)
{
for (int i=0; i<=(arrSize/sizeof(int)-1); i++)
    cout << "arr["<<i<<"] = " << *(arr +i) << endl ;
}

void printArray(char*arr , int arrSize)
{
for (int i=0 ; i<= (arrSize / sizeof(char) -1); i++)
cout << "arr["<<i<<"] = " << *(arr +i)<< endl ;
}
void printArray(double *arr , int arrSize)
{
for (int i=0; i<= (arrSize / sizeof(double) -1) ;i++)
cout << "arr["<<i<<"] = " << *(arr +i)<< endl ;
}

/* insert elements of multi-dimensional array */
void insertElements(int rows , int cols)
{
    cout << "Enter  " << rows * cols << " numbers" << endl;
    /* create rows of array */
    int **arr = new int* [rows];
    for (int r=0 ; r<rows ; r++)
    {
        /* create columns of array */
        arr[r]= new int[cols];
    }

    for (int r=0 ; r<rows ; r++)
    {
        for (int c=0 ; c<cols ; c++)
            cin >> arr[r][c];
    }
    cout << " Array [" <<rows<< "]["<<cols<<"]"<<" = " << endl << endl;
    ArrayFeatures ::printArray(arr,rows,cols);
}


void printArray(int **arr , int rows,int cols )
{

    for (int r=0 ; r<rows ; r++)
    {
        for (int c=0 ; c<cols ; c++)  cout << arr[r][c] << "  ";
        cout << endl;
    }
}
/*
void addTwoArrays (int aSize,int bSize)
{
    int *A = new int [MAX_SIZE];
    *A = new int [aSize];
   // int *B = new int [aSize][bSize];

    //int *result  = new int [aSize][bSize];

    for (int r=0 ; r<row ; r++)
    {
        for (int c=0 ; c<col ; c++)
           result [r][c] = a[r][c] +b[r][c];
    }
    cout << "A + B = "  << endl ;
    ArrayFeatures::printArray(result);
}
*/
void insertElements (int *arr , int arrSize )
{
    int arrayElements = (arrSize/sizeof(int)-1);
    cout << "please insert " << arrayElements +1 <<" Elemnts " << endl ;
    int input ;
    for (int i = 0 ; i <= arrayElements; i++)
    {
    cin >> input ;
    *(arr+i)= input ;
    }
    cout << "ok . Array is full" <<endl ;
}



bool isExist (int *arr , int arrSize , int element)
{
    bool exist ;
    for (int i = 0 ; i <= ((arrSize/sizeof(int))-1); i++)
    {
    if ((*(arr+i)) == element) exist = true ;
    else exist = false ;
    }
    return exist ;
}

};



int main()
{
    // declare array :
    int **arr ;
    int arr1[] = {10,60,7000,100,80,60,30};
    int arr2[7] = {10,60,7000,100,80,60,30};
    int arr3[SIZE];

    double doubleArr []= {10.5 , 50.0 , 60 , 10,9};
    char charArr[]= {'1','2','3','4','5','6','8','9'};
    char *myStr = "hemed";

    /* an object of arrayFeatures */
    ArrayFeatures myArray = ArrayFeatures();
    int **ptr ;
    int A[3][3];
    int B[3][3];

    myArray.insertElements(4,8);

    /*
    myArray.insertElements(B);
    myArray.printArray(A);
    myArray.printArray(B);
    myArray.IsOperationValid(3,3,3,3)? cout << "adding A + B is valid" << endl : cout << "invalid operation" << endl ;
    myArray.addTwoArrays(A,B);
    cout << "size of A = " << sizeof (A) << endl ;
    */

    /* Test  arrayOutOfBound checking function

    cout <<"\t"<<"Test  arrayOutOfBound checking function" << endl ;
    cout <<"-----------------------------------------" << endl;
    cout <<"Is int array out of Bound " << endl ;
    myArray.IsOutOfBound(arr1,sizeof(arr1),7) ? cout << "true" <<endl: cout << "false" << endl ;
    cout <<"Is double array out of Bound " << endl ;
    myArray.IsOutOfBound(doubleArr,sizeof(doubleArr),10) ? cout << "true" <<endl: cout << "false" << endl ;
    cout <<"Is char array out of Bound " << endl ;
    myArray.IsOutOfBound(charArr,sizeof(charArr),4) ? cout << "true"<<endl: cout << "false" << endl ;


    /* Test stringlen function ()
    cout <<"\t"<<"Test stringlen function " <<endl;
    cout <<"-----------------------------------------" << endl;
    cout << "string length = "<< myArray.stringLength(myStr) << endl;
    cout << "string length = "<< myArray.stringLength("123456789") << endl<< endl ;

    /* Test printArray
    cout <<"\t"<<"Test printArray function " << endl ;
    cout <<"-----------------------------------------" << endl;
    cout << "int array: "    << endl ;
    myArray.printArray(arr1,sizeof(arr1));
    cout << "char array: "   << endl ;
    myArray.printArray(charArr,sizeof(charArr));
    cout << "double array:"  << endl ;
    myArray.printArray(doubleArr,sizeof(doubleArr)) ;
    return 0 ;

    */





}


