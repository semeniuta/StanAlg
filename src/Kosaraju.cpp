#include "Kosaraju.h"
#include "Digraph.h"
#include <map>
#include <vector>

std::map<int, std::vector<int>> kosarajuSCC(Digraph& g) {

    std::map<int, int> f;
    Digraph graph_ftimes;

    kosarajuComputeFinishingTimes(&g, &graph_ftimes, f);

    std::map<int, int> leaders;
    kosarajuDetermineLeaders(&graph_ftimes, leaders);

    std::map<int, std::vector<int>> components;

    for (const auto& p : f) {

        int vertex = p.first;
        int finishing_time = p.second;
        int leader = leaders.at(finishing_time);

        if (components.find(leader) == components.end()) {
            components[leader] = std::vector<int>{ vertex };
        } else {
            components.at(leader).push_back(vertex);
        }

    }

    return components;

}

void kosarajuComputeFinishingTimes(Digraph* g, Digraph* graphF, std::map<int, int>& f) {

    std::vector<int> vertices = g->getVerticesVector();

    DFSKosarajuFinishingTimes dfs_ft(g, f);

    for (int& v : vertices) {

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

void kosarajuDetermineLeaders(Digraph *graphF, std::map<int, int>& leaderMap) {

    std::vector<int> vertices_desc = graphF->getVerticesVector(false);

    int s;

    DFSKosarajuLeaders dfs_lead(graphF, &s, leaderMap);

    for (int& v : vertices_desc) {

        if (!dfs_lead.isExplored(v)) {
            s = v;
            dfs_lead.searchFrom(v);
        }

    }

}
