#include <iostream>
#include "MergeSort.h"

using namespace std;

int main() {

  int a[5] = {4, 6, 2, 7, 1};

  //MergeSort<int>* ms = new MergeSort<int>(a, 5);

  //delete ms;

  MergeSort <int> ms (5);

  ms.sort(a);

  for (int i = 0; i < 5; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

}
