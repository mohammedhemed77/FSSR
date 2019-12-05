#include <iostream>
using namespace std ;

#include <iostream>
using namespace std ; 

#ifndef StackL_H
#define StackL_H

template<class GenericType>
class StackL{
	public :
	StackL(); 						        /* class constructor */
	bool isEmpty()	  const ;	            /* return true if stack is empty */
             
	void top (GenericType &) const ;		/* return element in the top */
	void pop (GenericType &);
        void push(GenericType);

	private:
	
	class Node {
	public: 
        GenericType data ; 
        Node* next; 
	};
	typedef Node* nodePtr;
        nodePtr stackTop ;
  

 };

#endif 