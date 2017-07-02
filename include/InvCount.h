#ifndef INVCOUNT_H
#define INVCOUNT_H

#include <vector>
#include "MergeSort.h"

template <class T>
class InvCount : public MergeSort<T> {

  public:
    InvCount() : MergeSort<T>(), lastMergeNumInv(0), numInvTotal(0) {  }
    virtual void sort(std::vector<T>* vec);
    int getNumberOfInversions();

  protected:
    virtual void onCopyFromSecondHalf(int lo, int mid, int hi, int k, int i, int j);

  private:
    int lastMergeNumInv;
    int numInvTotal;

    int sortAndInvCount(int lo, int hi);

};


#endif
