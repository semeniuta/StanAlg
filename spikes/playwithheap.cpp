#include <iostream>
#include "Heap.h"
#include "UniqueValuedHeap.h"

int main() {
    UniqueValuedHeap<int, int> my_heap;
    //Heap<int> my_heap;

    for (int x : std::vector<int>{ 11, 9, 13, 12, 4, 5, 8, 7, 6, 3, 14 }) {
        my_heap.insert(x, x);
        my_heap.printData();
        my_heap.printIndices();
    }

    std::cout << "\n# Removing element by value demo\n";

    int number_to_remove = 4;
    std::cout << "Trying to remove number " << number_to_remove << "\n";
    auto idx_of_num = my_heap.findIndex(number_to_remove);

    std::cout << "Number 4 is at index " << idx_of_num << ". ";
    if (idx_of_num > 0) {
        std::cout << "Removing it\n";
        if (idx_of_num >= 0) {
            my_heap.remove( (unsigned long)idx_of_num );
            my_heap.printData();
        }
    } else {
        std::cout << "\n";
    }

    std::cout << "# Popping heap root demo\n";

    while (my_heap.size() > 0) {
        std::cout << my_heap.pop().value << std::endl;
        my_heap.printData();
    }


}