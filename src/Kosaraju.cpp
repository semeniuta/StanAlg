#include "Kosaraju.h"
#include "Digraph.h"
#include <map>
#include <vector>

using namespace std;

void kosarajuComputeFinishingTimes(Digraph* g, Digraph* graphF, map<int, int>& f) {

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

        graphF->addEdge(f[v], f[w]);
    }

}

void kosarajuDetermineLeaders(Digraph* graphF, map<int, int>& leaderMap) {

    vector<int> vertices_desc;
    graphF->getVerticesVector(vertices_desc, false);

    int s;

    DFSKosarajuLeaders dfs_lead(graphF, &s, leaderMap);

    for (int& v : vertices_desc) {

        if (!dfs_lead.isExplored(v)) {
            s = v;
            dfs_lead.searchFrom(v);
        }

    }

}
