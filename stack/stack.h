#ifndef STACK_H
#define STACK_H
#include <iostream>

#include "../public_functions.h"

template <typename T>
class stack {
    enum { DEF_CAPACITY = 100 };
public:
    stack(int capacity = DEF_CAPACITY);
    ~stack();
    virtual void  push(const T& e, bool test=false);
    virtual void  pop(bool test= false);
    virtual const T& top() const;
    virtual int size() const;
    virtual bool empty() const;
    virtual void test();
private:
    T* S;
    int capacity;
    int t; // index of the top of the stack
};

template <typename T>
stack<T>::stack(int cap) : S(new T[cap]), capacity(cap), t(-1) {}

template <typename T>
int stack<T>::size() const {
    return t + 1;
}

template <typename T>
bool stack<T>::empty() const {
    return t < 0;
}

template <typename T>
const T& stack<T>::top() const {
    if (empty()) cout << "Stack is empty" << endl;
    return S[t];
}

template <typename T>
void stack<T>::push(const T& e, bool test) {
    if (size() == capacity) test? TestPrint("Exceed stack size"): ErrorPrint("Exceed stack size");
    this->t++;
    S[this->t] = e;
}

template <typename T>
void stack<T>::pop(bool test){
    if (empty()){
        test ? TestPrint("Pop from empty stack"):ErrorPrint("Pop from empty stack");
        return;
    }
    --t;
}

template <typename T>
stack<T>::~stack() {
    delete[] S;
}

template <typename T>
void stack<T> :: test(){

    TestPrint("Stack");

    for(int i = 0; i < capacity; i++) push(i, true);

    push(99999, true); // Push exceed stack size

    while(!empty()) pop(true);

    pop(true); // Pop from empty stack
}

#endif // STACK_H
