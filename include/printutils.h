#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <vector>
#include <map>

void printArray(int *array, int size);

void printVector(std::vector<int>& vec); // temporarily

template <typename T>
void printVector(std::vector<T>& vec);

void printMap(std::map<int, int>& m);

#endif
