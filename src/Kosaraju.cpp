#include "Kosaraju.h"
#include <map>
#include <vector>

using namespace std;

#include "QuickSort.h"

void kosarajuComputeFinishingTimes(Digraph* g, Digraph* res) {

    int t = 0;
    map<int, int> f;

    vector<int> vertices_desc;
    g->getVerticesVector(vertices_desc, false);

    DFSKosarajuFinishingTimes dfs_ft(g, &t, f);

    for (int& v : vertices_desc) {
        dfs_ft.reverseSearchFrom(v);
    }



}
