#ifndef NODELIST_H
#define NODELIST_H




template <typename T>
class NodeList{

    class Iterator{
    public:
        Iterator(node<T>* u);
        T& operator*();
        bool operator==(const Iterator& iter) const;
        bool operator!=(const Iterator& iter) const;
        Iterator<T>& operator++();
        Iterator<T>& operator--();
        friend class NodeList;
    private:
        node<T>* v;
    };

    class node{
    public:
        node():next(nullptr), prev(nullptr){}
        T data;
        node<T>* next;
        node<T>* prev;
    };

public:

    NodeList();
    T& operator [](int idx);

    int size() const;
    bool empty() const;
    Iterator<T> begin();
    Iterator<T> end();


    void insertFront(const T& data);
    void insertBack(const T& data);
    void insert(const Iterator<T>& iter, const T& data);


    void eraseFront();
    void eraseBack();
    void erase(const Iterator<T>& iter);

private:
    int n;
    node<T>* header;
    node<T>* trailer;
};


////////////////////////////////
/// Iterator implementations ///
////////////////////////////////
template <typename T>
NodeList<T>::Iterator<T>::Iterator(node<T>* u){
    v = u;
}

template <typename T>
T& NodeList<T>::Iterator<T>::operator *(){
    return v->data;
}

template <typename T>
bool NodeList<T>::Iterator<T>::operator==(const Iterator<T>& iter){
    return v == iter.v;
}

template <typename T>
bool NodeList<T>::Iterator<T>::operator!=(const Iterator<T>& iter){
    return v != iter.v;
}


template <typename T>
NodeList<T>:: Iterator<T>::operator ++(){
    v = v->next;return *this;
}

template <typename T>
NodeList<T>:: Iterator<T>::operator--(){
    v= v->prev; return *this;
}


/////////////////////////////////
///         NodeList          ///
/////////////////////////////////
template<typename T>
NodeList<T>::NodeList(){
    n = 0;
    header = new node<T>;
    trailer = new node<T>;
    header->next = trailer;
    trailer->prev = header;
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
NodeList<T> :: Iterator<T> NodeList<T>::begin(){
    return Iterator(header->next);
}

template <typename T>
NodeList<T>:: Iterator<T> NodeList<T>::end(){
    return Iterator(trailer);
}



#endif // NODELIST_H
