#include "Kosaraju.h"
#include "Digraph.h"
#include <map>
#include <vector>

using namespace std;

void kosarajuComputeFinishingTimes(Digraph* g, Digraph* resG, map<int, int>& f) {

    vector<int> vertices_desc;
    g->getVerticesVector(vertices_desc, false);

    DFSKosarajuFinishingTimes dfs_ft(g, f);

    for (int& v : vertices_desc) {

        if (!dfs_ft.isExplored(v)) {
            dfs_ft.reverseSearchFrom(v);
        }

    }

    int v, w;
    for (auto itr = g->edgesMapBegin(); itr != g->edgesMapEnd(); itr++) {

        v = itr->second.first;
        w = itr->second.second;

        resG->addEdge(f[v], f[w]);
    }



}
