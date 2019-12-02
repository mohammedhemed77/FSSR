#include <iostream>
using namespace std ;

#ifndef StackL_H
#define StackL_H

const int stackCapacity = 100 ;

template<class GenericType>
class StackA{
	public :
	StackL(); 						        /* class constructor */
	bool isEmpty()	  const ;	            /* return true if stack is empty */
	bool isFull()     const ;               /* return true if stack reach stackCapacity */
	void top (GenericType &) const ;		/* return element in the top */
	void pop (GenericType &);
    void push(GenericType);

	private:
	GenericType Arr[stackCapacity];
	GenericType mytop ;



};



#endif
