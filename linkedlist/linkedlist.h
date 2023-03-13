#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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


#endif // LINKEDLIST_H
