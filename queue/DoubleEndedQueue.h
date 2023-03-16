#ifndef DOUBLEENDEDQUEUE_H
#define DOUBLEENDEDQUEUE_H

#include "../public_functions.h"
#include "QueueInterface.h"


template <typename T>
class DoubleEndedQueue:public QueueInterface<T>{
public:
    DoubleEndedQueue(int cap=100);
    ~DoubleEndedQueue();
    int size() const override;
    bool empty() const override;
    const T& front() const override;
    const T& rear() const;
    void enqueue(const T& e, bool test = false) override;
    void dequeue(bool test = false) override;
    void test() override;
private:
    int qnum;
    int frontnum;
    int rearnum;
    T* Q;
    int capacity;
};



template<typename T>
DoubleEndedQueue<T>::DoubleEndedQueue(int cap):qnum(-1), capacity(cap), Q(new T[capacity]){}

template <typename T>
DoubleEndedQueue<T>::~DoubleEndedQueue(){
    delete [] Q;
}

template <typename T>
int DoubleEndedQueue<T>::size() const{
    return this->qnum+1;
}

template <typename T>
const T& DoubleEndedQueue<T>::front() const{
    return Q[frontnum];
}

template <typename T>
const T& DoubleEndedQueue<T>::rear() const{
    return Q[rearnum];
}

//template <typename T>
//void DoubleEndedQueue<T>::enqueue(const T& e, bool test){
//    if(this->size() == capacity){
//        test ? TestPrint("Exceed queue size") : ErrorPrint("Exceed queue size");
//        return;
//    }
//    rearnum = ++qnum;
//    Q[qnum] = e;
//}


template <typename T>
void DoubleEndedQueue<T>::enqueue(const T& e, bool test){
    if(this->size() == capacity){
        test ? TestPrint("Exceed queue size") : ErrorPrint("Exceed queue size");
        return;
    }
    if (qnum == -1) { // empty queue
        frontnum = rearnum = 0;
    } else {
        if (frontnum == 0) { // front is at the beginning of the queue
            frontnum = capacity - 1;
        } else {
            frontnum--;
        }
        if (rearnum == capacity - 1) { // rear is at the end of the queue
            rearnum = 0;
        } else {
            rearnum++;
        }
    }
    Q[frontnum] = e;
    qnum++;
}

template <typename T>
bool DoubleEndedQueue<T>::empty() const{
    return qnum==-1;
}

template <typename T>
void DoubleEndedQueue<T>::dequeue(bool test){
    if(empty()){
        test ? TestPrint("Dequeue from empty queue") : ErrorPrint("Dequeue from empty queue");
        return;
    }
    rearnum = --qnum;
}

template<typename T>
void DoubleEndedQueue<T>::test(){
    TestPrint("DoubleEndedQueue");
    for(int i = 0; i < capacity; i++) enqueue(i, true);

    enqueue(999999, true);
    front();
    rear();
    while(!empty()) dequeue();
    dequeue(true);
    front();
    rear();

    TestPassPrint("DoubleEndedQueue");

}

#endif // DOUBLEENDEDQUEUE_H
