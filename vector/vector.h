#ifndef VECTOR_H
#define VECTOR_H

#include "../public_functions.h"

namespace SelfDefinedVector {
    template <typename T>
    class vector{

    public:

        vector(int cap);
        vector();
        ~vector();

        // functions
        void push_back(T e);
        void pop_back();
        void reverse();
        void test();
        void clear();
        void erase(T e);
        void eraseIndex(size_t idx);
        void insert(T e, int idx);
        int  find(T target);

        // attributes
        int size();
        bool empty();
        T& operator [](int idx);

        // pointers
        T* begin;
        T* end;
        T* front();
        T* back();

    private:
        T* data;
        int length;
        int capacity;
    };


    ///////////////////////////////////////////////////////////
    ///                   Implementation                    ///
    ///////////////////////////////////////////////////////////
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
    void vector<T>::push_back(T e){
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
    void vector<T>::pop_back(){
        if(this->empty()){
            ErrorPrint("Pop back from empty vector");
            return;
        }
        data[length-1] = NULL;
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
        this->begin = new T;
        this->end   = new T;
        length = 0;        
        delete[] this->data;
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
                for(int j = i;j<length; j++){
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
        for(int i = idx; i< length; i++){
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
    int vector<T>::find(T target){
        /// erase by data
        if(this->empty()){
            ErrorPrint("Find element from empty vector");
            return -1;
        }
        for(int i =0; i < length; i++){
            if(this->data[i] == target) return i;
        }
    }

    template <typename T>
    bool vector<T>::empty(){
        return length==0;
    }


    template <typename T>
    void vector<T>::test(){
        TestPrint("Self Defined Vector");
        /// Test
        /// 1. push_back / pop_back
        /// 2. erase
        /// 3. find
        /// 4. insert
        /// 5. test the pointers
        /*1*/
        vector<int> V;
        V.push_back(123456);
        V.pop_back();

        /*2*/
        V.push_back(123);
        V.eraseIndex(0);
        V.push_back(456);
        V.erase(456);
        //V.erase(123);

        /*3*/
        for(int i = 0; i < 400; i+= 4){
            V.push_back((int)i);
        }
        if(V.find(40) != 10) ErrorPrint("V.find(40) = " + to_string(V.find(40)));

        /*4*/
        V.insert(10000,10);
        if(V.find(10000) != 10) ErrorPrint("V.find(10000) = " + to_string(V.find(10000)));






        TestPassPrint("Vector");
        return;
    }


    template <typename T>
    T& vector<T>::operator [](int idx){
        return this->data[idx];
    }

    template <typename T>
    T* vector<T>::front(){
        return this->data[0];
    }

    template <typename T>
    T* vector<T>::back(){
        return this->data[length];
    }

}

#endif // VECTOR_H

