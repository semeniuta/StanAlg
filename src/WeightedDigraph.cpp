#include "WeightedDigraph.h"

int WeightedDigraph::addEdge(int v, int w) {

    return this->addEdge(v, w, DEFAULT_EDGE_WEIGHT);

}

int WeightedDigraph::addEdge(int v, int w, int weight) {

    int edge_idx = Digraph::addEdge(v, w);

    this->edge_weights[edge_idx] = weight;

    return edge_idx;

}

int WeightedDigraph::getWeight(int edgeIndex) {

    auto itr = this->edge_weights.find(edgeIndex);

    if (itr == this->edge_weights.end()) {
        throw std::invalid_argument("Wrong edge index");
    }

    return itr->second;

}
