#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template <class T>
class MergeSort {

  public:
    MergeSort();
    ~MergeSort();
    virtual void sort(std::vector<T>* vec);

  protected:
    std::vector<T>* pvec;
    T* aux;
    int size;

    void merge(int lo, int mid, int hi);

    virtual void onCopyFromFirstHalf(int lo, int mid, int hi, int k, int i, int j);
    virtual void onCopyFromSecondHalf(int lo, int mid, int hi, int k, int i, int j);

  private:
    void sort(int lo, int hi);
    T getVectorElement(int index);
    void setVectorElement(int index, T val);

};


#endif
