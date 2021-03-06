#include "Graph.h"
#include <list>
#include <map>
#include <utility>
#include <iostream>
#include <iterator>

using namespace std;

Graph::Graph() : num_vertices(0), num_edges(0) {}

void Graph::addVertex(int v) {

    if (this->vertexExists(v)) {
        cout << "Vertex " << v << " already exists" << endl;
        return;
    }

    this->adj[v] = list<AdjacentVertex>();
    this->num_vertices++;

}

int Graph::addEdge(int v, int w) {

    if (!this->vertexExists(v)) {
        this->addVertex(v);
    }

    if (!this->vertexExists(w)) {
        this->addVertex(w);
    }

    if (this->edgeExists(v, w)) {
        return -1;
    }

    int current_index = this->num_edges;

    this->edges[current_index] = pair<int, int>(v, w);
    this->addAdjacencyInfo(v, w, current_index);

    this->num_edges++;

    return current_index;

}

void Graph::addAdjacencyInfo(int v, int w, int edgeIndex) {
    this->adj[v].push_back({w, edgeIndex});
    this->adj[w].push_back({v, edgeIndex});
}

pair<int, int>& Graph::edgeEndpoints(int edgeIndex) {
    return this->edges[edgeIndex];
}

int Graph::countVertices() {
    return num_vertices;
}

int Graph::countEdges() {
    return num_edges;
}

bool Graph::hasVertex(int index) {
    if (this->adj.find(index) != this->adj.end()) {
        return true;
    }
    return false;
}

std::vector<int> Graph::getVerticesVector(bool ascending) {

    std::vector<int> vertices;

    if (ascending) {

        for (auto itr = this->adj.begin(); itr != this->adj.end(); itr++) {
            vertices.push_back(itr->first);
        }

    } else {

        for (auto itr = this->adj.rbegin(); itr != this->adj.rend(); itr++) {
            vertices.push_back(itr->first);
        }

    }

    return vertices;
}

list<AdjacentVertex>& Graph::getListofAdjacentVertices(int v) {

    list<AdjacentVertex>& adj_list = this->adj[v];
    return adj_list;

}

AdjMapIterator Graph::adjMapBegin() {
    return this->adj.begin();
}

AdjMapIterator Graph::adjMapEnd() {
    return this->adj.end();
}

EdgesMapIterator Graph::edgesMapBegin() {
    return this->edges.begin();
}

EdgesMapIterator Graph::edgesMapEnd() {
    return this->edges.end();
}

void Graph::printAdj(map<int, list<AdjacentVertex>>& adj_map) {

    for (AdjMapIterator itr = adj_map.begin(); itr != adj_map.end(); itr++) {
        cout << itr->first << ": [";
        list<AdjacentVertex> adj_list = itr->second;
        for (list<AdjacentVertex>::iterator ptr_adj = adj_list.begin(); ptr_adj != adj_list.end(); ptr_adj++) {
            cout << ptr_adj->w;
            if (!(ptr_adj == prev(adj_list.end(), 1))) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

}

void Graph::printGraph() {

    this->printAdj(this->adj);

}

void Graph::printEdges() {

    for (const pair<int, pair<int, int>>& el : this->edges) {
        cout << el.first << ": (" << el.second.first << ", " << el.second.second << ")" << endl;
    }

}

bool Graph::edgeExists(int edgeIndex) {

    if (this->edges.find(edgeIndex) == this->edges.end()) {
        return false;
    }

    return true;
}

bool Graph::vertexExists(int v) {

    if (this->adj.find(v) == this->adj.end()) {
        return false;
    }

    return true;

}

bool Graph::edgeExists(int v, int w) {

    if (!this->vertexExists(v)) return false;

    bool exists = false;
    for (list<AdjacentVertex>::iterator itr = this->adj[v].begin(); itr != this->adj[v].end(); itr++) {
        if (itr->w == w) {
            exists = true;
            break;
        }
    }

    return exists;

}
