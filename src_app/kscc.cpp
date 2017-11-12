#include <iostream>
#include <algorithm>
#include <functional>
#include "ioutils.h"
#include "argtools.h"
#include "printutils.h"
#include "FileReader.h"
#include "Digraph.h"
#include "Kosaraju.h"


int main(int argc, char *argv[]) {

    std::cout << "kscc -- Kosaraju's algorithm for detection of strongly connected component in a directed graph" << std::endl;

    Digraph g;

    bool use_default_example = false;

    try {

        if (argc == 3) {

            if (getArg(argc, argv, 1) == "-f") {

                std::cout << "Reading the file and constructing Digraph\n";

                FileReader fr;
                string fname = getArg(argc, argv, 2);
                fr.open(fname);

                readDigraphFromFile(&fr, &g);

            } else {
                use_default_example = true;
            }

        } else {
            use_default_example = true;
        }

    } catch (exception& e) {

        std::cout << "Exception occured when reading file." << std::endl;
        use_default_example = true;

    }

    if (use_default_example) {

        std::cout << "Using the default example." << std::endl;

        vector<pair<int, int>> edges = {
                pair<int, int>(1, 5),
                pair<int, int>(5, 4),
                pair<int, int>(4, 1),
                pair<int, int>(2, 3),
                pair<int, int>(3, 6),
                pair<int, int>(6, 2),
                pair<int, int>(6, 7),
                pair<int, int>(7, 2),
                pair<int, int>(5, 2)

        };

        for (const pair<int, int>& p : edges) {
            g.addEdge(p.first, p.second);
        }

    }

    std::cout << "Detecting strongly connected components\n";
    std::map<int, vector<int>> components = kosarajuSCC(g);

    std::vector<unsigned long> scc_sizes;
    for (const auto& scc : components) {
        unsigned long size = scc.second.size();
        scc_sizes.push_back(size);
    }

    std::cout << "Sizes of the SCCs:\n";
    std::sort(scc_sizes.begin(), scc_sizes.end(), std::greater<>());
    printVector<unsigned long>(scc_sizes);



}
