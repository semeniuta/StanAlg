#include "Digraph.h"

void Graph::addAdjacencyInfo(int v, int w, int edgeIndex) {
  this->adj[v].push_back({w, edgeIndex});
}

