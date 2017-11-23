#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <functional>

template <typename T>
class Heap {

public:

    Heap();
    Heap(std::function<bool(T,T)> compare_func);
    void insert(T val);
    T pop();
    long findIndex(T val);
    T at(unsigned long index);
    void remove(unsigned long index);
    void printData();
    unsigned long size() { return heap_size; }


private:

    std::vector<T> data;
    std::function<bool(T,T)> compare;
    unsigned long heap_size;

    void bubbleUp(unsigned long index);
    void bubbleDown(unsigned long index = 0);
    void swap(unsigned long i, unsigned long j);
    unsigned long parent(unsigned long i);
    unsigned long firstChild(unsigned long i);


};


#endif
