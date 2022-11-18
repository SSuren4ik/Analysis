#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Queue {
private:
    size_t start;
    size_t end;
    T* arr;
    size_t size;//размер буфера
    size_t next(size_t i) { return ((i + 1) % size); }
public:
    Queue(size_t s=0)
    {
        size = s + 1;
        arr = new T[size];
        end = 0;
        start = next(end);
    }

    bool Is_Empty()
    {
        if (next(end) == start)
            return true;
        return false;
    }
    bool Is_Full() {
        if (next(next(end)) == start)
        {
            return true;
        }
        return false;
    }
    void Push(T x) {
        if (Is_Full())
        {
            ReMem();
        }
        end = next(end);
        arr[end] = x;
    }
    T Pop() {
        if (Is_Empty())
        {
            throw exception();
        }
        T v = arr[start];
        start = next(start);
        return v;
    }
    void ReMem()
    {
        T* arr2 = new T[size * 2];
        end = 0;
        for (size_t i = 1; i < size; i++)
        {
            arr2[i] = arr[next(end)];
            end = next(end);
        }
        delete[] arr;
        arr = arr2;
        size *= 2;
    }
};