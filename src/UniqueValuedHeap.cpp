#include "UniqueValuedHeap.h"
#include <iostream>

template <typename T>
unsigned long UniqueValuedHeap<T>::insert(T val) {

    auto itr = this->indices.find(val);
    if (itr != this->indices.end()) return itr->second;

    auto idx = Heap<T>::insert(val);
    this->indices[val] = idx;

    return idx;

}


template <typename T>
long UniqueValuedHeap<T>::findIndex(T val) {

    auto itr = this->indices.find(val);

    if (itr != this->indices.end()) {
        return itr->second;
    }

    return -1;

}

template <typename T>
void UniqueValuedHeap<T>::swap(unsigned long i, unsigned long j) {

    T a = this->data[i];
    T b = this->data[j];;

    Heap<T>::swap(i, j);

    this->indices[a] = j;
    this->indices[b] = i;
}

template <typename T>
void UniqueValuedHeap<T>::printIndices() {

    if (this->heap_size == 0)
        return;

    std::cout << "{";

    for (const auto& entry : this->indices) {
        T val = entry.first;
        T idx = entry.second;
        std::cout << val << "->" << idx << ", ";
    }
    std::cout << "}\n";

}

template class UniqueValuedHeap<int>;