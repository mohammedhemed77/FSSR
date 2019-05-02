#include <iostream>
using namespace std;
const int row = 10 , col = 10; //set size of rows & columns

void fillArrayWithZeros (int(*)[10] );
void insertElements(int(*)[10] );
void printArray(int(*)[10] );
void sumOfRows(int(*)[10] );
void smallestElement(int(*)[10] );

int main()
{
    int arr[10][10];
    fillArrayWithZeros (arr);
    printArray(arr);
    insertElements (arr);
    printArray(arr);
    sumOfRows (arr);
    smallestElement (arr);

    return 0;
}


void fillArrayWithZeros(int arr[row][col])
{
    for (int r=0 ; r<row ; r++)
    {
        for (int c=0 ; c<col ; c++)
            arr[r][c]=0;
    }
}


void insertElements(int arr[row][col])
{
    cout << "Enter 100 No. " << endl;
    for (int r=0 ; r<row ; r++)
    {
        for (int c=0 ; c<col ; c++)
            cin >> arr[r][c];
    }
}

void printArray(int arr[row][col])
{
    for (int r=0 ; r<row ; r++)
    {
        for (int c=0 ; c<col ; c++)
            cout << arr[r][c] << " ";
        cout << endl;
    }
}

void smallestElement(int arr[row][col])
{
    int smallest=arr[0][0];
    for (int r=0 ; r<row ; r++)
    {
        for (int c=0 ; c<col ; c++)
            if (smallest>=arr[r][c]) smallest=arr[r][c];
    }
    cout << "smallest element = " << smallest << endl;
}

void sumOfRows(int arr[row][col])
{
    int sum = 0;
    for (int r=0 ; r<row ; r++)
    {   sum = 0 ;
        for (int c=0 ; c<col ; c++)sum = sum + (arr[r][c]);
        cout << "Sum of individual row = " << sum << endl;
    }
}
