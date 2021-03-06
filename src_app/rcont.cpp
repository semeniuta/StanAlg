/*
 * Compute size of min cut of an undirected graph
 * using the randomized contraction algorithm.
 * The graph is specified in a text file in the adjacency list form:
 * each line contains a number of integers separated by whitespaces;
 * the first integer specifies the target vertex index, and the rest
 * correspond to the vertices the target is adjacent to.
 *
 * Usage example:
 * ./rcont -f ../../data/kargerMinCut.txt
 *
 */

#include <iostream>
#include <vector>
#include "Graph.h"
#include "RandContract.h"
#include "FileReader.h"
#include "argtools.h"
#include "ioutils.h"

using namespace std;

int main(int argc, char *argv[]) {

    srand(time(nullptr));

    ContractableGraph g;

    if (argc == 3) {

        if (getArg(argc, argv, 1) == "-f") {

            FileReader fr;
            string fname = getArg(argc, argv, 2);
            fr.open(fname);

            readGraphFromFile(&fr, &g);
        }

    } else {

        vector<pair<int, int>> edges = {
                pair<int, int>(0, 1),
                pair<int, int>(1, 2),
                pair<int, int>(2, 0),
                pair<int, int>(1, 3),
                pair<int, int>(3, 4),
                pair<int, int>(3, 7),
                pair<int, int>(4, 5),
                pair<int, int>(5, 6),
                pair<int, int>(6, 7),
                pair<int, int>(4, 6),
                pair<int, int>(7, 5),
                pair<int, int>(8, 1),
                pair<int, int>(8, 0),
                pair<int, int>(8, 2)
        };

        for (const pair<int, int> &p : edges) {
            g.addEdge(p.first, p.second);
        }

    }

    RandomContraction rc(&g);

    int nc;
    int nc_min = g.countEdges();
    for (int i = 0; i < 200; i++) {
        cout << nc << " ";
        nc = rc.doContraction();
        if (nc < nc_min) {
            nc_min = nc;
        }
    }

    cout << "\nMin cut size: " << nc_min << endl;

    return 0;
}
