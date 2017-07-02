#include <iostream>
#include <vector>
#include "InvCount.h"

using namespace std;

int main(int argc, char** argv) {

  vector<int> a = {10, 4, 6, 2, 7, 1};

  InvCount <int> ic;
  ic.sort(&a);


  cout << "The sorted array:" << endl;
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  cout << "The number of inversions: ";
  cout << ic.getNumberOfInversions() << endl;

}
