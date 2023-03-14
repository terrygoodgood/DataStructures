#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H


#include "../public_functions.h"



template<typename T>
class DNode{
public:
    DNode():prev(nullptr),next(nullptr){}
    T data;
    DNode<T>* prev;
    DNode<T>* next;
};


template <typename T>
class DoublyLinkedList{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    bool empty();
    void addFront(T& e);
    void addBack(T& e);
    const T& front() const;
    const T& end() const;

    void removeFront();
    void removeBack();
    void virtual test();
private:
    DNode<T>* head;
    DNode<T>* back;
protected:
    void add(DNode<T>* node, const T& e);
    void remove(DNode<T>* node);
};


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = new DNode<T>;
    back = new DNode<T>;
    head->next = back;
    back->prev = head;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    while(!empty()) removeFront();
}


template <typename T>
bool DoublyLinkedList<T>::empty(){
    return head == back;
}

template <typename T>
void DoublyLinkedList<T>::addFront(T& e){
    if(empty())
    {
        head = new DNode<T>;
        head->data = e;
        head->next = back;
        back->prev = head;
    }else{
        DNode<T>* temp = new DNode<T>;
        temp->data = e;
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::addBack(T& e){
    if(empty()){
        back = new DNode<T>;
        back->data = e;
        back->prev = head;
        head->next = back;
    }
    else
    {
        DNode<T>* temp = new DNode<T>;
        temp->data = e;
        back->next = temp;
        temp->prev = back;
        back = temp;
    }

}


template <typename T>
void DoublyLinkedList<T>::removeFront() {
    if (empty()) {
        return;
    }
    DNode<T>* curr = head;
    head = curr->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        back = nullptr;
    }
    delete curr;
}

template <typename T>
void DoublyLinkedList<T>::removeBack() {
    if (empty()) {
        return;
    }
    DNode<T>* curr = back;
    back = curr->prev;
    if (back != nullptr) {
        back->next = nullptr;
    } else {
        head = nullptr;
    }
    delete curr;
}


template <typename T>
const T& DoublyLinkedList<T>::end() const{
    return back->data;
}




template <typename T>
const T& DoublyLinkedList<T>::front() const{
    return head->data;
}



template<typename T>
void DoublyLinkedList<T>::add(DNode<T>* node, const T& e){
    DNode<T>* temp = new DNode<T>;
    temp->data = e;
    temp->next = node;
    node->prev = temp;
    node->prev->next = temp->prev = temp;
}


template <typename T>
void DoublyLinkedList<T>::test(){
    int j = 0;
    for(int i = 0; i < 10 ; i++){
        addBack(i);
        addFront(j);
    }
    removeBack();
    removeFront();
}
#endif // DLINKEDLIST_H
