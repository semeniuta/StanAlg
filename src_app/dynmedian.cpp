#include <iostream>
#include <string>
#include "DynamicMedian.h"
#include "FileReader.h"

int main(int argc, char *argv[]) {

    const std::string fname = "../../data/Median.txt";

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

    DynamicMedian<long> dm;
    long sum_of_medians = 0;

    for (const auto& num : numbers) {
        dm.insert(num);
        sum_of_medians += dm.median();
    }

    std::cout << "Sum of medians: " << sum_of_medians << std::endl;
    std::cout << "Sum of medians % 10K: " << sum_of_medians % 10000 << std::endl;


}


