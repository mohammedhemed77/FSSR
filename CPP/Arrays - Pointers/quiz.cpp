#include <iostream>
using namespace std;
void multiplicationTable (int );
void printArray (int*, int );
void insertElements (int * , int );
bool isExist (int *, int , int );
int main()
{
    int arr[7];
    int element ;
    //multiplicationTable (1);
    insertElements (arr ,sizeof(arr));
    printArray(arr ,sizeof(arr));
    cout << "search for elemnt : " << endl;
    cin >> element ;
    isExist (arr,sizeof(arr) , element)? cout << "Element exist" << endl : cout << "Element not exist"<< endl ;
    return 0;
}


void multiplicationTable (int num)
{
for (int x = 1 ; x <=12 ; x++)
cout << num <<"*"<<x << "="<< num*x << " ";
}


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

void printArray (int *arr , int arrSize)
{

    for (int i = 0 ; i <= ((arrSize/sizeof(int))-1); i++)
    {
    cout << "arr[" <<i << "] =" << *(arr+i) << endl ;
    }

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
