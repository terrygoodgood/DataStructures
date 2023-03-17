#ifndef TESTS_H
#define TESTS_H

/// linked lists
#include "linkedlist/clinkedlist.h"
#include "linkedlist/linkedlist.h"
#include "linkedlist/glinkedlist.h"
#include "linkedlist/dlinkedlist.h"


/// stacks
#include "stack/stack.h"
#include "stack/lstack.h"


/// queues
#include "queue/ArrayQueue.h"
#include "queue/DoubleEndedQueue.h"

/// vector
#include "vector/vector.h"

namespace tests{


    namespace LinkedList{

        void TestLinkedlist(){
            /// Linkedlist
            Glinkedlist<double>* GL = new Glinkedlist<double>;
            GL->test();
            delete GL;
            TestPassPrint("LinkedList");
        }

        void TestDoublyLinkedList(){
            /// DoublyLinkedList
            DoublyLinkedList<int>* DL = new DoublyLinkedList<int>;
            DL->test();
            delete DL;
            TestPassPrint("DoublyLinkedList");
        }

        void TestCircularlyLinkedLists(){
            /// Circularly LinkedList
            CircularlyLinkedList<double>* CL = new CircularlyLinkedList<double>;
            CL->test();
            delete CL;
            TestPassPrint("CircularlyLinkedList");

        }

        void TestAll(){
            TestLinkedlist();
            TestDoublyLinkedList();
            TestCircularlyLinkedLists();
        }
    }

    namespace Stack{
        void TestArrayBasedStack(){
            stack<int>* St = new stack<int>;
            St->test();
            delete St;
            TestPassPrint("Array-Based Stack");

        }


        void TestLinkedListBasedStack(){
            LStack<int>* LSt = new LStack<int>;
            LSt->test();
            delete LSt;

            TestPassPrint("LinkedList-Based Stack");
        }

        void TestAll(){
            TestArrayBasedStack();
            TestLinkedListBasedStack();
        }
    }

    namespace Queue{
        void TestArrayQueue(){
            ArrayQueue<int>* AQ = new ArrayQueue<int>;
            AQ->test();
            delete AQ;
        }

        void TestDoubleEndedQueue(){
            DoubleEndedQueue<int>* DEQ = new DoubleEndedQueue<int>;
            DEQ->test();
            delete DEQ;
        }



        void TestAll(){
            TestArrayQueue();
            TestDoubleEndedQueue();
        }
    }

    namespace Vector{
        void TestVector(){
            SelfDefinedVector::vector<int> SDV;
            SDV.test();
        }
    }
}






#endif // TESTS_H
