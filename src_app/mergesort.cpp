#include <iostream>
#include "MergeSort.h"

using namespace std;

int main(int argc, char* argv[]) {

  vector<int> a = {4, 6, 2, 7, 1};

  MergeSort<int> ms;

  ms.sort(&a);

  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;

}
