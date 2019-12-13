#include <iostream>
using namespace std;

template <class T>
class StackLinked {
private:

    class Node {
    public:
        T data;
        Node *next;

        Node(T sentData) : data(sentData), next(NULL) {
        } //constructor
    };
    typedef Node* nodePtr;
    nodePtr top, cursor;
    int sizeOfStack;

public:

    StackLinked() : top(NULL), cursor(NULL), sizeOfStack(0) {
    }; //constructor

    ~StackLinked() {
    } //destructor

    bool isFull() const;
    bool isEmpty() const;
    void getTop(T&) const;
    void push(T);
    void pop(T&);
    void traverse(void(*pf)(T));
    int stackSize() const;
};
