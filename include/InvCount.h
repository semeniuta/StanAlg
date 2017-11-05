#ifndef INVCOUNT_H
#define INVCOUNT_H

#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include "MergeSort.h"

namespace mp = boost::multiprecision;

template<class T>
class InvCount : public MergeSort<T> {

public:
    InvCount() : MergeSort<T>(), lastMergeNumInv(0), numInvTotal(0) {}

    virtual void sort(std::vector<T> *vec);

    mp::int128_t getNumberOfInversions();

protected:
    virtual void onCopyFromSecondHalf(
            unsigned long lo,
            unsigned long mid,
            unsigned long hi,
            unsigned long k,
            unsigned long i,
            unsigned long j
    );

private:
    mp::int128_t lastMergeNumInv;
    mp::int128_t numInvTotal;

    mp::int128_t sortAndInvCount(unsigned long lo, unsigned long hi);

};


#endif
