#include <vector>
#include "QuickSort.h"

template <class T>
QuickSort<T>::QuickSort() {
  this->pvec = nullptr;
}

template <class T>
QuickSort<T>::~QuickSort() { }

template <class T>
void QuickSort<T>::sort(std::vector<T>* vec) {
  this->pvec = vec;

  this->sort(0, this->pvec->size()-1);
}

template <class T>
void QuickSort<T>::sort(int lo, int hi) {

  if (lo >= hi) {
    return;
  }

  int initial_pivot_index = this->choosePivot(lo, hi);
  this->swap(lo, initial_pivot_index);
  int pivot_index = this->partition(lo, hi);

  this->sort(lo, pivot_index-1);
  this->sort(pivot_index+1, hi);

}

template <class T>
int QuickSort<T>::choosePivot(int lo, int hi) {
  return lo;
}

template <class T>
int QuickSort<T>::partition(int lo, int hi) {

  T p = this->getVectorElement(lo);

  int i = lo + 1;

  for (int j = lo + 1; j <= hi; j++) {
    if (this->getVectorElement(j) < p) {
      this->swap(i, j);
      i++;
    }
  }

  int pivot_index = i - 1;
  this->swap(lo, pivot_index);

  return pivot_index;

}

template <class T>
void QuickSort<T>::swap(int i, int j) {
  T temp = this->getVectorElement(i);
  this->setVectorElement(i, this->getVectorElement(j));
  this->setVectorElement(j, temp);
}

template <class T>
T QuickSort<T>::getVectorElement(int index) {
  return (*(this->pvec))[index];
}

template <class T>
void QuickSort<T>::setVectorElement(int index, T val) {
  (*(this->pvec))[index] = val;
}

template class QuickSort<int>;
template class QuickSort<double>;
