#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "../public_functions.h"
#include "QueueInterface.h"

template <typename T>
class ArrayQueue : public QueueInterface<T> {
    public:
    ArrayQueue(int cap = 100);
    ~ArrayQueue();
    int size() const override;
    bool empty() const  override;
    const T& front() const override;
    void enqueue(const T& e, bool test=false) override;
    void dequeue(bool test = false) override;
    void test() override;
private:
    T* Q;
    int qnum;
    int capacity;
};




template<typename T>
ArrayQueue<T>::ArrayQueue(int cap) : Q(new T[cap]), qnum(-1), capacity(cap){}


template <typename T>
ArrayQueue<T> :: ~ArrayQueue(){
    delete []Q;
}

template<typename T>
int ArrayQueue<T>::size() const{
    return this->qnum +1;
}

template<typename T>
bool ArrayQueue<T>::empty() const{
    return this->qnum==-1;
}


template<typename T>
const T& ArrayQueue<T>::front() const{
    return Q[qnum];
}


template<typename T>
void ArrayQueue<T>::enqueue(const T& e, bool test){
    if(this->size() == capacity){
        test? TestPrint("Exceed queue size"):ErrorPrint("Exceed queue size");
        return;
    }
    qnum++;
    Q[qnum] = e;
}


template<typename T>
void ArrayQueue<T>:: dequeue(bool test){
    if(empty()){
        test ? TestPrint("Dequeue from empty queue"):ErrorPrint("Dequeue from empty queue");
        return;
    }
    qnum--;
}


template <typename T>
void ArrayQueue<T>::test(){
    TestPrint("Array Queue");
    for(int i = 0; i < capacity; i++){
        enqueue(i, true);
    }
    enqueue(999999, true);
    while(!empty()) dequeue();
    dequeue(true);

    TestPassPrint("ArrayQueue");
}


#endif // ARRAYQUEUE_H
