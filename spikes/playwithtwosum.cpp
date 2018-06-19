#include <iostream>
#include <vector>
#include "TwoSum.h"

int main(int argc, char *argv[]) {

    TwoSum<long> twosum {
            std::vector<long> {1, 2, 3, 4, 5, 1, 6}
    };

    auto pairs = twosum.check(6);

    for (const auto& pair : pairs) {
        std::cout << pair.first << ", " << pair.second << std::endl;
    }


}