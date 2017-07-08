#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

enum ChoosePivotRule { first, last, medianOfThree };

template <class T>
class QuickSort {

  public:
    QuickSort();
    QuickSort(ChoosePivotRule cpr);
    ~QuickSort();
    virtual int sort(std::vector<T>* vec);

  protected:
    virtual int choosePivot(int lo, int hi);

  private:
    std::vector<T>* pvec;
    ChoosePivotRule choose_pivot_rule;

    int sort(int lo, int hi);
    int partition(int lo, int hi);
    void swap(int i, int j);

    T getVectorElement(int index);
    void setVectorElement(int index, T val);

};

#endif
