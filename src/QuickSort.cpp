#include <vector>
#include "QuickSort.h"

template<class T>
QuickSort<T>::QuickSort() : choose_pivot_rule(medianOfThree) {
    this->pvec = nullptr;
}

template<class T>
QuickSort<T>::QuickSort(ChoosePivotRule cpr) {
    this->choose_pivot_rule = cpr;
}

template<class T>
unsigned long QuickSort<T>::sort(std::vector<T> *vec) {
    this->pvec = vec;

    auto num_compares = this->sort(0, this->pvec->size() - 1);

    return num_compares;
}

template<class T>
unsigned long QuickSort<T>::sort(unsigned long lo, unsigned long hi) {

    if (hi + 1 == 0 || lo >= hi) {
        return 0;
    }

    auto initial_pivot_index = this->choosePivot(lo, hi);
    this->swap(lo, initial_pivot_index);
    auto pivot_index = this->partition(lo, hi);

    auto num_compares_1 = this->sort(lo, pivot_index - 1);
    auto num_compares_2 = this->sort(pivot_index + 1, hi);

    return num_compares_1 + num_compares_2 + (hi - lo);

}

template<class T>
unsigned long QuickSort<T>::choosePivot(unsigned long lo, unsigned long hi) {

    switch (this->choose_pivot_rule) {

        case medianOfThree: {
            unsigned long len = hi - lo + 1;

            unsigned long mid;
            if (len % 2 == 0) {
                mid = lo + len / 2 - 1;
            } else {
                mid = lo + len / 2;
            }

            T candidates[3] = {
                    this->getVectorElement(lo),
                    this->getVectorElement(mid),
                    this->getVectorElement(hi)
            };

            int smallest_ind = 0;
            int largest_ind = 0;

            for (int i = 0; i < 3; i++) {

                if (candidates[i] < candidates[smallest_ind]) {
                    smallest_ind = i;
                }

                if (candidates[i] > candidates[largest_ind]) {
                    largest_ind = i;
                }

            }

            unsigned long median = 0;
            for (unsigned long i = 0; i < 3; i++) {
                if (i != smallest_ind && i != largest_ind) {
                    median = i;
                    break;
                }
            }

            if (median == 0) {
                return lo;
            } else if (median == 1) {
                return mid;
            } else {
                return hi;
            }

        }

        case first:
            return lo;

        case last:
            return hi;

    }
}

template<class T>
unsigned long QuickSort<T>::partition(unsigned long lo, unsigned long hi) {

    T p = this->getVectorElement(lo);

    unsigned long i = lo + 1;

    for (unsigned long j = lo + 1; j <= hi; j++) {
        if (this->getVectorElement(j) < p) {
            this->swap(i, j);
            i++;
        }
    }

    unsigned long pivot_index = i - 1;
    this->swap(lo, pivot_index);

    return pivot_index;

}

template<class T>
void QuickSort<T>::swap(unsigned long i, unsigned long j) {
    T temp = this->getVectorElement(i);
    this->setVectorElement(i, this->getVectorElement(j));
    this->setVectorElement(j, temp);
}

template<class T>
T QuickSort<T>::getVectorElement(unsigned long index) {
    return (*(this->pvec))[index];
}

template<class T>
void QuickSort<T>::setVectorElement(unsigned long index, T val) {
    (*(this->pvec))[index] = val;
}

template class QuickSort<int>;
template class QuickSort<double>;
