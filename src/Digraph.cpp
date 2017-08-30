#include "Digraph.h"

void Digraph::addAdjacencyInfo(int v, int w, int edgeIndex) {

    this->adj[v].push_back({w, edgeIndex});
}
