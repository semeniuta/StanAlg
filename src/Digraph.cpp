#include "Digraph.h"

void Digraph::addAdjacencyInfo(int v, int w, int edgeIndex) {

    this->adj[v].push_back({w, edgeIndex});
    this->adjReverse[w].push_back({v, edgeIndex});
}

list<AdjacentVertex> &Digraph::getListOfReverseAdjacentVertices(int v) {

    list<AdjacentVertex> &adj_list_rev = this->adjReverse[v];
    return adj_list_rev;

}

void Digraph::printReversedGraph() {

    this->printAdj(this->adjReverse);

}
