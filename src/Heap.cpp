#include "Heap.h"
#include <iostream>
#include "printutils.h"

template <typename T>
Heap<T>::Heap() : compare( [](T a, T b){ return a <= b; } ), heap_size(0) { }

template <typename T>
Heap<T>::Heap(std::function<bool(T,T)> compare_func) : compare(compare_func), heap_size(0) { }

template <typename T>
void Heap<T>::insert(T val) {

    if (this->data.empty()) {
        this->data.push_back(val);
        this->heap_size++;
        return;
    }

    if (this->heap_size == this->data.size()) {
        this->data.push_back(val);
    } else {
        this->data[this->heap_size] = val;
    }

    this->bubbleUp(this->data.size() - 1);

    this->heap_size++;

}

template <typename T>
T Heap<T>::pop() {

    T result = this->data[0];

    this->data[0] = this->data[this->heap_size - 1];
    this->heap_size--;

    this->bubbleDown(0);

    return result;

}

template <typename T>
long Heap<T>::findIndex(T val) {

    for (unsigned long i = 0; i < this->heap_size; i++) {
        if (this->data[i] == val) return i;
    }

    return -1;

}

template <typename T>
T Heap<T>::at(unsigned long index) {

    if (index >= this->heap_size) {
        throw std::invalid_argument("Wrong index provided");
    }

    return this->data[index];

}

template <typename T>
void Heap<T>::remove(unsigned long index) {

    if (index >= this->heap_size) {
        throw std::invalid_argument("Wrong index provided");
    }

    this->data[index] = this->data[this->heap_size - 1];
    this->heap_size--;

    this->bubbleDown(index);
}

template <typename T>
void Heap<T>::bubbleUp(unsigned long index) {

    if (index == 0) return;

    auto parent_index = this->parent(index);

    T my_val = this->data[index];
    T parent_val = this->data[parent_index];

    bool in_place = this->compare(parent_val, my_val);

    if (!in_place) {
        this->swap(index, parent_index);
        this->bubbleUp(parent_index);
    }

}

template <typename T>
void Heap<T>::bubbleDown(unsigned long index) {

    if (index == this->heap_size-1) return;

    auto child_index_1 = this->firstChild(index);
    auto child_index_2 = child_index_1 + 1;

    T my_val = this->data[index];

    T child_1 = (child_index_1 < this->heap_size) ? this->data[child_index_1] : my_val;
    T child_2 = (child_index_2 < this->heap_size) ? this->data[child_index_2] : my_val;

    bool in_place = (this->compare(my_val, child_1) && this->compare(my_val, child_2));

    if (!in_place) {

        unsigned long smaller_child_index;
        smaller_child_index = (this->data[child_index_1] < this->data[child_index_2]) ? child_index_1 : child_index_2;

        this->swap(index, smaller_child_index);
        this->bubbleDown(smaller_child_index);

    }

}

template <typename T>
void Heap<T>::swap(unsigned long i, unsigned long j) {

    T tmp = this->data[i];
    this->data[i] = this->data[j];
    this->data[j] = tmp;

}

template <typename T>
unsigned long Heap<T>::parent(unsigned long i) {

    return (i - 1) / 2;

}

template <typename T>
unsigned long Heap<T>::firstChild(unsigned long i) {

    return 2 * i + 1;

}

template <typename T>
void Heap<T>::printData() {

    if (this->heap_size == 0)
        return;

    std::cout << "[";
    for (auto i = 0; i < this->heap_size - 1; i++) {
        std::cout << this->data[i] << ", ";
    }
    std::cout << this->data[this->heap_size - 1] << "]" << std::endl;

}

template class Heap<int>;
