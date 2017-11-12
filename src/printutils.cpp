#include <iostream>
#include <vector>
#include <map>
#include "printutils.h"

template <typename T>
void printVector(std::vector<T>& vec) {

    auto size = vec.size();
    std::cout << "[";
    for (auto i = 0; i < size - 1; i++) {
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

template void printVector<int>(std::vector<int>&);
template void printVector<unsigned long>(std::vector<unsigned long>&);
