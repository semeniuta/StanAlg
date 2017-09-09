#include <iostream>
#include <vector>
#include "printutils.h"

using namespace std;

int main() {

    vector<int> vec = {0, 1, 2, 3, 4, 5};

    printVector(vec);

    vector<int>& vec1 = vec;
    vector<int> vec2 = vec1;
    vec1.push_back(20);
    printVector(vec);
    printVector(vec2);



}
