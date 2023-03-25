#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "nodelist.h"
#include <cassert>

template<typename T>
class NodeSequence:public NodeList<T>{
public:
    typename NodeList<T>::Iterator atIndex(int i);
    int indexOf(const typename NodeList<T>::Iterator & iter);
    void test();
};

template<typename T>
typename NodeList<T>::Iterator NodeSequence<T>::atIndex(int i){
    typename NodeList<T>::Iterator iter = this->begin();
    for(int j = 0; j < i ;j++) ++iter;
    return iter;
}

template <typename T>
int NodeSequence<T>::indexOf(const typename NodeList<T>::Iterator & iter){
    typename NodeList<T>::Iterator temp = this->begin();
    int idx = 0;
    while(temp !=iter){
        temp++;
        idx++;
    }
    return idx;
}


template <typename T>
void NodeSequence<T>::test(){
    NodeSequence<int> NS;
    NS.insert(NS.begin(),1);
    assert(NS[0]==1);
    NS.erase(NS.begin());
    assert(NS.empty());
    TestPassPrint("NodeSequence");
}

#endif // SEQUENCE_H
