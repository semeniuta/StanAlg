#ifndef UNIQUEVALUESHEAP_H
#define UNIQUEVALUESHEAP_H

#include <map>
#include "Heap.h"

template <typename KeyT, typename ValueT>
class UniqueValuedHeap : public Heap<KeyT, ValueT> {

public:

    UniqueValuedHeap() = default;
    explicit UniqueValuedHeap(std::function<bool(KeyT,KeyT)> compare_func) : Heap<KeyT, ValueT>(compare_func) {}
    unsigned long insert(KeyT key, ValueT value) override;
    long findIndex(ValueT value) override;
    void printIndices();

protected:

    void swap(unsigned long i, unsigned long j) override;

private:

    std::map<ValueT, unsigned long> indices;


};


#endif
