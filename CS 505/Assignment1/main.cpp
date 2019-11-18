#include <iostream>
using namespace std;

class Student
{


public :

    string name ;
    float grade ;

    /* pointer to next Student object */
    Student *next ;

    /* setters */
    void setName(string name) {this->name = name;}
    void setGrade(float grade){this->grade = grade;}
    /* getters */
    string getName() {  return name;    }
    float  getGrade(){  return grade;   }
    /* Insert new student */
    void insertStudent (Student **headStudent ,string studentName , float studentGrade , int studentPosition )
    {

     /* cursor is a temp pointer to reach wanted position */
     Student *cursor = *headStudent;
     /* 
        create new object of type ( Student ) 
        and return its save its address in a pointer to object Student variable
        to allow me to deal with this Student node in the (Heap) 
     */
     Student* newStudent = new Student() ;
     newStudent->setName (studentName);
     newStudent->setGrade(studentGrade);
     newStudent->next = NULL;

     if (studentPosition == 1 )
     {
     *headStudent = newStudent;
     return;
     }

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
        cout <<"student name is " << cursor->name << endl ;
        cout <<"student grade is " << cursor->grade << endl ;
        cout <<"--------------------" << endl ;
        cursor = cursor->next ;
    }
    cout << endl ;
    }
};


int main()
{

    Student *head = new Student() ;
    head->setName("Ali");
    head->setGrade(50);
    head->insertStudent(&head,"Alaa    ",150.0,2);
    head->insertStudent(&head,"Esraa   ",250.0,3);
    head->insertStudent(&head,"ibrahim ",350.0,4);
    head->insertStudent(&head,"Nour  ",100.0,5);
    head->insertStudent(&head,"Dine  ",150.0,6);
    head->insertStudent(&head,"Aliaa ",350.0,7);

    head->printStudentList(head);
    return 0;
}


