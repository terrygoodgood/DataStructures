#ifndef DOUBLEENDEDQUEUE_H
#define DOUBLEENDEDQUEUE_H
#include "QueueInterface.h"

template <typename T>
class DoubleEndedQueue:public QueueInterface<T>{
    DoubleEndedQueue();
    int size() const;
    bool empty() const;
    const T& front() const;
    void enqueue(const T& e);
    void dequeue();
};
#endif // DOUBLEENDEDQUEUE_H
