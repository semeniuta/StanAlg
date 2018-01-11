#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "WeightedDigraph.h"
#include "UniqueValuedHeap.h"
#include "DFS.h"
#include <set>

const int NO_PATH_WEIGHT = 1000000;

struct UnprocessedVertex {
    int index;
    int score;
};

class Dijkstra {

public:

    Dijkstra() = delete;
    Dijkstra(WeightedDigraph* g, int startVertex);
    void computeShortestPaths();

private:

    WeightedDigraph* graph;
    int start_vertex;
    std::map<int, bool> reachable;
    std::map<int, int> shortest_paths;
    UniqueValuedHeap<UnprocessedVertex> unprocessed_vertices;

    void updateHeap(int extracted_v);
    int computeDijskatraGreedyScore(int v);
    bool vertexIsProcessed(int v);


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
