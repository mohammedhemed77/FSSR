/* ORDERD LIST header file  */
/* Author : Mohammed sayed hemed */
#include <iostream>
#include <cstdlib>
using namespace std ;
#ifndef 	LIST_H
#define 	LIST_H

typedef unsigned int uint;

template <class dataType , class keyType>
class List {

public:
	/* to avoid traversing the whole list to know the length */
	/* so : traverse process = O(1) instead of O(n) */
	uint NodesCounter = 0 ;
	List();  			/* class constructor */
        List (const List &);
        ~List();  			/* class  destructor */

        bool isListEmpty() const;
	bool isCurEmpty() const;
	void toFirst();
	bool atFirst() const;
	void advance();
	void toEnd();
	bool atEnd() const;
	int  listSize() const;
	void updateData (const dataType & );
	void retrieveData (dataType &) const;
	void insertFirst (const keyType &, const dataType & );
	void insertAfter (const keyType &, const dataType & );
	void insertBefore (const keyType &, const dataType & );
	void insertEnd (const keyType &, const dataType & );
	void deleteNode();
	void deleteFirst();
	void deleteEnd();
	void makeListEmpty();
	bool searchElement (const keyType & );
	void orderInsert(const keyType &, const dataType & );
	void traverse();


private:

	class Node {
		public :		     /* public members to be accessible to the List Class */
		/* ---------------------------------------------------------------------- */
		keyType key ; 	  /* to make list as ordered linked list */
		dataType data;    /* to store the date */
		Node* next;       /* pointer to the next node */
		 	  };
	typedef Node* ptrToNode ;
        ptrToNode head , cursor , prev ;

};






#endif
