#include "ContractableGraph.h"
#include <iostream>

using namespace std;

int ContractableGraph::contractEdge(int edgeIndex) {

    // Returns 0 if successful

    if (!this->edgeExists(edgeIndex)) {
        cout << "Invalid edge index provided" << endl;
        return -1;
    }

    pair<int, int> endpoints = this->edgeEndpoints(edgeIndex);

    int v_keep = endpoints.first;
    int v_away = endpoints.second;

    this->edges.erase(edgeIndex);
    this->shrinkAdjOnContraction(v_keep, v_away);
    this->renameInEdgesMapOnContraction(v_keep, v_away);
    this->removeSelfLoopsAfterContraction(v_keep, v_away);

    return 0;

}

void ContractableGraph::shrinkAdjOnContraction(int v_keep, int v_away) {

    // Copy the adjacency list from the vertex that is going away

    for (const AdjacentVertex& a : this->adj[v_away]) {
        this->adj[v_keep].push_back(a);
    }
    this->adj.erase(v_away);
    this->num_vertices--;

}

void ContractableGraph::renameInEdgesMapOnContraction(int v_keep, int v_away) {

    // Rename in edges map

    for (const pair<int, pair<int, int>>& e : this->edges) {
        int key = e.first;
        int a = e.second.first;
        int b = e.second.second;

        if (a == v_away) {
            this->edges[key].first = v_keep;
        }

        if (b == v_away) {
            this->edges[key].second = v_keep;
        }

    }

}

void ContractableGraph::removeSelfLoopsAfterContraction(int v_keep, int v_away) {

    int cycles_removed = 0;
    for (AdjMapIterator ami = this->adj.begin(); ami != this->adj.end(); ami++) {

        int v = ami->first;
        list<AdjacentVertex>& v_adj = ami->second;

        // rename
        for (AdjacentVertex& a : v_adj) {
            if (a.w == v_away) {
                a.w = v_keep;
            }
        }

        // remove self-loop
        for (list<AdjacentVertex>::iterator ptr_w = v_adj.begin(); ptr_w != v_adj.end(); /* No increment */) {

            int w = ptr_w->w;

            if (w == v) {

                int edge_index_to_remove = ptr_w->edgeIndex;
                if (this->edgeExists(edge_index_to_remove)) {
                    this->edges.erase(edge_index_to_remove);
                }

                ptr_w = v_adj.erase(ptr_w);

                cycles_removed++;
            } else {
                ptr_w++;
            }
        }

    }

    this->num_edges -= (cycles_removed / 2);

}
