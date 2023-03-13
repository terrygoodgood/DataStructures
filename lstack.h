#ifndef LSTACK_H
#define LSTACK_H
#include "stack.h"
#include "glinkedlist.h"
template <typename T>
class LStack: public stack<T>, public GNode<T>{
    // LinkedList based stack
public:
    enum{DEF_CAPACITY=100};
    LStack(int capacity = DEF_CAPACITY);
    ~LStack();
    void push(const T&e) override;
    void pop() override;
    const T& top() const override;
    bool empty() const override;
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
        pop();
    }
    delete S; // delete the dummy node
}

template<typename T>
void LStack<T>::push(const T& e){
    if(this->size()==capacity) return;
    t++;
    GNode<T>* temp = new GNode<T>;
    temp->data = e;
    temp->next = S;
    S = temp;
}

template<typename T>
void LStack<T>::pop(){
    if(empty()) return;
    GNode<T>* temp = new GNode<T>;
    temp = S;
    S = S->next;
    delete temp;
    --t;
}


template<typename T>
const T& LStack<T>::top() const{
    if(empty()) throw std::out_of_range("Stack is empty");
    return S->data;
}

template <typename T>
bool LStack<T>::empty() const{
    return t < 0;
}
#endif // LSTACK_H
