#ifndef QUEUE_H
#define QUEUE_H
#include "../public_functions.h"



template <typename T>
class QueueInterface{
public:
    virtual int size() const=0;
    virtual bool empty() const=0;
    virtual const T& front() const=0;
    virtual void enqueue(const T& e, bool test=false)=0;
    virtual void dequeue(bool test = false)=0;
    virtual void test()=0;
};



#endif // QUEUE_H
