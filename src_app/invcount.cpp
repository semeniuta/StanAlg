#include <iostream>
#include <vector>
#include <string>
#include "argtools.h"
#include "InvCount.h"

using namespace std;

enum UserInput {from_file, from_stdin};

int main(int argc, char* argv[]) {

  // UserInput input;
  // if (argc == 1) {
  //   cout << "Reading data from stdin" << endl;
  //   input = from_stdin;
  // } else if (argc == 3) {
  //   string input_flag = getArg(argc, argv, 1);
  //   if (input_flag == "-f") {
  //     string filename = getArg(argc, argv, 2);
  //     cout << "Opening " << filename << endl;
  //     input = from_file;
  //   } else {
  //
  //   }
  // }

  vector<int> a = {10, 10, 4, 6, 2, 7, 1};

  InvCount <int>ic;
  ic.sort(&a);


  cout << "The sorted array:" << endl;
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  cout << "The number of inversions: ";
  cout << ic.getNumberOfInversions() << endl;

}
