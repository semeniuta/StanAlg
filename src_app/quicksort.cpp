#include <iostream>
#include <vector>
#include "QuickSort.h"
#include "FileReader.h"
#include "argtools.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  FileReader fr;
  vector<int> numbers;
  ChoosePivotRule cpr = medianOfThree;
  
  if (argc == 4) {
    
    if (getArg(argc, argv, 1) == "-f") {
      string fname = getArg(argc, argv, 2);
      
      fr.open(fname);
      
      string current_str;
      int current_number;
      while (!fr.eof()) {
        current_str = fr.readLine();
        if (current_str.length() != 0) {
          current_number = atoi(current_str.c_str());
          numbers.push_back(current_number);
        }
      }
      
    }
    
    string third_arg = getArg(argc, argv, 3);
    if (third_arg == "--first" || third_arg == "--last" || third_arg == "--median") {
      if (third_arg == "--first") {
        cpr = first;
      } else if (third_arg == "--last") {
        cpr = last;
      } else {
        cpr = medianOfThree;
      }
    }
    
  } else {
    
    numbers = {4, 2, 3, 5, 1, 9, 8};
    
  }


  QuickSort<int> qs(cpr);

  int num_compares;
  num_compares = qs.sort(&numbers);

  for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;

  cout << "Number of compares: " << num_compares << endl;

}
