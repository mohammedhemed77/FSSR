#include <iostream>
using namespace std;
const int row = 10 , col = 10; //set size of rows & columns

/* functions prototypes */
/* How to prototype a function with have 2D array parameter using pointer ? */
/*
 we know that name of array returns a pointer to the first element but each element isn't int 
 Each element = 1-D of 10 elements  
 ex : 
 -----
 // creat 10 * 10 array  
 B[10][10] ;  
 
 Type of pointer doesn't matter when you read address , 
 it matters when using pointer arithmetic or derefrencing.  
 
 int *ptr = B ;             // this line will cause compilation error
 
 // a pointer to array of 10 elemnts 
 int (*ptr)[10] = B ;       // correct code 

*/

void fillZeros(int(*)[10] );
void readFromUser(int(*)[10] );
void printArrElements(int(*)[10] );
void sumOfIndividualRows(int(*)[10] );
void smallestElement(int(*)[10] );
int main()
{
    char again='y';
    int selection;
    int arr[row][col];

    while (again == 'y')
    {
        cout << "1. Initialize array to zeros" << endl
             << "2. Fill array" << endl
             << "3. Print array elements" << endl
             << "4. Find the smallest element in array" <<endl
             << "5. Find the sum of each individual row" << endl;

        cout << "Select what you want to do : ";
        cin >> selection;

        switch (selection)
        {
            case 1: fillZeros(arr); break;
            case 2: readFromUser(arr); break;
            case 3: printArrElements(arr); break;
            case 4: smallestElement(arr); break;
            case 5: sumOfIndividualRows(arr); break;
        }
        cout << "Do you want to try again ? y/n ";
        cin >> again;
    }
    return 0;
}



//Initialize array with zeros
void fillZeros(int arr[row][col])
{
    for (int r=0 ; r<row ; r++)
    {
        for (int c=0 ; c<col ; c++)
            arr[r][c]=0;
    }
}

//Read array from the user
void readFromUser(int arr[row][col])
{
    cout << "Enter 100 No. " << endl;
    for (int r=0 ; r<row ; r++)
    {
        for (int c=0 ; c<col ; c++)
            cin >> arr[r][c];
    }
}

//Print array elements
void printArrElements(int arr[row][col])
{
    for (int r=0 ; r<row ; r++)
    {
        for (int c=0 ; c<col ; c++)
            cout << arr[r][c] << " ";
        cout << endl;
    }
}

//Find the smallest element in array
void smallestElement(int arr[row][col])
{
    int smallest=arr[0][0];
    for (int r=0 ; r<row ; r++)
    {
        for (int c=0 ; c<col ; c++)
            if (smallest>=arr[r][c])
                smallest=arr[r][c];
    }
    cout << "The smallest element in array is : " << smallest << endl;
}

//Find the sum of each individual rows
void sumOfIndividualRows(int arr[row][col])
{
    int sumOfIndividualRows=0;
    for (int r=1 ; r<row ; r+=2)
    {
        for (int c=0 ; c<col ; c++)
            sumOfIndividualRows+=arr[r][c];
    }
    cout << "Sum of individual rows = " << sumOfIndividualRows << endl;
}

