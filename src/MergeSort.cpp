#include "MergeSort.h"

template <class T>
MergeSort<T>::MergeSort(int size) {

  this->size = size;
  this->aux = new T[size];
  this->a = nullptr;

}

template <class T>
MergeSort<T>::~MergeSort() {
  delete this->aux;
}

template <class T>
void MergeSort<T>::sort(T* arr) {

  this->a = arr;
  sort(0, this->size-1);

}

template <class T>
void MergeSort<T>::sort(int lo, int hi) {

  if (lo >= hi) {
    return;
  }

  int mid = lo + (hi - lo) / 2;

  this->sort(lo, mid);
  this->sort(mid+1, hi);

  this->merge(lo, mid, hi);

}

template <class T>
void MergeSort<T>::merge(int lo, int mid, int hi) {

  for (int k = lo; k <= hi; k++) {
    this->aux[k] = this->a[k];
  }

  int i = lo;
  int j = mid+1;

  for (int k = lo; k <= hi; k++) {

    if (i > mid) {
      this->onCopyFromSecondHalf(lo, mid, hi, k, i, j);
      this->a[k] = this->aux[j++];
    } else if (j > hi) {
      this->onCopyFromFirstHalf(lo, mid, hi, k, i, j);
      this->a[k] = this->aux[i++];
    } else if (this->aux[i] <= this->aux[j]) {
      this->onCopyFromFirstHalf(lo, mid, hi, k, i, j);
      this->a[k] = this->aux[i++];
    } else {
      this->onCopyFromSecondHalf(lo, mid, hi, k, i, j);
      this->a[k] = this->aux[j++];
    }

  }

}

template <class T>
void MergeSort<T>::onCopyFromFirstHalf(int lo, int mid, int hi, int k, int i, int j) { }

template <class T>
void MergeSort<T>::onCopyFromSecondHalf(int lo, int mid, int hi, int k, int i, int j) { }

template class MergeSort<int>;
template class MergeSort<double>;
