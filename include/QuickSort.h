#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

enum ChoosePivotRule {
    first, last, medianOfThree
};

template<class T>
class QuickSort {

public:

    QuickSort();

    explicit QuickSort(ChoosePivotRule cpr);

    virtual unsigned long sort(std::vector<T> *vec);

protected:

    virtual unsigned long choosePivot(unsigned long lo, unsigned long hi);

private:

    std::vector<T> *pvec;
    ChoosePivotRule choose_pivot_rule;

    unsigned long sort(unsigned long lo, unsigned long hi);

    unsigned long partition(unsigned long lo, unsigned long hi);

    void swap(unsigned long i, unsigned long j);

    T getVectorElement(unsigned long index);

    void setVectorElement(unsigned long index, T val);

};

#endif
