#include <iostream>
using namespace std;

class Student
{

    public :
    /* student data */
    string name ,phone , address ;
    int code ;
    /* pointer to next Student object */
    Student *next ;

    /* setters */
    void setName()
        {
        cout << "Enter student name : " << endl;
        cin >>  name ;
        }
    void setCode()
        {
        cout << "Enter student code : " << endl;
        cin >>  code ;
        }
    void setAddress(){
        cout << "Enter student address : " << endl;
        cin >>  address ;
        }
    void setphone(){
        cout << "Enter student phone : " << endl;
        cin >>  phone ;
            }
    /* getters */
    string getName()    {  return name;      }
    string getphone()   {  return phone;     }
    string getaddress() {  return address;   }
    int  getCode()      {  return code;      }
    /* Insert new student */
    void insertStudent (Student **headStudent , int studentPosition )
    {

     /* cursor is a temp pointer to reach wanted position */
     Student *cursor = *headStudent;
     /*
        create new object of type ( Student )
        and return its save its address in a pointer to object Student variable
        to allow me to deal with this Student node in the (Heap)
     */
     Student* newStudent = new Student() ;
     newStudent->setName ();
     newStudent->setAddress();
     newStudent->setphone();
     newStudent->setCode();
     newStudent->next = NULL;

     /* if list is empty : */
     if (studentPosition == 1 )
     {
     *headStudent = newStudent;
     return;
     }
    /*
    to reach specific positoin :
    wanted position = (wanted position -1) -> next
    and this for loop ends before i = wanted position -2
    */
    for (int i = 0 ; i<(studentPosition-2);i++)
        {
        cursor = cursor->next ;
        }

        newStudent->next = cursor->next ;
        cursor->next = newStudent ;
    }

    void printStudentList (Student* headStudent)
    {
    Student *cursor = headStudent ;
    cout << "Student list is : " << endl ;
    cout << "-----------------" << endl ;
    while (cursor != NULL)
    {
        cout <<"student name is "     << cursor->getName()    << endl ;
        cout <<"student code is "     << cursor->getCode()     << endl ;
        cout <<"student address is "  << cursor->getaddress() << endl ;
        cout <<"student phone is "    << cursor->getphone() << endl ;
        cout <<"--------------------" << endl ;
        cursor = cursor->next ;
    }
    cout << endl ;
    }
};


int main()
{

    Student *head = NULL ;

    head->insertStudent(&head,1);
    head->insertStudent(&head,2);
    head->insertStudent(&head,3);
    head->insertStudent(&head,4);
    head->insertStudent(&head,5);
    head->insertStudent(&head,6);
    head->insertStudent(&head,7);

    head->printStudentList(head);
    return 0;
}


