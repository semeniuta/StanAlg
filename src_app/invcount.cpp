/*
 * Count number of inversions in a sequence of integers.
 * The program is supplied with a path to a text file where
 * each line contains a single integer.
 *
 * Usage example:
 * ./invcount -f ../../data/IntegerArray.txt
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "argtools.h"
#include "FileReader.h"
#include "InvCount.h"

using namespace std;

int main(int argc, char *argv[]) {

    FileReader fr;
    vector<int> numbers;

    if (argc == 3) {
        if (getArg(argc, argv, 1) == "-f") {
            string fname = getArg(argc, argv, 2);

            fr.open(fname);

            string current_str;
            int current_number;
            while (!fr.eof()) {
                current_str = fr.readLine();
                if (current_str.length() != 0) {
                    current_number = atoi(current_str.c_str());
                    numbers.push_back(current_number);
                }
            }

        }
    } else {
        numbers = {10, 4, 6, 2, 7, 1};
    }

    InvCount<int> ic;
    ic.sort(&numbers);


    cout << "The sorted array:" << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "The number of inversions: ";
    cout << ic.getNumberOfInversions() << endl;

}
