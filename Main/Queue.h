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

    void Relocate()
    {
        T* arr2 = new T[size * 2];
        size_t index = 1;
        for (size_t i = start; i != next(end); i = next(i))
        {
            arr2[index] = arr[i];
            index++;
        }
        delete[] arr;
        arr = arr2;
        end = size - 1;
        size *= size;
        start = 1;
    }
public:
    Queue(size_t s=1)
    {
        size = s;
        arr = new T[size];
        end = 0;
        start = next(end);
    }
    Queue(const Queue<T>& q)
    {

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
            Relocate();
        }
        end = next(end);
        arr[end] = x;
    }
    T Top()
    {
        return arr[start];
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
    friend ostream& operator <<(ostream& out, Queue<T>& q)
    {
        if (q.Is_Empty())
        {
            out << "Queue is Empty!\n";
            return out;
        }
        for (int i = q.start; i != q.next(q.end); i= q.next(i))
        {
            out << q.arr[i] << endl;
        }
        return out;
    }
    ~Queue()
    {
        if(size!=0)
        delete[] arr;
    }
};