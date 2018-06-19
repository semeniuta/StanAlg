#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "Heap.h"
#include "DynamicMedian.h"

int main() {

    std::vector<int> numbers = {5, 4, 3, 1, 6, 2, 7, 8, 15, 2};

    std::cout << "Standard std::priority_queue\n";

    std::priority_queue<int, std::vector<int>, std::greater<>> heap;
    for (const auto& num : numbers) {
        heap.push(num);
    }

    while (!heap.empty()) {
        std::cout << heap.top() << std::endl;
        heap.pop();
    }

    std::cout << "My heap\n";

    //Heap<int, bool> myheap { [](int a, int b){ return a >= b; } };
    Heap<int, bool> myheap { std::less_equal<>() };
    for (const auto& num : numbers) {
        myheap.insert(num, true);
    }

    while (!myheap.empty()) {

        auto top = myheap.pop();

        std::cout << top.key << std::endl;

    }

    std::cout << "DynamicMedian\n";

    DynamicMedian<int> dm;
    for (const auto& num : numbers) {
        dm.insert(num);
        std::cout << "Inserted " << num << ", median = " << dm.median() << std::endl;
        dm.printData();
    }


}