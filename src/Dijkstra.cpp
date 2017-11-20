#include "Dijkstra.h"
#include <queue>

Dijkstra::Dijkstra(WeightedDigraph* g, int startVertex) : graph(g), start_vertex(startVertex) {

    DijkstraPreprocessingDFS preprocess(this->graph);
    preprocess.searchFrom(this->start_vertex);
    this->reachable = preprocess.copyReachabilityMap();

}

void Dijkstra::computeShortestPaths() {



}
