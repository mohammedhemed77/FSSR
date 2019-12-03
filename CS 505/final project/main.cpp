#include <iostream>
#include <cmath>
using namespace std ; 

int main() {
    const int screenWidth = 120 ; 
       
    
    /* users will send three towers array */
    int t1[] =  {1,2,3,4,5,6,7,8};
    int t2[] =  {8,7,6,5,4,3,2,1};
    int t3[] =  {1,2,3,4,5,6,7,8};
    
    int diskNumbers = sizeof(t1)/sizeof(int) ;
    cout << " Disk Numbers = " << diskNumbers << endl ;
    cout << " Minimum Moves = " << (pow(2,diskNumbers) - 1) << endl;  
    
    
    int s1,s2,s3;
    int base = diskNumbers * 2 ; 
    int bigSpace = (screenWidth - (3 * base)) / 4 ;   
    
     
    for (int i = 0 ; i < diskNumbers ; i++)
    {
    
    (t1[i] % base  == 0) ? s1 = (t1[i]% base): s1 = base - (t1[i] % base);
    
    (t2[i] % base  == 0) ? s2 = (t2[i]% base): s2 = base - (t2[i] % base);
    
    (t3[i] % base  == 0) ? s3 = (t3[i]% base): s3 = base - (t3[i] % base);
    
    if (t1[i]<=t2[i]) s2 -= t1[i] % t2[i];   
    else s2 += t1[i] % t2[i];
    if (t2[i]<=t3[i]) s3 -= t2[i] % t3[i];
    int x ; 
    for (x = 0 ; x < (bigSpace + s1); x++ ) cout << " ";
    //for (x = 0 ; x < s1 ; x++ ) cout << " ";
    for (x = 0 ; x < t1[i] ; x++ ) cout << "* ";
    
    for (x = 0 ; x < (bigSpace + s2 ); x++ ) cout << " ";
    //for (x = 0 ; x < s2 ; x++ ) cout << " ";
    for (x = 0 ; x < t2[i] ; x++ ) cout << "* ";
    
    for (x = 0 ; x < (bigSpace + s3 ); x++ ) cout << " ";
    //for (x = 0 ; x < s3 ; x++ ) cout << " ";
    for (x = 0 ; x < t3[i] ; x++ ) cout << "* ";
    
    for (x = 0 ; x < bigSpace ; x++ ) cout << " ";
   
    cout << endl ;
    
    }
        
    return 0;
}



/* 
    s2 = base - (t2[i] % base) ;
    s3 = base - (t3[i] % base) ;
    */
     
    
    /*
    cout << "s1 = " << s1  << endl ; 
    cout << "s2 = " << s2  << endl ;
    cout << "s3 = " << s3  << endl ;
    cout << "bigSpace = " << bigSpace << endl ;
    */
    
    
