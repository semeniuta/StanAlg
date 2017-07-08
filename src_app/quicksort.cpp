#include <iostream>
#include <vector>
#include "QuickSort.h"

using namespace std;

int main(int argc, char* argv[]) {

  vector<int> a = {4, 2, 3, 5, 1, 9, 8};

  QuickSort<int> qs;

  int num_compares;
  num_compares = qs.sort(&a);

  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  cout << "Number of compares: " << num_compares << endl;

}
