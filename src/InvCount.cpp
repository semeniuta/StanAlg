#include <vector>
#include "InvCount.h"

template <class T>
void InvCount<T>::onCopyFromSecondHalf(int lo, int mid, int hi, int k, int i, int j) {

  int numInv = mid - i + 1;
  this->lastMergeNumInv += numInv;

};

template <class T>
void InvCount<T>::sort(std::vector<T>* vec) {

  this->pvec = vec;
  this->size = vec->size();

  if (!(this->aux == nullptr)) {
    delete this->aux;
  }
  this->aux = new T[this->size];

  this->numInvTotal = sortAndInvCount(0, this->size-1);

}

template <class T>
int InvCount<T>::sortAndInvCount(int lo, int hi) {

  if (lo >= hi) {
    return 0;
  }

  int mid = lo + (hi - lo) / 2;

  int A = this->sortAndInvCount(lo, mid);
  int B = this->sortAndInvCount(mid+1, hi);

  this->merge(lo, mid, hi);

  int C = this->lastMergeNumInv;
  this->lastMergeNumInv = 0;

  return A + B + C;

}

template <class T>
int InvCount<T>::getNumberOfInversions() {
  return this->numInvTotal;
}

template class InvCount<int>;
template class InvCount<double>;
