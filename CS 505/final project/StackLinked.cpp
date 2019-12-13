#include "StackLinked.h"

//return size of stack
template <class T>
int StackLinked<T>::stackSize() const {
    return sizeOfStack;
}

//return true if stack empty
template <class T>
bool StackLinked<T>::isEmpty() const {
    return !sizeOfStack;
}

//return true if stack full
template <class T>
bool StackLinked<T>::isFull() const {
    return 0;
}

//put element at the top of stack
template <class T>
void StackLinked<T>::push(T ele) {
    nodePtr newNode = new Node(ele);
    newNode->next = top;
    top = newNode;
    sizeOfStack++;
}

//get top element in stack
template <class T>
void StackLinked<T>::pop(T &ele) {
    if (isEmpty()) return;
    ele = top->data;
    cursor = top;
    top = top->next;
    delete(cursor);
    sizeOfStack--;
}

//get top element without changing stack
template <class T>
void StackLinked<T>::getTop(T &ele) const {
    if (isEmpty()) return;
    ele = top->data;
}

//traverse elements in stack
template <class T>
void StackLinked<T>::traverse(void(*pf)(T)) {
    if (isEmpty()) return;
    cursor = top;
    while (cursor != NULL) {
        (*pf)(cursor->data);
        cursor = cursor->next;
    }
}