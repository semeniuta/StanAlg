#include "Dijkstra.h"
#include <queue>
#include <climits>

Dijkstra::Dijkstra(WeightedDigraph* g, int startVertex) : graph(g), start_vertex(startVertex) {

    if (!g->hasVertex(startVertex)) {
        throw std::invalid_argument("Non-existing start vertex provided");
    }

    // Find the reachable subset of the graph

    DijkstraPreprocessingDFS preprocess(this->graph);
    preprocess.searchFrom(this->start_vertex);
    this->reachable = preprocess.copyReachabilityMap();

    // Initialize shortest_paths given the starting vertex

    this->shortest_paths[this->start_vertex] = 0;

    // Initialize the priority queue of unprocessed vertices

    std::set<int> adj_to_start;
    for (const auto& adj_vertex : this->graph->getListofAdjacentVertices(this->start_vertex)) {

        adj_to_start.insert(adj_vertex.w);

        UnprocessedVertex upv{
                adj_vertex.w,
                this->graph->getWeight(adj_vertex.edgeIndex)
        };

        this->unprocessed_vertices.push(upv);
    }

    for (auto v : this->graph->getVerticesVector()) {

        if (adj_to_start.find(v) == adj_to_start.end()) {

            UnprocessedVertex unreachable_upv{ v, INT_MAX };
            this->unprocessed_vertices.push(unreachable_upv);

        }

    }

}

void Dijkstra::computeShortestPaths() {

    // TODO

}

void Dijkstra::updateHeap(int extracted_v) {

    for (const auto& adj_edge : this->graph->getListofAdjacentVertices(extracted_v)) {

        int w = adj_edge.w;

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
