#include "STACKA.h"

template <class GenericType>
StackA <GenericType> :: StackA()  {mytop = -1;}


template <class GenericType>
bool StackA <GenericType>::isEmpty() const
{ return mytop == -1 ;}

template <class GenericType>
bool StackA <GenericType>::isFull() const
{return mytop >= stackCapacity ;}

template <class GenericType>
void StackA <GenericType>::top(GenericType &G) const
{
	(!isEmpty()) ? G = Arr[mytop] : throw invalid_argument("Error : stack is empty , not found top element ");
}

template <class GenericType>
void StackA<GenericType>::push(GenericType G)
{
   (isFull()) ? throw invalid_argument("Error : stack is Full , stack overflow!") : Arr[++mytop] = G ;
}

template<class GenericType>
void StackA<GenericType>::pop(GenericType &G)
{
(!isEmpty()) ? G = Arr[mytop--] : throw invalid_argument("Error : stack is empty , no pop operation");
}

