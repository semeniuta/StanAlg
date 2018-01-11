#include "UniqueValuedHeap.h"
#include <iostream>

template <typename KeyT, typename ValueT>
unsigned long UniqueValuedHeap<KeyT, ValueT>::insert(KeyT key, ValueT value) {

    auto itr = this->indices.find(value);
    if (itr != this->indices.end()) return itr->second;

    auto idx = Heap<KeyT, ValueT>::insert(key, value);
    this->indices[value] = idx;

    return idx;

}


template <typename KeyT, typename ValueT>
long UniqueValuedHeap<KeyT, ValueT>::findIndex(ValueT value) {

    auto itr = this->indices.find(value);

    if (itr != this->indices.end()) {
        return itr->second;
    }

    return -1;

}

template <typename KeyT, typename ValueT>
void UniqueValuedHeap<KeyT, ValueT>::swap(unsigned long i, unsigned long j) {

    HeapEntry<KeyT, ValueT> a = this->entries[i];
    HeapEntry<KeyT, ValueT> b = this->entries[j];

    Heap<KeyT, ValueT>::swap(i, j);

    this->indices[a.value] = j;
    this->indices[b.value] = i;
}

template <typename KeyT, typename ValueT>
void UniqueValuedHeap<KeyT, ValueT>::printIndices() {

    if (this->heap_size == 0)
        return;

    std::cout << "{";

    for (const auto& entry : this->indices) {
        auto value = entry.first;
        auto idx = entry.second;
        std::cout << value << "->" << idx << ", ";
    }
    std::cout << "}\n";

}

template class UniqueValuedHeap<int, int>;