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

    if (!(this->aux == nullptr)) {
        delete this->aux;
    }
    this->aux = new T[this->size];

    sort(0, this->size - 1);

    for (int i = 0; i < this->size; i++) {
        std::cout << this->getVectorElement(i) << " ";
    }
    std::cout << std::endl;

}

template<class T>
void MergeSort<T>::sort(int lo, int hi) {

    if (lo >= hi) {
        return;
    }

    int mid = lo + (hi - lo) / 2;

    this->sort(lo, mid);
    this->sort(mid + 1, hi);

    this->merge(lo, mid, hi);

}

template<class T>
void MergeSort<T>::merge(int lo, int mid, int hi) {

    for (int k = lo; k <= hi; k++) {
        this->aux[k] = this->getVectorElement(k);
    }

    int i = lo;
    int j = mid + 1;

    for (int k = lo; k <= hi; k++) {

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
T MergeSort<T>::getVectorElement(int index) {
    return (*(this->pvec))[index];
}

template<class T>
void MergeSort<T>::setVectorElement(int index, T val) {
    (*(this->pvec))[index] = val;
}

template<class T>
void MergeSort<T>::onCopyFromFirstHalf(int lo, int mid, int hi, int k, int i, int j) {}

template<class T>
void MergeSort<T>::onCopyFromSecondHalf(int lo, int mid, int hi, int k, int i, int j) {}

template
class MergeSort<int>;

template
class MergeSort<double>;
