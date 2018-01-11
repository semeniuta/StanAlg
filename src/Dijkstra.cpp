#include "Dijkstra.h"
#include <queue>
#include <climits>

Dijkstra::Dijkstra(WeightedDigraph* g, int startVertex) :
        graph(g),
        start_vertex(startVertex) {

    if (!g->hasVertex(startVertex)) {
        throw std::invalid_argument("Non-existing start vertex provided");
    }

    // Find the reachable subset of the graph

    DijkstraPreprocessingDFS preprocess(this->graph);
    preprocess.searchFrom(this->start_vertex);
    this->reachable = preprocess.copyReachabilityMap();

    // Initialize shortest_paths given the starting vertex

    this->shortest_paths[this->start_vertex] = 0;

    // Include all the unreachable vertices as processed with INT_MAX

    for (const auto& reach : this->reachable) {
        int v = reach.first;
        bool not_reachable = !reach.second;
        if (not_reachable) {
            this->shortest_paths[v] = INT_MAX;
        }
    }

    // Initialize the heap of unprocessed vertices

    for (auto v : this->graph->getVerticesVector()) {

        if (!this->vertexIsProcessed(v)) {

            this->unprocessed_vertices.insert(this->graph->getWeight(v), v);

        }

    }



}

void Dijkstra::computeShortestPaths() {

    // TODO

}

void Dijkstra::updateHeap(int extracted_v) {

    for (const auto& adj_vertex : this->graph->getListofAdjacentVertices(extracted_v)) {

        int w = adj_vertex.w;

        if (!this->vertexIsProcessed(w)) {

            // TODO
            // Delete w from this->unprocessed_vertices
            // and recompute score
        }

    }

}

int Dijkstra::computeDijskatraGreedyScore(int v) {

    // TODO

}

bool Dijkstra::vertexIsProcessed(int v) {

    if (this->shortest_paths.find(v) != this->shortest_paths.end()) {
        return true;
    }

    return false;

}