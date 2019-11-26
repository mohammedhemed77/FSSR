#include "List.cpp"
int main()
{
    List <int ,int > list1;
       /* insert 10 elements in the list at first */
    cout << "insert 10 elements in the list at first" << endl;

    for (int i = 1; i <=10 ; i ++)
        list1.insertFirst(i,i*10);
    /* display list elements */
    list1.traverse();

    cout << "insert after element 2 " << endl;
    list1.insertAfter(2,1000);
    list1.traverse();

    //list1.insertAfter()
    return 0;
}
