#ifndef MERGESORT_H
#define MERGESORT_H

template <class T>
class MergeSort {

  public:
    MergeSort(int size);
    ~MergeSort();
    virtual void sort(T* arr);

  protected:
    T* a;
    T* aux;
    int size;

    void merge(int lo, int mid, int hi);

    virtual void onCopyFromFirstHalf(int lo, int mid, int hi, int k, int i, int j);
    virtual void onCopyFromSecondHalf(int lo, int mid, int hi, int k, int i, int j);

  private:
    void sort(int lo, int hi);

};


#endif
