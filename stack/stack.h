#ifndef STACK_H
#define STACK_H
#include <iostream>
template <typename T>
class stack {
    enum { DEF_CAPACITY = 100 };
public:
    stack(int capacity = DEF_CAPACITY);
    ~stack();
    void virtual push(const T& e);
    void virtual pop();
    const virtual T& top() const;
    int size() const;
    bool virtual empty() const;

private:
    T* S;
    int capacity;
    int t; // index of the top of the stack
};

template <typename T>
stack<T>::stack(int cap) : S(new T[cap]), capacity(cap), t(-1) {}

template <typename T>
int stack<T>::size() const {
    return t + 1;
}

template <typename T>
bool stack<T>::empty() const {
    return t < 0;
}

template <typename T>
const T& stack<T>::top() const {
    if (empty()) throw std::out_of_range("Stack is empty");
    return S[t];
}

template <typename T>
void stack<T>::push(const T& e) {
    if (size() == capacity) return;
    t++;
    S[t] = e;
}

template <typename T>
void stack<T>::pop() {
    if (empty()) return;
    --t;
}

template <typename T>
stack<T>::~stack() {
    delete[] S;
}

#endif // STACK_H
