#ifndef TESTS_H
#define TESTS_H
#include "linkedlist.h"
#include "glinkedlist.h"
#include "dlinkedlist.h"
#include "clinkedlist.h"


#include "stack.h"
#include "lstack.h"
namespace tests{
    namespace LinkedList{

        void TestLinkedlist(){
            /// Linkedlist
            Glinkedlist<double> GL;
            for(double d = 0.1; d<1.0; d+=0.1){
                GL.addFront(d);
            }
            GNode<double>* GLtemp = GL.head;
            while(GL.head->next!=nullptr){
                GL.head = GL.head->next;
            }
            GL.head = GLtemp;
            const double & GLhead = GL.head->data;
            cout << endl << "[ LinkedList ] Test passed !" << endl;
        }

        void TestDoublyLinkedList(){
            /// DoublyLinkedList
            DoublyLinkedList<int> DL;
            int j = 0;
            for(int i = 0; i < 10 ; i++){
                DL.addBack(i);
                DL.addFront(j);
            }

            const int &DLfront = DL.front();
            const int &DLback  = DL.end();
            cout << endl << "[ DoublyLinkedList ] Test passed !" << endl;
        }

        void TestCircularlyLinkedLists(){
            CircularlyLinkedList<double> CL;
            for(double i = 1.1; i < 2.0; i+=0.1){
                CL.add(i);
            }
            for(int i = 0; i < 5 ; i++){
//                cout << CL.cursor->data<<endl;
                CL.advance();
            }
            CL.remove();
            cout << endl << "[ CircularlyLinkedList ] Test passed !" << endl;

        }

    }
    namespace Stack{
        void TestArrayBasedStack(){
            stack<int> St;
            for(int i = 0; i < 10; i++){
                St.push(i);
            }
            while(!St.empty()){
//                cout << St.top()<<endl;
                St.pop();
            }
            cout << endl << "[ Array-Based Stack ] Test passed !" << endl;

        }


        void TestLinkedListBasedStack(){
            LStack<int> LSt;
            for(int i = 0 ; i < 10 ; i++){
                LSt.push(i);
            }
            while(!LSt.empty()){
                LSt.pop();
            }
            cout <<  endl <<"[ LinkedList Based Stack] Test passed !"<<endl;
        }
    }

    namespace Queue{}
}
#endif // TESTS_H
