#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "WeightedDigraph.h"
#include "DFS.h"
#include <algorithm>

const int NO_PATH_WEIGHT = 1000000;

class Dijkstra {

public:

    Dijkstra() = delete;
    Dijkstra(WeightedDigraph* g, int startVertex);
    void computeShortestPaths();

private:

    WeightedDigraph* graph;
    int start_vertex;
    std::map<int, bool> reachable;

};


class DijkstraPreprocessingDFS : public DFSDirected {

public:

    explicit DijkstraPreprocessingDFS(WeightedDigraph* g) : DFSDirected(g) {

        for (auto itr = g->adjMapBegin(); itr != g->adjMapEnd(); itr++) {
            this->reachable[itr->first] = false;
        }
    }

    std::map<int, bool> copyReachabilityMap() { return this->reachable; }

protected:
    void onExit(int currentVertex) override {  this->reachable[currentVertex] = true; }

private:
    std::map<int, bool> reachable;

};


#endif
