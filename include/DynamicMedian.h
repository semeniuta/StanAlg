#ifndef DYNAMICMEDIAN_H
#define DYNAMICMEDIAN_H

#include <functional>
#include "Heap.h"

template <typename T>
class DynamicMedian {

public:

    DynamicMedian() = default;

    void insert(T val) {

        if (h_low.empty() && h_high.empty()) {
            h_low.insert(val, true);
            return;
        }

        if (h_high.empty()) { // and one entry in h_low

            if (val >= h_low.topKey()) {
                h_high.insert(val, true);
            } else {
                equalize(h_low, val);
            }

            return;
        }

        T a = h_low.topKey();
        T b = h_high.topKey();

        if (val <= a) {
            insertLow(val);
        } else if (val >= b) {
            insertHigh(val);
        } else { // a < val < b
            insertLow(val);
        }
    }

    T median() {

        if (h_low.size() >= h_high.size()) {
            return h_low.topKey();
        } else {
            return h_high.topKey();
        }

    }

    void printData() {

        if (h_low.empty()) {
            std::cout << "[Empty]";
        } else {
            std::cout << "[";
            for (unsigned long i = h_low.size() - 1; i > 0; i--) {
                std::cout << h_low.at(i).key << ", ";
            }
            std::cout << h_low.topKey() << "]";
        }

        if (h_high.empty()) {
            std::cout << "[Empty]";
        } else {
            std::cout << "[";
            for (unsigned long i = 0; i < h_high.size() - 1; i++) {
                std::cout << h_high.at(i).key << ", ";
            }
            std::cout << h_high.at(h_high.size() - 1).key << "]";
        }

        std::cout << std::endl;
    }

private:

    Heap<T, bool> h_low{std::greater_equal<>()};
    Heap<T, bool> h_high{std::less_equal<>()};

    void equalize(Heap<T, bool>& heap_to_pop, T val) {

        auto popped = heap_to_pop.pop();

        T smaller, bigger;
        if (popped.key <= val) {
            smaller = popped.key;
            bigger = val;
        } else {
            smaller = val;
            bigger = popped.key;
        }

        h_low.insert(smaller, true);
        h_high.insert(bigger, true);
    }

    void insertLow(T val) {

        if (h_low.size() <= h_high.size()) {
            h_low.insert(val, true);
        } else {
            equalize(h_low, val);
        }

    }

    void insertHigh(T val) {

        if (h_low.size() >= h_high.size()) {
            h_high.insert(val, true);
        } else {
            equalize(h_high, val);
        }

    }

};

#endif
