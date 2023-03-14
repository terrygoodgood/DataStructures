#ifndef LSTACK_H
#define LSTACK_H

#include "../public_functions.h"
#include "stack.h"
#include "../linkedlist/glinkedlist.h"


#include <iostream>
using namespace std;

template <typename T>
class LStack: public stack<T>, public GNode<T>{
    // LinkedList based stack
public:
    enum{DEF_CAPACITY=100};
    LStack(int capacity = DEF_CAPACITY);
    ~LStack();
    void push(const T&e, bool test=false) override;
    void pop(bool test=false) override;
    const T& top() const override;
    bool empty() const override;
    void test() override;
    int size() const override;
private:
    GNode<T>* S;
    int capacity;
    int t; // index of the top of the stack

};

template<typename T>
LStack<T>::LStack(int cap): S(new GNode<T>), capacity(cap), t(-1){}


template<typename T>
LStack<T>::~LStack(){
    while(!empty()) {
        pop(false);
    }
    delete S; // delete the dummy node
}

template <typename T>
int LStack<T>::size() const{
    return t+1;
}

template<typename T>
void LStack<T>::push(const T& e, bool test){
    if(this->size()==capacity) test ? TestPrint("Exceeding stack size"):ErrorPrint("Exceeding stack size !");
    this->t++;
    GNode<T>* temp = new GNode<T>;
    temp->data = e;
    temp->next = S;
    S = temp;
}


template<typename T>
void LStack<T>::pop(bool test){
    if(empty()) test ? TestPrint("Pop from empty stack !"):ErrorPrint("Pop from empty stack !");
    GNode<T>* temp = new GNode<T>;
    temp = S;
    S = S->next;
    delete temp;
    --t;
}


template<typename T>
const T& LStack<T>::top() const{
    if(empty()) ErrorPrint("Stack is Empty !");
    return S->data;
}

template <typename T>
bool LStack<T>::empty() const{
    return t < 0;
}

template <typename T>
void LStack<T>::test(){
    TestPrint("Stack");
    for(int i = 0 ; i < capacity ; i++){
        push(i, true);
    }
    push(99999, true);
    while(!empty()){
        pop(true);
    }
    pop(true);
}

#endif // LSTACK_H
