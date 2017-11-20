#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <vector>
#include <map>

template <typename T>
void printVector(std::vector<T>& vec);

template <typename K, typename V>
void printMap(std::map<K, V>& m);

#endif
