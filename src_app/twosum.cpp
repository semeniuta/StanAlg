#include <iostream>
#include <vector>
#include "TwoSum.h"
#include "FileReader.h"

int main(int argc, char *argv[]) {

    const std::string fname = "../../data/algo1-programming_prob-2sum.txt";
    const long RANGE_FROM = -10000;
    const long RANGE_TO   =  10000;

    FileReader fr;
    fr.open(fname);

    std::vector<long> numbers;
    while (!fr.eof()) {

        std::string line = fr.readLine();
        if (!line.empty()) {
            long num = std::stol(line);
            numbers.push_back(num);
        }
    }

    TwoSum<long> twosum {numbers};
    long total = 0;

    for (auto i = RANGE_FROM; i <= RANGE_TO; i++) {

        std::cout << "i=" << i << std::endl;

        auto pairs = twosum.check(i);

        for (const auto& pair : pairs) {
            std::cout << pair.first << ", " << pair.second << std::endl;
        }

        std::cout << "Size: " << pairs.size() << std::endl;

        if (!pairs.empty()) {
            total++;
        }

    }

    std::cout << "Total: " << total << std::endl;

}