#include "Heap.h"
#include <iostream>
#include "printutils.h"

template <typename KeyT, typename ValueT>
Heap<KeyT, ValueT>::Heap() : compare( [](KeyT a, KeyT b){ return a <= b; } ), heap_size(0) { }

template <typename KeyT, typename ValueT>
Heap<KeyT, ValueT>::Heap(std::function<bool(KeyT,KeyT)> compare_func) : compare(compare_func), heap_size(0) { }

template <typename KeyT, typename ValueT>
unsigned long Heap<KeyT, ValueT>::insert(KeyT key, ValueT value) {

    HeapEntry<KeyT, ValueT> entry{key, value};

    if (this->entries.empty()) {
        this->entries.push_back(entry);
        this->heap_size++;
        return 0;
    }

    if (this->heap_size == this->entries.size()) {
        this->entries.push_back(entry);
    } else {
        this->entries[this->heap_size] = entry;
    }

    this->heap_size++;

    return this->bubbleUp(this->entries.size() - 1);

}

template <typename KeyT, typename ValueT>
HeapEntry<KeyT, ValueT> Heap<KeyT, ValueT>::pop() {

    HeapEntry<KeyT, ValueT> result = this->entries[0];

    this->entries[0] = this->entries[this->heap_size - 1];
    this->heap_size--;

    this->bubbleDown(0);

    return result;

}

template <typename KeyT, typename ValueT>
long Heap<KeyT, ValueT>::findIndex(ValueT value) {

    for (unsigned long i = 0; i < this->heap_size; i++) {
        if (this->entries[i].value == value) return i;
    }

    return -1;

}

template <typename KeyT, typename ValueT>
HeapEntry<KeyT, ValueT> Heap<KeyT, ValueT>::at(unsigned long index) {

    if (index >= this->heap_size) {
        throw std::invalid_argument("Wrong index provided");
    }

    return this->entries[index];

}

template <typename KeyT, typename ValueT>
void Heap<KeyT, ValueT>::remove(unsigned long index) {

    if (index >= this->heap_size) {
        throw std::invalid_argument("Wrong index provided");
    }

    this->entries[index] = this->entries[this->heap_size - 1];
    this->heap_size--;

    this->bubbleDown(index);
}

template <typename KeyT, typename ValueT>
unsigned long Heap<KeyT, ValueT>::bubbleUp(unsigned long index) {

    if (index == 0) return index;

    auto parent_index = this->parent(index);

    KeyT my_key = this->entries[index].key;
    KeyT parent_key = this->entries[parent_index].key;

    bool in_place = this->compare(parent_key, my_key);
    if (in_place) return index;

    this->swap(index, parent_index);
    return this->bubbleUp(parent_index);

}

template <typename KeyT, typename ValueT>
unsigned long Heap<KeyT, ValueT>::bubbleDown(unsigned long index) {

    if (index == this->heap_size-1) return index;

    auto child_index_1 = this->firstChild(index);
    auto child_index_2 = child_index_1 + 1;

    auto my_entry = this->entries[index];

    auto child_1 = (child_index_1 < this->heap_size) ? this->entries[child_index_1] : my_entry;
    auto child_2 = (child_index_2 < this->heap_size) ? this->entries[child_index_2] : my_entry;

    bool in_place = (this->compare(my_entry.key, child_1.key) && this->compare(my_entry.key, child_2.key));
    if (in_place) return index;

    unsigned long smaller_child_index;
    smaller_child_index = (this->entries[child_index_1].key < this->entries[child_index_2].key) ? child_index_1 : child_index_2;

    this->swap(index, smaller_child_index);
    return this->bubbleDown(smaller_child_index);

}

template <typename KeyT, typename ValueT>
void Heap<KeyT, ValueT>::swap(unsigned long i, unsigned long j) {

    auto tmp = this->entries[i];
    this->entries[i] = this->entries[j];
    this->entries[j] = tmp;

}

template <typename KeyT, typename ValueT>
unsigned long Heap<KeyT, ValueT>::parent(unsigned long i) {

    return (i - 1) / 2;

}

template <typename KeyT, typename ValueT>
unsigned long Heap<KeyT, ValueT>::firstChild(unsigned long i) {

    return 2 * i + 1;

}

template <typename KeyT, typename ValueT>
void Heap<KeyT, ValueT>::printData() {

    if (this->heap_size == 0)
        return;

    std::cout << "[";
    for (auto i = 0; i < this->heap_size - 1; i++) {
        std::cout << this->entries[i].key << "(" << this->entries[i].value << ")" <<  ", ";
    }
    std::cout << this->entries[this->heap_size - 1].key << "(" << this->entries[this->heap_size - 1].value << ")]" << std::endl;

}

template class Heap<int, int>;
