#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include "InvCount.h"

namespace mp = boost::multiprecision;

template<class T>
void InvCount<T>::onCopyFromSecondHalf(
        unsigned long lo,
        unsigned long mid,
        unsigned long hi,
        unsigned long k,
        unsigned long i,
        unsigned long j
) {

    auto numInv = mid - i + 1;
    this->lastMergeNumInv += numInv;

};

template<class T>
void InvCount<T>::sort(std::vector<T> *vec) {

    this->pvec = vec;
    this->size = vec->size();

    delete this->aux;
    this->aux = new T[this->size];

    this->numInvTotal = sortAndInvCount(0, this->size - 1);

}

template<class T>
mp::int128_t InvCount<T>::sortAndInvCount(unsigned long lo, unsigned long hi) {

    if (lo >= hi) {
        return 0;
    }

    auto mid = lo + (hi - lo) / 2;

    mp::int128_t A = this->sortAndInvCount(lo, mid);
    mp::int128_t B = this->sortAndInvCount(mid + 1, hi);

    this->merge(lo, mid, hi);

    mp::int128_t C = this->lastMergeNumInv;
    this->lastMergeNumInv = 0;

    mp::int128_t this_sort_invcount = A + B + C;
    return this_sort_invcount;

}

template<class T>
mp::int128_t InvCount<T>::getNumberOfInversions() {
    return this->numInvTotal;
}

template class InvCount<int>;
template class InvCount<double>;
