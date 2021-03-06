#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <map>
#include <functional>
#include <iostream>

template <typename KeyT, typename ValueT>
struct HeapEntry {
    KeyT key;
    ValueT value;
};

template <typename KeyT, typename ValueT>
class Heap {

public:

    Heap() : compare{ std::less_equal<>() }, heap_size(0) { }

    explicit Heap(std::function<bool(KeyT,KeyT)> compare_func) : compare(compare_func), heap_size(0) { }

    virtual unsigned long insert(KeyT key, ValueT value) {

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

        return this->bubbleUp(this->heap_size - 1);

    }

    virtual HeapEntry<KeyT, ValueT> pop() {

        HeapEntry<KeyT, ValueT> result = this->entries[0];

        this->entries[0] = this->entries[this->heap_size - 1];
        this->heap_size--;

        this->bubbleDown(0);

        return result;

    }

    KeyT topKey() {

        if (this->empty()) {
            throw std::runtime_error("Heap is empty");
        }

        return this->entries[0].key;
    }

    HeapEntry<KeyT, ValueT> at(unsigned long index) {

        if (index >= this->heap_size) {
            throw std::invalid_argument("Wrong index provided");
        }

        return this->entries[index];

    }

    virtual long findIndex(ValueT value) {

        for (unsigned long i = 0; i < this->heap_size; i++) {
            if (this->entries[i].value == value) return i;
        }

        return -1;

    }

    virtual HeapEntry<KeyT, ValueT> remove(unsigned long index) {

        if (index >= this->heap_size) {
            throw std::invalid_argument("Wrong index provided");
        }

        HeapEntry<KeyT, ValueT> result = this->entries[index];

        this->entries[index] = this->entries[this->heap_size - 1];
        this->heap_size--;

        this->bubbleDown(index);

        return result;

    }

    void printData() {

        if (this->heap_size == 0)
            return;

        std::cout << "[";
        for (auto i = 0; i < this->heap_size - 1; i++) {
            std::cout << this->entries[i].key << "(" << this->entries[i].value << ")" <<  ", ";
        }
        std::cout << this->entries[this->heap_size - 1].key << "(" << this->entries[this->heap_size - 1].value << ")]" << std::endl;

    }

    unsigned long size() { return heap_size; }
    bool empty() { return (heap_size == 0); };

protected:

    std::vector<HeapEntry<KeyT, ValueT>> entries;
    std::function<bool(KeyT,KeyT)> compare;
    unsigned long heap_size;

    virtual void swap(unsigned long i, unsigned long j) {

        auto tmp = this->entries[i];
        this->entries[i] = this->entries[j];
        this->entries[j] = tmp;

    }

private:

    unsigned long bubbleUp(unsigned long index) {

        if (index == 0) return index;

        auto parent_index = this->parent(index);

        KeyT my_key = this->entries[index].key;
        KeyT parent_key = this->entries[parent_index].key;

        bool in_place = this->compare(parent_key, my_key);
        if (in_place) return index;

        this->swap(index, parent_index);
        return this->bubbleUp(parent_index);

    }

    unsigned long bubbleDown(unsigned long index = 0) {

        if (index == this->heap_size-1) {
            return index;
        }

        auto child_index_1 = this->firstChild(index);
        auto child_index_2 = child_index_1 + 1;

        auto my_entry = this->entries[index];

        auto child_1 = (child_index_1 < this->heap_size) ? this->entries[child_index_1] : my_entry;
        auto child_2 = (child_index_2 < this->heap_size) ? this->entries[child_index_2] : my_entry;

        bool in_place = (this->compare(my_entry.key, child_1.key) && this->compare(my_entry.key, child_2.key));
        if (in_place) {
            return index;
        }

        unsigned long target_child_index;
        target_child_index = this->compare(
                this->entries[child_index_1].key, this->entries[child_index_2].key
        ) ? child_index_1 : child_index_2;

        this->swap(index, target_child_index);
        return this->bubbleDown(target_child_index);

    }

    unsigned long parent(unsigned long i) {

        return (i - 1) / 2;

    }

    unsigned long firstChild(unsigned long i) {

        return 2 * i + 1;

    }

};


#endif
