#ifndef GLINKEDLIST_H
#define GLINKEDLIST_H

#include "../public_functions.h"


#include <iostream>

using namespace std;


/// Generic linkedlist
template<typename T>  class GNode {
public:
    T data;
    GNode<T>* next;
};




template <typename T>
class Glinkedlist{
public:
    Glinkedlist();
    ~Glinkedlist();

    bool empty();
    void addFront(T& e);
    T& front() const;
    void removeFront();
    void virtual test();
    GNode<T>* head;
};




/// the functions are defined here due to compiler linker issue on template
template<typename T>
Glinkedlist<T>::Glinkedlist():head(nullptr){
}


template <typename T>
Glinkedlist<T>::~Glinkedlist(){
    while(!empty()) removeFront();
}

template <typename T>
void Glinkedlist<T>::addFront(T &e){
    GNode<T>* node = new GNode<T>;
    node->data = e;
    node->next = head;
    head = node;
}

template<typename T> T& Glinkedlist<T>::front() const{
    return head->data;
}


template<typename T>
void Glinkedlist<T>::removeFront(){
    if (head == nullptr) {
        return; // nothing to remove
    }
    GNode<T>* old = head; // save current head
    head = old->next; // skip over old head
    delete old;       // delete the old head
}


template <typename T>
bool Glinkedlist<T>::empty(){
    return head==NULL;
}

template<typename T>
void Glinkedlist<T>::test(){
    for(double d = 0.1; d<1.0; d+=0.1){
        this->addFront(d);
    }
    GNode<double>* GLtemp = head;
    while(head->next!=nullptr){
        head = head->next;
    }
    head = GLtemp;
}
#endif // GLINKEDLIST_H
