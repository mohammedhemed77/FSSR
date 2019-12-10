#include <iostream>
#include <cstdlib>

using namespace std ;
#include "List.cpp"
int main()
{
    List <int ,int  > list1;
    List <int ,int  > list2;
    int element ; 
 
    /* insert 10 elements in the list at first */
    cout << "insert 10 elements in the list at first" << endl;
    for (int i = 1; i <=10 ; i ++)
    list1.insertFirst(i,i);
    
    /* display list elements */
    list1.traverse();
    
    list1.toFirst();
    list2.toFirst();
    while (!list1.atEnd())
    {
     list1.retrieveData(element);
     /* if element is odd */
     /* rand function generates random numbers for the keys */
     if (element %2 != 0) list2.insertAfter(rand(),element); 
     list1.advance();
    }
    list1.toFirst();
    while (!list1.atEnd())
    {
     list1.retrieveData(element);
     /* if element is even */
     /* rand function generates random numbers for the keys */
     if (element %2 == 0) list2.insertAfter(rand(),element);
     list1.advance();
    }
    /* display list 2 after edit the elements */
    list2.traverse();
    
    
    return 0;
}
