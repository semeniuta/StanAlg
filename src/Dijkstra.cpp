#include "Dijkstra.h"
#include <queue>

Dijkstra::Dijkstra(WeightedDigraph* g, int startVertex) : graph(g), start_vertex(startVertex) {

    if (!g->hasVertex(startVertex)) {
        throw std::invalid_argument("Non-existing start vertex provided");
    }

    // Find the reachable subset of the graph
    DijkstraPreprocessingDFS preprocess(this->graph);
    preprocess.searchFrom(this->start_vertex);
    this->reachable = preprocess.copyReachabilityMap();

    // Initialize shortest_paths and frontier_edges given the starting vertex
    this->shortest_paths[this->start_vertex] = 0;
    for (const auto& adj_vertex : g->getListofAdjacentVertices(startVertex)) {
        if (adj_vertex.w != startVertex) {
            this->frontier_edges.insert( adj_vertex.edgeIndex );
        }
    }

    // Initialize the priority queue of unprocessed vertices
    // TODO

}

void Dijkstra::computeShortestPaths() {

    // TODO

}

void Dijkstra::updateFrontier(int newVertexIndex) {

    // Remove old frontier edges that point to the newly processed vertex
    for (auto frontier_edge : this->frontier_edges) {

        if (this->graph->edgeEndpoints(frontier_edge).second == newVertexIndex) {
            this->frontier_edges.erase(frontier_edge);
        }

    }

    // Add new frontier edges from the newly processed vertex
    for (const auto& adj_vertex : this->graph->getListofAdjacentVertices(newVertexIndex)) {
        if (!vertexIsProcessed(adj_vertex.w)) {
            this->frontier_edges.insert(adj_vertex.edgeIndex);
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
