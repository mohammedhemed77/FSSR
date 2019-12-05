#include <iostream>
#include <cmath>
using namespace std ; 

int main() {
    const int screenWidth = 100 ; 
       
    
    /* users will send three towers array */
    
    /* the worst case */
    int t2[] =  {0,0,0,4,5};
    int t1[] =  {0,0,1,2,3};
    int t3[] =  {0,0,0,1,2};
    
    int diskNumbers =  5;
    cout << " Disk Numbers = " << diskNumbers << endl ;
    cout << " Minimum Moves = " << (pow(2,diskNumbers) - 1) << endl << endl;  
    
    int s1,s2,s3;
    int base = diskNumbers * 2 ; 
    int bigSpace = (screenWidth - (3 * base)) / 4 ;   
    
    
    for (int i = 0 ; i < diskNumbers ; i++)
    {
    
     
    
    (t1[i] == base/2) ? s1 = 0: s1 = base - (t1[i]*2 % base);
    
    (t2[i] == base/2) ? s2 = 0: s2 = base - (t2[i]*2% base) ;
    
    (t3[i] == base/2) ? s3 = 0: s3 = base - (t3[i]*2% base);
    
    
        
    int x ; 
    for (x = 0 ; x < (bigSpace + s1 ); x++ ) cout << " ";
    
    for (x = 0 ; x < t1[i] ; x++ ) cout << "* " ;     
    
    for (x = 0 ; x < (bigSpace +s2); x++ ) cout << " ";
    for (x = 0 ; x < t2[i] ; x++ ) cout << "* ";
    
    for (x = 0 ; x < (bigSpace +s3); x++ ) cout << " ";
    for (x = 0 ; x < t3[i] ; x++ ) cout << "* ";
    
    for (x = 0 ; x < ( bigSpace ) ; x++ ) cout << " ";
   
    cout << endl ;
    
    }
        
    return 0;
}
    
