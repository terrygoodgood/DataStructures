#ifndef QUEUE_H
#define QUEUE_H
#include "../public_functions.h"



template <typename T>
class QueueInterface{
public:
    virtual int size() const;
    virtual bool empty() const;
    virtual const T& front() const;
    virtual void enqueue(const T& e, bool test=false);
    virtual void dequeue(bool test = false);
};



#endif // QUEUE_H
