#include <iostream>
#include "InvCount.h"

using namespace std;

int main(int argc, char** argv) {

  int a[5] = {4, 6, 2, 7, 1};

  InvCount <int> ic (5);

  ic.sort(a);


  cout << "The sorted array:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  cout << "The number of inversions: ";
  cout << ic.getNumberOfInversions() << endl;

}
