#include <iostream>
#include <cmath>
using namespace std ; 

enum towerSpecs {screenWidth = 201 , underEveryBase = 10}; 

void drawPeaks(int &bigSpace){
        int i ; 
        for (i = 0 ; i < bigSpace ; i++) cout << " "; cout <<"|"; 
        for (i = 0 ; i < bigSpace ; i++) cout << " "; cout <<"|";
        for (i = 0 ; i < bigSpace ; i++) cout << " "; cout <<"|";
        for (i = 0 ; i < bigSpace ; i++) cout << " "; 
        cout << endl ; 

}

void drawBottoms(){
    
    int u = 0 , b = 0  ;
    int bottomSpace  = (screenWidth - (3 * 8)) / 4 ;   
    int s1 ,s2 , s3 , s4 ;
    
    s1 = bottomSpace - underEveryBase;  s2 = bottomSpace - (2 * underEveryBase);  
    s3 = bottomSpace - (2 * underEveryBase);  s4 = bottomSpace -  underEveryBase;    
    
    /* draw first bottom */
    for (b = s1 ; b > 0 ; b --)    cout << " "; 
    for (u = underEveryBase ; u > 0 ; u --) cout << "-"; cout<<"-"; 
    for (u = underEveryBase ; u > 0 ; u --) cout << "-";
            
    /* draw second bottom */
    for (b = s2 ; b > 0 ; b --)    cout << " "; 
    for (u = underEveryBase ; u > 0 ; u --) cout << "-"; cout <<"-";
    for (u = underEveryBase ; u > 0 ; u --) cout << "-";
    
    /* draw third bottom */
    for (b = s3 ; b > 0 ; b --)    cout << " "; 
    for (u = underEveryBase ; u > 0 ; u --) cout << "-"; cout<<"-";
    for (u = underEveryBase ; u > 0 ; u --) cout << "-";

    for (b = s4 ; b > 0 ; b --)    cout << " "; 
    cout << endl ; 
    
}
    int main() {    
        int x = 0;
    /* users will send three towers array */
    
    /* the worst case */
    int t2[] =  {0,0,0,0,0,0,0,0};
    int t1[] =  {1,2,3,4,5,6,7,8};
    int t3[] =  {0,0,0,0,0,0,1,2};
    
    int diskNumbers =  8;
    cout << " Disk Numbers = " << diskNumbers << endl ;
    cout << " Minimum Moves = " << (pow(2,diskNumbers) - 1) << endl << endl;  
    
    int s1,s2,s3,s4,i,j;
    /* to avoid odd numbers multiply by (2) */
    int base = diskNumbers * 2 ;   
   
    int bigSpace = (screenWidth - (3 * diskNumbers)) / 4 ;   
    
    drawPeaks(bigSpace); 
    drawPeaks(bigSpace); 
    
   
    for (i = 0 ; i < diskNumbers ; i++)
    {
    
     
    s1 = bigSpace - t1[i];  s2 = bigSpace - (t1[i] + t2[i]);  s3 = bigSpace - (t2[i] + t3[i]);  s4 = bigSpace -  t3[i];    
    
        
    int x ; 
    for (x = 0 ; x < s1; x++ )       cout << " ";
    for (x = 0 ; x < t1[i] ; x++ )   cout << "*"; cout << "|";
    for (x = 0 ; x < t1[i] ; x++ )   cout << "*";
    
    for (x = 0 ; x < s2; x++ ) cout << " ";
    for (x = 0 ; x < t2[i] ; x++ ) cout << "*";  cout << "|";  
    for (x = 0 ; x < t2[i] ; x++ ) cout << "*";
    
    
    
    for (x = 0 ; x < s3; x++ ) cout << " ";
    for (x = 0 ; x < t3[i] ; x++ ) cout << "*"; cout << "|";
    for (x = 0 ; x < t3[i] ; x++ ) cout << "*"; 
    
    
    for (x = 0 ; x < s4 ; x++ ) cout << " ";
   
    cout << endl ;
    
    }
    
    drawBottoms();
    return 0;
}
    
