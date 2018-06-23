/*
 * Sort a sequence of integers using QuickSort algorithm.
 * The program is supplied with a path to a text file where
 * each line contains a single integer. To select the choose
 * pivot rule, one of the following flags is used:
 * --first, --median, --last
 *
 * Usage examples:
 * ./quicksort -f ../../data/QuickSort.txt --first
 * ./quicksort -f ../../data/QuickSort.txt --median
 * ./quicksort -f ../../data/QuickSort.txt --last
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "QuickSort.h"
#include "FileReader.h"
#include "argtools.h"

using namespace std;

int main(int argc, char *argv[]) {

    FileReader fr;
    vector<int> numbers;
    ChoosePivotRule cpr = medianOfThree;

    if (argc == 4) {

        if (getArg(argc, argv, 1) == "-f") {
            string fname = getArg(argc, argv, 2);

            fr.open(fname);

            string current_str;
            int current_number;
            while (!fr.eof()) {
                current_str = fr.readLine();
                if (!current_str.empty()) {
                    current_number = std::stoi(current_str);
                    numbers.push_back(current_number);
                }
            }

        }

        string third_arg = getArg(argc, argv, 3);
        if (third_arg == "--first" || third_arg == "--last" || third_arg == "--median") {
            if (third_arg == "--first") {
                cpr = first;
            } else if (third_arg == "--last") {
                cpr = last;
            } else {
                cpr = medianOfThree;
            }
        }

    } else {

        numbers = {4, 2, 3, 5, 1, 9, 8};

    }


    QuickSort<int> qs(cpr);

    auto num_compares = qs.sort(&numbers);

    for (auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Number of compares: " << num_compares << endl;

}
