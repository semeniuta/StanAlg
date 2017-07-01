#include <iostream>
#include <vector>
#include "printutils.h"

void printArray(int* array, int size) {
  std::cout << "[";
  for (int i = 0; i < size-1; i++) {
    std::cout << array[i] << ", ";
  }
  std::cout << array[size-1] << "]" << std::endl;
}

void printVector(std::vector<int> vec, int size) {
  std::cout << "[";
  for (int i = 0; i < size-1; i++) {
    std::cout << vec[i] << ", ";
  }
  std::cout << vec[size-1] << "]" << std::endl;
}
