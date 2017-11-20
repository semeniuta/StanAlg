#ifndef WEIGHTEDDIGRAPH_H
#define WEIGHTEDDIGRAPH_H

#include "Digraph.h"
#include <map>

const int DEFAULT_EDGE_WEIGHT = 1;

class WeightedDigraph : public Digraph {

public:
    int addEdge(int v, int w) override;
    int addEdge(int v, int w, int weight);
    int getWeight(int edgeIndex);

private:
    std::map<int, int> edge_weights;

};


#endif
