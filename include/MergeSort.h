#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template<class T>
class MergeSort {

public:

    MergeSort();

    ~MergeSort();

    virtual void sort(std::vector<T> *vec);

protected:

    std::vector<T> *pvec;
    T *aux;
    unsigned long size;

    void merge(unsigned long lo, unsigned long mid, unsigned long hi);

    virtual void onCopyFromFirstHalf(
            unsigned long lo,
            unsigned long mid,
            unsigned long hi,
            unsigned long k,
            unsigned long i,
            unsigned long j
    );

    virtual void onCopyFromSecondHalf(
            unsigned long lo,
            unsigned long mid,
            unsigned long hi,
            unsigned long k,
            unsigned long i,
            unsigned long j
    );

private:

    void sort(unsigned long lo, unsigned long hi);

    T getVectorElement(unsigned long index);

    void setVectorElement(unsigned long index, T val);

};


#endif
