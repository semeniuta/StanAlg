#include <iostream>
#include "Heap.h"
#include "UniqueValuedHeap.h"

int main() {
    UniqueValuedHeap<int> my_heap;
    //Heap<int> my_heap;

    for (int x : std::vector<int>{ 11, 9, 13, 12, 4, 5, 8, 7, 6, 3, 14 }) {
        my_heap.insert(x);
        my_heap.printData();
        my_heap.printIndices();
    }

    std::cout << "Trying to remove number 13 \n";
    auto idx_of_num = my_heap.findIndex(13);

    std::cout << "Number 13 is at index " << idx_of_num << ". ";
    if (idx_of_num > 0) {
        std::cout << "Removing it\n";
        my_heap.remove( (unsigned long)idx_of_num );
        my_heap.printData();
    } else {
        std::cout << "\n";
    }

    std::cout << "Popping ... \n";
    while (my_heap.size() > 0) {
        std::cout << my_heap.pop() << std::endl;
        my_heap.printData();
    }


}