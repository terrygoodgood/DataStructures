#ifndef VECTOR_H
#define VECTOR_H
#include <cassert>

#include "../public_functions.h"

namespace SelfDefinedVector {
    template <typename T>
    class vector{

    public:

        vector(int cap=10);
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
        const T* front();
        const T* back();

    private:
        T** data; // pointer array
        T* begin;
        T* end;
        int length;
        int capacity;
    };


    ///////////////////////////////////////////////////////////
    ///                   Implementation                    ///
    ///////////////////////////////////////////////////////////
    template< typename T>
    vector<T>::vector(int cap):capacity(cap), begin(new T), end(new T), data(new T*[cap]), length(0){}


    template <typename T>
    vector<T>::~vector(){
        delete[] data;
    }

    template <typename T>
    int vector<T>::size(){
        return length;
    }


    template <typename T>
    void vector<T>::push_back(T e){
        if(capacity){
            if(size() == capacity){
                ErrorPrint("Exceed vector size");
                return;
            }
        }
        T* temp = new T;
        *temp = e;
        data[length] = temp;
        begin = data[0];
        end   = data[length];
        length++;
    }

    template <typename T>
    void vector<T>::pop_back(){
        if(empty()){
            ErrorPrint("Pop back from empty vector");
            return;
        }
        delete data[--length] ;
        begin = data[0];
        end   = data[length-1];
    }



    template <typename T>
    void vector<T>::reverse(){
        T** newdata = new T*[length];
        for(int i = 0; i < length; i++){
            newdata[i] = data[length-1-i];
        }
        delete[] data;
        data = newdata;
        begin = data[0];
        end   = data[length-1];
    }


    template <typename T>
    void vector<T>::clear(){
        delete data;

        data = new T*[capacity];
        begin = data[0];
        end = data[0];
        length = 0;
    }

    template <typename T>
    void vector<T>::erase(T e){
        /// erase by data
        if(empty()){
            ErrorPrint("Erase element from empty vector");
            return;
        }
        for(int i =0; i < length; i++){
            if(*data[i] == e){
                for(int j = i;j<length; j++){
                    data[j] = data[j+1];
                }
                length--;
                begin = data[0];
                end   = data[length-1];
                return;
            }
        }
    }

    template <typename T>
    void vector<T>::eraseIndex(size_t idx){
        /// erase by index
        if(empty()){
            ErrorPrint("Erase element from empty vector");
            return;
        }
        if(length < idx){
            string S = "Length = "+to_string(length)+" no index "+to_string(idx);
            ErrorPrint(S);
            return;
        }
        for(int i = idx; i< length; i++){
            data[i] = data[i+1];
        }
        length--;
        begin = data[0];
        end   = data[length-1];
    }


    template <typename T>
    void vector<T>::insert(T e, int idx){

        if(size() == capacity){
            ErrorPrint("Insert to full vector");
            return;
        }

        if(length > idx){
            for(int i = idx; i < length; i++){
                data[i+1] = data[i];
            }
        }else idx = length;
        T* temp = new T;
        *temp = e;
        length++;
        data[idx] = temp;
        begin = data[0];
        end   = data[length-1];
    }

    template <typename T>
    int vector<T>::find(T target){
        /// erase by data
        if(empty()){
            ErrorPrint("Find element from empty vector");
        }else{
            for(int i =0; i < length; i++){
                if(*data[i] == target) return i;
            }
        }
        return -1;
    }

    template <typename T>
    bool vector<T>::empty(){
        return length==0;
    }



    template <typename T>
    void vector<T>::test(){
        TestPrint("vector");
        // Test constructors and basic operations
        TestPrint("constructors and basic operations");
        vector<int> v;
        assert(v.size() == 0);
        assert(v.empty());

        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        assert(v.size() == 3);
        assert(v[0] == 1);
        assert(v[1] == 2);
        assert(v[2] == 3);

        v.pop_back();
        assert(v.size() == 2);
        assert(v[0] == 1);
        assert(v[1] == 2);

        // Test clear and insert
        TestPrint("clear and insert");
        v.clear();
        assert(v.size() == 0);

        v.insert(1, 0);
        assert(v.size() == 1);
        assert(v[0] == 1);

        v.insert(3, 1);
        assert(v.size() == 2);
        assert(v[0] == 1);
        assert(v[1] == 3);

        v.insert(2, 1);
        assert(v.size() == 3);
        assert(v[0] == 1);
        assert(v[1] == 2);
        assert(v[2] == 3);

        // Test erase
        TestPrint("erase");
        v.erase(2);
        assert(v.size() == 2);
        assert(v[0] == 1);
        assert(v[1] == 3);

        v.eraseIndex(0);
        assert(v.size() == 1);
        assert(v[0] == 3);

        // Test find
        TestPrint("find");
        v.push_back(4);
        v.push_back(5);
        assert(v.find(4) == 1);
        assert(v.find(6) == -1);

        // Test pointers
        TestPrint("pointers front() & back()");
        const int* ptr1 = v.front();
        const int* ptr2 = v.back();
        assert(*ptr1 == 3);
        assert(*ptr2 == 5);

        // Test reverse
        TestPrint("reverse");
        v.reverse();
        assert(v.size() == 3);
        assert(v[0] == 5);
        assert(v[1] == 4);
        assert(v[2] == 3);

        TestPassPrint("vector");
    }

    template <typename T>
    T& vector<T>::operator [](int idx){
        return **(data+idx);
    }

    template <typename T>
    const T* vector<T>::front(){
        return begin;
    }

    template <typename T>
    const T* vector<T>::back(){
        return end;
    }

}

#endif // VECTOR_H

