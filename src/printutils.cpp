#include <iostream>
#include <vector>
#include <map>
#include "printutils.h"

void printArray(int *array, int size) {

    std::cout << "[";
    for (int i = 0; i < size - 1; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << array[size - 1] << "]" << std::endl;

}

void printVector(std::vector<int>& vec) {

    int size = vec.size();
    std::cout << "[";
    for (int i = 0; i < size - 1; i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[size - 1] << "]" << std::endl;

}

void printMap(std::map<int, int>& m) {

    std::cout << "{" << std::endl;

    for (auto itr = m.begin(); itr != m.end(); itr++) {
        std::cout << "  " << itr->first << "->" << itr->second << std::endl;
    }
    std::cout << "}" << std::endl;

}
