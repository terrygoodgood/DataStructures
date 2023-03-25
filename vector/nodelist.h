#ifndef NODELIST_H
#define NODELIST_H

#include "../public_functions.h"
#include <cassert>

template <typename T>
class NodeList{
public:
    class node{
    public:
        node():next(nullptr), prev(nullptr){}
        T data;
        node* next;
        node* prev;
    };

    class Iterator{
    public:
        Iterator(node* u);


        bool         operator==(const Iterator& iter);
        bool         operator!=(const Iterator& iter);

        T&           operator*();

        Iterator&    operator++();
        Iterator&    operator--();

        friend class NodeList;
    private:
        node* v;
    };

public:

    NodeList();
    ~NodeList();
    T& operator [](int idx);

    int size() const;
    bool empty() const;
    Iterator begin();
    Iterator end();


    void insertFront(const T& data);
    void insertBack(const T& data);
    void insert(const Iterator& iter, const T& data);


    void eraseFront();
    void eraseBack();
    void erase(const Iterator& iter);


    void test();
private:
    int n;
    node* header;
    node* trailer;
};


////////////////////////////////
/// Iterator implementations ///
////////////////////////////////
template <typename T>
NodeList<T>::Iterator::Iterator(node* u){
    v = u;
}

template <typename T>
T& NodeList<T>::Iterator::operator *(){
    return v->data;
}

template <typename T>
bool NodeList<T>::Iterator::operator==(const Iterator& iter){
    return v == iter.v;
}

template <typename T>
bool NodeList<T>::Iterator::operator!=(const Iterator& iter){
    return v != iter.v;
}



/*
In the NodeList class, there is a nested class Iterator defined, which represents an iterator for the list. However, since Iterator is a nested class of NodeList, its full name includes the name of its enclosing class, like NodeList<T>::Iterator.

When you use Iterator as a type, the compiler needs to know what Iterator is, which requires the full name NodeList<T>::Iterator. However, Iterator is not a member of NodeList until the NodeList class is fully instantiated with a template parameter, T. Therefore, we need to use the typename keyword to tell the compiler that Iterator is a type defined within NodeList<T>.

So, the correct way to use the Iterator data type is to write it as typename NodeList<T>::Iterator. For example, you can declare a variable of type Iterator like this:
*/


template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator ++(){
    v = v->next;return *this;
}


template <typename T>
 typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator--(){
    v= v->prev; return *this;
}



/////////////////////////////////
///         NodeList          ///
/////////////////////////////////



template<typename T>
NodeList<T>::NodeList(){
    n = 0;
    header = new node;
    trailer = new node;
    header->next = trailer;
    trailer->prev = header;
}

template <typename T>
NodeList<T>::~NodeList() {
    node* curr = header;
    while (curr) {
        node* next = curr->next;
        delete curr;
        curr = next;
    }
}


template <typename T>
int NodeList<T>::size() const{
    return n;
}

template <typename T>
bool NodeList<T>::empty() const{
    return n==0;
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::begin(){
    return Iterator(header->next);
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::end(){
    return Iterator(trailer);
}

template <typename T>
void NodeList<T>::insertFront(const T& data){
    insert(begin(), data);
}


template <typename T>
void NodeList<T>::insertBack(const T& data){
    insert(end(), data);
}

template <typename T>
void NodeList<T>::insert(const Iterator &iter, const T &data){
    node* curr = iter.v;
    node* pre  = curr->prev;
    node* temp = new node;
    temp->data = data;
    temp->next = curr;
    curr->prev = temp;
    temp->prev = pre;
    pre->next = temp;
    n++;
}


template <typename T>
void NodeList<T>::erase(const Iterator& iter){
    node* curr = iter.v;
    node* pre = curr->prev;
    node* Next = curr ->next;
    Next->prev = pre;
    pre->next = Next;
    delete curr;
    n--;
}

template<typename T>
void NodeList<T>::eraseFront(){
    erase(begin());
}
template <typename T>
void NodeList<T>::eraseBack(){
    erase(--end());
    // end() is actually a nullptr at the bottom of NodeList
}

template <typename T>
T& NodeList<T>::operator[](int idx) {
    Iterator curr = begin();
    while(idx-- > 0){
        ++curr;
    }
    return *curr;
}

template <typename T>
void NodeList<T>::test(){
    NodeList<double> NL;
    TestPrint("insertFront&Back");
    NL.insertFront(456);
    NL.insertBack(1.5);
    NL.insertBack(2.5);
    NL.insertBack(32.5);
    NL.insertBack(24.5);
    NL.insertBack(288.5);
    assert(NL[0]==456);
    TestPrint("eraseFront");
    NL.eraseFront();
    assert(NL[0]==1.5);
    TestPrint("eraseBack");;
    NL.eraseBack();
    assert(NL[3]==24.5);
    TestPrint("operator []");
    NL[0] = 57.1;
    assert(NL[0] == 57.1);
    TestPassPrint("NodeList");


}
#endif // NODELIST_H
