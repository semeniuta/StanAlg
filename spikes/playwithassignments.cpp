#include <iostream>
#include <vector>
#include "printutils.h"

using namespace std;

int main() {

    vector<int> vec = {0, 1, 2, 3, 4, 5};

    printVector(vec, vec.size());

    vector<int>& vec1 = vec;
    vector<int> vec2 = vec1;
    vec1.push_back(20);
    printVector(vec, vec.size());
    printVector(vec2, vec1.size());



}
