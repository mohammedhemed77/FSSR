#include "STACKL.h"

template <class GenericType>
StackL <GenericType> :: StackL()  {mytop = -1;}


template <class GenericType>
bool StackL <GenericType>::isEmpty() const
{ return mytop == -1 ;}

template <class GenericType>
bool StackL <GenericType>::isFull() const
{return mytop >= stackCapacity ;}

template <class GenericType>
void StackL <GenericType>::top(GenericType &G) const
{
	(!isEmpty()) ? G = Arr[mytop] : throw invalid_argument("Error : stack is empty , not found top element ");
}

template <class GenericType>
void StackL<GenericType>::push(GenericType G)
{
   (isFull()) ? throw invalid_argument("Error : stack is Full , stack overflow!") : Arr[++mytop] = G ;
}

template<class GenericType>
void StackL<GenericType>::pop(GenericType &G)
{
(!isEmpty()) ? G = Arr[mytop--] : throw invalid_argument("Error : stack is empty , no pop operation");
}
