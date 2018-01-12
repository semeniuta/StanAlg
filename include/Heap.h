#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <map>
#include <functional>

template <typename KeyT, typename ValueT>
struct HeapEntry {
    KeyT key;
    ValueT value;
};

template <typename KeyT, typename ValueT>
class Heap {

public:

    Heap();
    explicit Heap(std::function<bool(KeyT,KeyT)> compare_func);
    virtual unsigned long insert(KeyT key, ValueT value);
    virtual HeapEntry<KeyT, ValueT> pop();
    HeapEntry<KeyT, ValueT> at(unsigned long index);
    virtual long findIndex(ValueT value);
    virtual HeapEntry<KeyT, ValueT> remove(unsigned long index);
    void printData();
    unsigned long size() { return heap_size; }
    bool empty() { return (heap_size == 0); };

protected:

    std::vector<HeapEntry<KeyT, ValueT>> entries;
    std::function<bool(KeyT,KeyT)> compare;
    unsigned long heap_size;

    virtual void swap(unsigned long i, unsigned long j);

private:

    unsigned long bubbleUp(unsigned long index);
    unsigned long bubbleDown(unsigned long index = 0);
    unsigned long parent(unsigned long i);
    unsigned long firstChild(unsigned long i);


};


#endif
