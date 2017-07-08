#include <vector>
#include "QuickSort.h"

template <class T>
QuickSort<T>::QuickSort() : choose_pivot_rule(medianOfThree) {
  this->pvec = nullptr;
}

template <class T>
QuickSort<T>::QuickSort(ChoosePivotRule cpr) {
  this->choose_pivot_rule = cpr;
}

template <class T>
QuickSort<T>::~QuickSort() { }

template <class T>
int QuickSort<T>::sort(std::vector<T>* vec) {
  this->pvec = vec;

  int num_compares;
  num_compares = this->sort(0, this->pvec->size()-1);

  return num_compares;
}

template <class T>
int QuickSort<T>::sort(int lo, int hi) {

  if (lo >= hi) {
    return 0;
  }

  int initial_pivot_index = this->choosePivot(lo, hi);
  this->swap(lo, initial_pivot_index);
  int pivot_index = this->partition(lo, hi);

  int num_compares_1, num_compares_2;
  num_compares_1 = this->sort(lo, pivot_index-1);
  num_compares_2 = this->sort(pivot_index+1, hi);

  return num_compares_1 + num_compares_2 + (hi - lo);

}

template <class T>
int QuickSort<T>::choosePivot(int lo, int hi) {

  switch (this->choose_pivot_rule) {

    case medianOfThree: {
      int len = hi - lo + 1;
      
      int mid;
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
      
      int median = 0;
      for (int i = 0; i < 3; i++) {
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

    case first: return lo;

    case last: return hi;

  }
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
