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

int Graph::countVertices() {
  return num_vertices;
}

int Graph::countEdges() {
  return num_edges;
}

int Graph::contractEdge(int edgeIndex) {
  // returns index of ... ?
  
  if (this->edges.find(edgeIndex) == this->edges.end()) {
    cout << "Invalid edge index provided" << endl;
    return -1;
  }

  pair<int, int> endpoints = this->edgeEndpoints(edgeIndex);

  int v_keep = endpoints.first;
  int v_away = endpoints.second;

  // copy the adjacency list from the vertex that go away
  for (const int& a : this->adj[v_away]) {
    this->adj[v_keep].push_back(a);
  }
  this->adj.erase(v_away);
  this->edges.erase(edgeIndex);
  this->num_vertices--;
  
  // rename in edges map
  for (const pair<int, pair<int, int>>& e : this->edges) {
    int key = e.first;
    int a = e.second.first;
    int b = e.second.second;
    
    if (a == v_away) {
      this->edges[key].first = v_keep;
    }
    
    if (b == v_away) {
      this->edges[key].second = v_keep;
    }
    
  }

  int cycles_removed = 0;
  for (AdjMapIterator ami = this->adj.begin(); ami != this->adj.end(); ami++) {

    int v = ami->first;
    list<int>& v_adj = ami->second;

    // rename
    for (int& w : v_adj) {
      if (w == v_away) {
        w = v_keep;
      }
    }
    
    // remove self-loop
    /*
    int n_egdes_before = v_adj.size();
    v_adj.remove(v);
    int n_egdes_after = v_adj.size();
    int n_edges_removed = (n_egdes_before - n_egdes_after) / 2;
    this->num_edges -= n_edges_removed;
     */
    
    for (list<int>::iterator ptr_w = v_adj.begin(); ptr_w != v_adj.end(); /* No increment */) {
      int w = *ptr_w;
      
      if (w == v) {
        ptr_w = v_adj.erase(ptr_w);
        cout << "Removing (" << v << ", " << w << ")" << endl;
        cycles_removed++;
      } else {
        ptr_w++;
      }
    }
    
  }
  
  this->num_edges -= (cycles_removed / 2);
  
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

void Graph::printEdges() {
  
  for (const pair<int, pair<int, int>>& el : this->edges) {
    cout << el.first << ": (" << el.second.first << ", " << el.second.second << ")" << endl;
  }
  
}

bool Graph::vertexExists(int v) {

  if (this->adj.find(v) == this->adj.end()) {
    return false;
  }

  return true;

}
