#ifndef UNIQUEVALUESHEAP_H
#define UNIQUEVALUESHEAP_H

#include <map>
#include "Heap.h"

template <typename T>
class UniqueValuedHeap : public Heap<T> {

public:

    UniqueValuedHeap() = default;
    explicit UniqueValuedHeap(std::function<bool(T,T)> compare_func) : Heap<T>(compare_func) {}
    unsigned long insert(T val) override;
    long findIndex(T val) override;
    void printIndices();

protected:

    void swap(unsigned long i, unsigned long j) override;

private:

    std::map<T, unsigned long> indices;


};


#endif
