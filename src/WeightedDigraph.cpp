#include "WeightedDigraph.h"

int WeightedDigraph::addEdge(int v, int w) {

    return this->addEdge(v, w, DEFAULT_EDGE_WEIGHT);

}

int WeightedDigraph::addEdge(int v, int w, int weight) {

    int edge_idx = Digraph::addEdge(v, w);

    this->edge_weights[{v, w}] = weight;

    return edge_idx;

}

int WeightedDigraph::getWeight(int v, int w) {

    auto itr = this->edge_weights.find({v, w});

    if (itr == this->edge_weights.end()) {
        throw std::invalid_argument("Wrong edge");
    }

    return itr->second;

}
