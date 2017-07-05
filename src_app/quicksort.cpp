#include <iostream>
#include "QuickSort.h"

using namespace std;

int main(int argc, char* argv[]) {

  vector<int> a = {10, 4, 6, 2, 7, 1};

  QuickSort<int> qs;

  qs.sort(&a);

  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;

}
