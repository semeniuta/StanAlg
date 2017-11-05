#include "MergeSort.h"
#include <iostream>

template<class T>
MergeSort<T>::MergeSort() {

    this->size = 0;
    this->pvec = nullptr;
    this->aux = nullptr;

}

template<class T>
MergeSort<T>::~MergeSort() {
    delete this->aux;
    this->aux = nullptr;
}

template<class T>
void MergeSort<T>::sort(std::vector<T> *vec) {

    this->pvec = vec;
    this->size = vec->size();

    delete this->aux;
    this->aux = new T[this->size];

    sort(0, this->size - 1);

    for (unsigned int i = 0; i < this->size; i++) {
        std::cout << this->getVectorElement(i) << " ";
    }
    std::cout << std::endl;

}

template<class T>
void MergeSort<T>::sort(unsigned long lo, unsigned long hi) {

    if (lo >= hi) {
        return;
    }

    auto mid = lo + (hi - lo) / 2;

    this->sort(lo, mid);
    this->sort(mid + 1, hi);

    this->merge(lo, mid, hi);

}

template<class T>
void MergeSort<T>::merge(unsigned long lo, unsigned long mid, unsigned long hi) {

    for (auto k = lo; k <= hi; k++) {
        this->aux[k] = this->getVectorElement(k);
    }

    auto i = lo;
    auto j = mid + 1;

    for (auto k = lo; k <= hi; k++) {

        if (i > mid) {
            this->onCopyFromSecondHalf(lo, mid, hi, k, i, j);
            this->setVectorElement(k, this->aux[j++]);
        } else if (j > hi) {
            this->onCopyFromFirstHalf(lo, mid, hi, k, i, j);
            this->setVectorElement(k, this->aux[i++]);
        } else if (this->aux[i] <= this->aux[j]) {
            this->onCopyFromFirstHalf(lo, mid, hi, k, i, j);
            this->setVectorElement(k, this->aux[i++]);
        } else {
            this->onCopyFromSecondHalf(lo, mid, hi, k, i, j);
            this->setVectorElement(k, this->aux[j++]);
        }

    }

}

template<class T>
T MergeSort<T>::getVectorElement(unsigned long index) {
    return (*(this->pvec))[index];
}

template<class T>
void MergeSort<T>::setVectorElement(unsigned long index, T val) {
    (*(this->pvec))[index] = val;
}

template<class T>
void MergeSort<T>::onCopyFromFirstHalf(
        unsigned long lo,
        unsigned long mid,
        unsigned long hi,
        unsigned long k,
        unsigned long i,
        unsigned long j
) {}

template<class T>
void MergeSort<T>::onCopyFromSecondHalf(
        unsigned long lo,
        unsigned long mid,
        unsigned long hi,
        unsigned long k,
        unsigned long i,
        unsigned long j
) {}

template
class MergeSort<int>;

template
class MergeSort<double>;
