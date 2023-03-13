#include "linkedlist.h"
#include <iostream>
using namespace std;


/// int example
linkedlist::linkedlist():head(nullptr){
    cout << "---Linkedlist initiliazed.---" <<endl;
}


//linkedlist::~linkedlist(){
//    Node** temp = new Node*[10];
//    int cnt = 0;
//    while(head){
//        temp[cnt++] = head;
//        head = head->next;
//    }
//    for(int i = 0; i < cnt; i++){
//        delete temp[i];
//    }
//    delete[] temp;
//}


// This is modified by chatGPT
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
