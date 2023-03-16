#ifndef VECTOR_H
#define VECTOR_H

#include "../public_functions.h"
#include "../linkedlist/dlinkedlist.h"

namespace SelfDefinedVector {
    template <typename T>
    class vector : public DoublyLinkedList<T>{

    public:

        vector(int cap);
        vector();
        ~vector();

        // functions
        void push_back(T& e, bool test=false);
        void push_back(T e, bool test=false);
        void push_front(T& e, bool test=false);
        void push_front(T e, bool test=false);

        void pop_front();
        void pop_back();

        void reverse();

        void test() override;
        void testCapacity();

        void clear();

        void erase(T e);
        void eraseIndex(size_t idx);

        void insert(T e, int idx);

        int* find(T target); // indices for target

        /* used only in numeric data types */
        const T& max();
        const T& min();
        const T sum();


        // attributes
        int size();
        bool empty();
        T& operator [](int idx);


        // pointers
        DNode<T>* begin;
        DNode<T>* end;
    private:
        T* data;
        int length;
        int capacity;

    };


    /// Implementation
    template< typename T>
    vector<T>::vector(int cap):capacity(cap), begin(nullptr), end(nullptr), data(new T), length(0){}
    template <typename T>
    vector<T>::vector():capacity(0),begin(nullptr), end(nullptr),data(new T), length(0){}


    template <typename T>
    vector<T>::~vector(){
        delete this->data;
        delete this->begin;
        delete this->end;
    }

    template <typename T>
    int vector<T>::size(){
        return length;
    }

    template <typename T>
    void vector<T>::push_back(T& e, bool test){
        if(this->capacity){
            if(this->size() == capacity){
                test ? TestPrint("Exceed vector size"):ErrorPrint("Exceed vector size");
                return;
            }
        }
        this->data + length++ = e;
    }


    template <typename T>
    void vector<T>::push_back(T e, bool test){
        if(capacity){
            if(this->size() == capacity){
                ErrorPrint("Exceed vector size");
                return;
            }
        }
        this->data[length] = e;
        length++;
    }


    template <typename T>
    void vector<T>::pop_front(){
        if(this->empty()){
            ErrorPrint("Pop front from empty vector");
            return;
        }
        this->data = this->data +1; // move ahead 1 unit
        length--;
    }


    template <typename T>
    void vector<T>::pop_back(){
        if(this->empty()){
            ErrorPrint("Pop back from empty vector");
            return;
        }
        length--;
    }



    template <typename T>
    void vector<T>::reverse(){
        T* newdata = new T*;
        for(int i = 0; i > length; i++){
            newdata[i] = this->data[length-1 - i];
        }
        delete this->data;
        this->data = newdata;
        delete newdata;
    }


    template <typename T>
    void vector<T>::clear(){
        delete this->begin;
        delete this->end;
        this->begin = new DNode<T>;
        this->end   = new DNode<T>;
        length = 0;
        capacity = 0;
        delete this->data;
        this->data = new T*;
    }





    template <typename T>
    void vector<T>::erase(T e){
        /// erase by data
        if(this->empty()){
            ErrorPrint("Erase element from empty vector");
            return;
        }
        for(int i =0; i < length; i++){
            if(this->data[i] == e){
                for(int j = i;j<length-1; j++){
                    this->data[j] = this->data[j+1];
                }
                length--;
                return;
            }
        }
    }

    template <typename T>
    void vector<T>::eraseIndex(size_t idx){
        /// erase by index
        if(this->empty()){
            ErrorPrint("Erase element from empty vector");
            return;
        }
        if(length < idx){
            string S = "Length = "+to_string(length)+" no index "+to_string(idx);
            ErrorPrint(S);
            return;
        }
        for(int i = idx; i< length-1; i++){
            this->data[i] = this->data[i+1];
        }
        length--;
    }


    template <typename T>
    void vector<T>::insert(T e, int idx){
        if(capacity){
            if(this->size() == capacity){
                ErrorPrint("Insert to full vector");
                return;
            }
        }
        for(int i = idx+1; i < length; i++){
            this->data[i] = this->data[i-1];
        }
        this->data[idx] = e;
    }

    template <typename T>
    int* vector<T>::find(T target){
        /// erase by data
        if(this->empty()){
            ErrorPrint("Find element from empty vector");
            return nullptr;
        }
        int* temp = new int;
        int cnt = 0;
        for(int i =0; i < length; i++){
            if(this->data[i] == target){
                temp[cnt++] = i;
            }
        }

        int ans[cnt];
        for(int i = 0; i < cnt; i++){
            ans[i] = temp[i];
        }
        delete temp;
        return ans;
    }




    template <typename T>
    bool vector<T>::empty(){
        return length==0;
    }


    template <typename T>
    void vector<T>::test(){
        TestPrint("Self Defined Vector");
        push_back(123,true);
        TestPrint("Current value = "+to_string(this->data[0]));
        size_t a = 1523;
        eraseIndex(a);
        erase(10);
        TestPrint("Pop back");
        pop_back();
        TestPrint("Pop back");

        pop_back();

        return;
    }



    template <typename T>
    void vector<T>::testCapacity(){
        TestPrint("Self Defined Vector - test capacity");
        for(int i = 0; i < capacity+1 ; i++){
            push_back((int)i, true);
        }
        for(int i = 0; i < capacity+2 ; i++){
            pop_back();
        }
        TestPassPrint("vector capacity");
        return;
    }



    /// For numeric data types only
//    template <typename T>
//    const vector<T>::T& max(){

//    }
}

#endif // VECTOR_H

