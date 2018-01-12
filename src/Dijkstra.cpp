#include "Dijkstra.h"
#include "Heap.h"
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

    // Fill the heap of unprocessed vertices with the vertices adjacent to start

    std::set<int> adj_to_start;

    for (const auto& adj_vertex : this->graph->getListofAdjacentVertices(this->start_vertex)) {

        adj_to_start.insert(adj_vertex.w);

        int greedy_score = this->graph->getWeight(adj_vertex.edgeIndex);
        UnprocessedVertexData vertex_data{ adj_vertex.w, this->start_vertex };

        this->unprocessed_vertices.insert(greedy_score, vertex_data);
    }

    // Fill the heap of unprocessed vertices with the vertices NOT adjacent to start

    for (auto v : this->graph->getVerticesVector()) {

        bool not_adjacent_to_start = (adj_to_start.find(v) == adj_to_start.end());
        bool not_start = (v != this->start_vertex);
        bool not_processed = (!this->vertexIsProcessed(v));

        if (not_start && not_adjacent_to_start && not_processed) {

            UnprocessedVertexData vertex_data{ v, -1 };
            this->unprocessed_vertices.insert(NO_PATH_WEIGHT, vertex_data);

        }

    }

}

void Dijkstra::computeShortestPaths() {

    while (!this->unprocessed_vertices.empty()) {

        HeapEntry<int, UnprocessedVertexData> extracted = this->unprocessed_vertices.pop();

        int distance = this->shortest_paths[extracted.value.src] + extracted.key;
        this->shortest_paths[extracted.value.v] = distance;

        //this->updateHeap()

    }

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

template class UniqueValuedHeap<int, UnprocessedVertexData>;