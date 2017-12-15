#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <map>
#include <functional>

template <typename T>
class Heap {

public:

    Heap();
    explicit Heap(std::function<bool(T,T)> compare_func);
    virtual unsigned long insert(T val);
    virtual long findIndex(T val);
    T pop();
    T at(unsigned long index);
    void remove(unsigned long index);
    void printData();
    unsigned long size() { return heap_size; }

protected:

    std::vector<T> data;
    std::function<bool(T,T)> compare;
    unsigned long heap_size;

    virtual void swap(unsigned long i, unsigned long j);

private:

    unsigned long bubbleUp(unsigned long index);
    unsigned long bubbleDown(unsigned long index = 0);
    unsigned long parent(unsigned long i);
    unsigned long firstChild(unsigned long i);


};


#endif
