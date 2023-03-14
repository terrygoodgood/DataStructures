#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../public_functions.h"


#include <iostream>
using namespace std;

/// Below is for int example
class Node{
public:
    int data;
    Node* next;
};


class linkedlist{
public:
    linkedlist();
    ~linkedlist();

    bool empty();
    void addFront(int& e);
    int& front() const;
    void removeFront();
    Node* head;
};

/// implement
linkedlist::linkedlist():head(nullptr){
    cout << "---Linkedlist initiliazed.---" <<endl;
}

linkedlist::~linkedlist(){
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}




void linkedlist::addFront(int &e){
    Node* node = new Node;
    node->data = e;
    node->next = head;
    head = node;
}

int& linkedlist::front() const{
    return head->data;
}

void linkedlist::removeFront(){
    Node* old = head; // save current head
    head = old->next; // skip over old head
    delete old;       // delete the old head
}

bool linkedlist::empty(){
    return head == nullptr;
}

#endif // LINKEDLIST_H
