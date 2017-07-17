#include "Graph.h"
#include <vector>
#include <map>
#include <utility>
#include <iostream>

using namespace std;

Graph::Graph() : num_vertices(0), num_edges(0) { }

Graph::~Graph() { }

void Graph::addVertex(int v) {

  if (this->vertexExists(v)) {
    cout << "Vertex " << v << " already exists" << endl;
    return;
  }

  this->adj[v] = vector<int>();
  this->num_vertices++;

}

int Graph::addEdge(int v, int w) {

  if (!this->vertexExists(v)) {
    this->addVertex(v);
  }

  if (!this->vertexExists(w)) {
    this->addVertex(w);
  }

  int current_index = this->num_edges;

  this->edges[current_index] = pair<int, int>(v, w);
  this->adj[v].push_back(w);
  this->adj[w].push_back(v);

  this->num_edges++;

  return current_index;

}

vector<int>::iterator Graph::adjacentEdges(int v) {
  return this->adj[v].begin();
}

pair<int, int> Graph::edgeEndpoints(int edgeIndex) {
  return this->edges[edgeIndex];
}

int Graph::countVerticess() {
  return num_vertices;
}

int Graph::countEdges() {
  return num_edges;
}

bool Graph::vertexExists(int v) {

  for (AdjMapIterator itr = this->adj.begin(); itr != this->adj.end(); itr++) {
    if (itr->first == v) {
      return true;
    }
  }

  return false;

}
