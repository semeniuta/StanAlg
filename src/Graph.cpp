#include "Graph.h"
#include <list>
#include <map>
#include <utility>
#include <iostream>
#include <iterator>

using namespace std;

Graph::Graph() : num_vertices(0), num_edges(0) { }

Graph::~Graph() { }

void Graph::addVertex(int v) {

  if (this->vertexExists(v)) {
    cout << "Vertex " << v << " already exists" << endl;
    return;
  }

  this->adj[v] = list<int>();
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

list<int>::iterator Graph::adjacentEdges(int v) {
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

int Graph::contractEdge(int edgeIndex) {
  // returns index of ... ?

  if (edgeIndex < 0 || edgeIndex >= this->num_edges) {
    cout << "Invalid edge index provided. Should be between " << 0 << " and "
         << this->num_edges-1 << endl;
    return -1;
  }

  pair<int, int> endpoints = this->edgeEndpoints(edgeIndex);

  int v_keep = endpoints.first;
  int v_away = endpoints.second;

  for (const int& a : this->adj[v_away]) {
    this->adj[v_keep].push_back(a);
  }

  this->adj.erase(v_away);

  for (AdjMapIterator itr = this->adj.begin(); itr != this->adj.end(); itr++) {

    int v = itr->first;
    list<int>& v_adj = itr->second;

    // rename
    for (int& w : v_adj) {
      if (w == v_away) {
        w = v_keep;
      }
    }
    
    // remove self-loop
    v_adj.remove(v);

  }

  return 0;

}

void Graph::printGraph() {

  for (AdjMapIterator itr = this->adj.begin(); itr != this->adj.end(); itr++) {
    cout << itr->first << ": [";
    list<int> adj_list = itr->second;
    for (list<int>::iterator ptr_adj = adj_list.begin(); ptr_adj != adj_list.end(); ptr_adj++) {
      cout << *ptr_adj;
      if (!(ptr_adj == prev(adj_list.end(), 1))) {
         cout << ", ";
      }
    }
    cout << "]" << endl;
  }

}

bool Graph::vertexExists(int v) {

  for (AdjMapIterator itr = this->adj.begin(); itr != this->adj.end(); itr++) {
    if (itr->first == v) {
      return true;
    }
  }

  return false;

}
