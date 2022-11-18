#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
private:
    size_t top;
    size_t size;
    T* arr;
public:
    Stack(size_t sz)
    {
        if (sz <= 0)
        {
            throw exception();
        }
        top = -1;
        size = sz;
        arr = new T[size];
    }
    Stack(const Stack& st)
    {
        top = st.top;
        size = st.size;
        copy(st.arr, st.arr + size, arr);
    }
    T Size()
    {
        return top + 1;
    }
    void Push(const T& val)
    {
        if (top == size - 1)
        {
            T* tmp = new T[size * 2];
            copy(arr, size + arr, tmp);
            delete[] arr;
            arr = tmp;
            size *= 2;
        }
        arr[++top] = val;
    }
    T Pop()
    {
        if (IsEmpty())
        {
            throw exception();
        }
        T v = arr[top];
        top--;
        return v;
    }
    bool IsEmpty() const
    {
        return top == -1;
    }
    bool IsFull() const
    {
        return top == size - 1;
    }
    Stack()
    {
        delete[] arr;
    }
};