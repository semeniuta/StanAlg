#include "DFS.h"
#include "Graph.h"
#include <map>

DFS::DFS(Graph* g) {

    this->graph = g;

    for (auto itr = this->graph->adjMapBegin(); itr != this->graph->adjMapEnd(); itr++) {
        int key = itr->first;
        this->explored[key] = false;
    }

}

void DFS::searchFrom(int startVertex) {

    this->onEntry(startVertex);

    this->explored[startVertex] = true;

    list<AdjacentVertex>& adj = this->graph->getListofAdjacentVertices(startVertex);

    for (AdjacentVertex& neighbor : adj) {
        int next_vertex = neighbor.w;
        if (!this->explored[next_vertex]) {
            this->searchFrom(next_vertex);
        }
    }

    this->onExit(startVertex);

}
