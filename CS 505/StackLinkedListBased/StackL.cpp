#include "stackL.h"

template <class GenericType>
StackL <GenericType> :: StackL()  {stackTop = NULL;}


template <class GenericType>
bool StackL <GenericType>::isEmpty() const
{ return stackTop == NULL ;}


template <class GenericType>
void StackL <GenericType>::top(GenericType &G) const
{
	
       if (!isEmpty()) G =stackTop->data ;
       else throw invalid_argument("Error : stack is empty , not found top element ");
}

template <class GenericType>
void StackL<GenericType>::push(GenericType G)
{
    nodePtr myNode = new Node();
    myNode-> data = G ;
    myNode-> next = stackTop;
    stackTop = myNode ;
}

template<class GenericType>
void StackL<GenericType>::pop(GenericType &G)
{
 
if (!isEmpty())
{
nodePtr garbage = new Node();
garbage = stackTop;
stackTop = stackTop->next;
G = garbage->data ;
delete garbage;
}
else throw invalid_argument("Error : stack is empty , no pop operation");
}