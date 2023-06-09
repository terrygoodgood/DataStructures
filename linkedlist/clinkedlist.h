#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include "../public_functions.h"


#include "linkedlist.h"


template <typename T>
class CNode{
public:
    CNode():next(nullptr){}
    T data;
    CNode* next;
};



template <typename T>
class CircularlyLinkedList{
public:
    CircularlyLinkedList();
    const T& front() const;
    const T& back() const;
    void advance();
    void add(T& e);
    void remove();
    bool empty();
    void virtual test();
    CNode<T>* cursor;
};

template <typename T>
CircularlyLinkedList<T>::CircularlyLinkedList():cursor(nullptr){}

template <typename T>
bool CircularlyLinkedList<T>::empty(){
    return cursor==nullptr;
}
template <typename T>
const T& CircularlyLinkedList<T>::front() const{
    return cursor ? cursor->next->data: nullptr;
}
template <typename T>
const T& CircularlyLinkedList<T>::back() const{
    return cursor->data;
}

template <typename T>
void CircularlyLinkedList<T>::advance(){
    cursor = cursor->next;
}


template <typename T>
void CircularlyLinkedList<T>::add(T& e){
    CNode<T>* v = new CNode<T>;
    v->data = e;
    if(empty()){
        v->next = v;
        cursor = v;
    }else{
        v->next = cursor->next;
        cursor->next = v;
    }
}


template <typename T>
void CircularlyLinkedList<T>::remove(){
    CNode<T>* old = cursor->next;
    if(old==cursor){
        cursor = nullptr;
    }else{
        cursor->next = old->next;
    }
}

template <typename T>
void CircularlyLinkedList<T>::test(){
    for(double i = 1.1; i < 2.0; i+=0.1){
        add(i);
    }
    for(int i = 0; i < 5 ; i++){
        advance();
    }
    remove();
}

#endif // CLINKEDLIST_H
