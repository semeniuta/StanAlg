#ifndef INVCOUNT_H
#define INVCOUNT_H

#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include "MergeSort.h"

namespace mp = boost::multiprecision;

template <class T>
class InvCount : public MergeSort<T> {

  public:
    InvCount() : MergeSort<T>(), lastMergeNumInv(0), numInvTotal(0) {  }
    virtual void sort(std::vector<T>* vec);
    mp::int128_t getNumberOfInversions();

  protected:
    virtual void onCopyFromSecondHalf(int lo, int mid, int hi, int k, int i, int j);

  private:
    mp::int128_t lastMergeNumInv;
    mp::int128_t numInvTotal;

    mp::int128_t sortAndInvCount(int lo, int hi);

};


#endif
