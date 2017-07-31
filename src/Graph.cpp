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

  int current_index = this->num_edges;

  this->edges[current_index] = pair<int, int>(v, w);
  this->adj[v].push_back({w, current_index});
  this->adj[w].push_back({v, current_index});

  this->num_edges++;

  return current_index;

}

list<AdjacentVertex>::iterator Graph::adjacentEdges(int v) {
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
  
  if (!this->edgeExists(edgeIndex)) {
    cout << "Invalid edge index provided" << endl;
    return -1;
  }

  pair<int, int> endpoints = this->edgeEndpoints(edgeIndex);

  int v_keep = endpoints.first;
  int v_away = endpoints.second;

  this->edges.erase(edgeIndex);
  this->shrinkAdjOnContraction(v_keep, v_away);
  this->renameInEdgesMapOnContraction(v_keep, v_away);
  this->removeSelfLoopsAfterContraction(v_keep, v_away);
  
  return 0;

}

void Graph::printGraph() {

  for (AdjMapIterator itr = this->adj.begin(); itr != this->adj.end(); itr++) {
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

void Graph::shrinkAdjOnContraction(int v_keep, int v_away) {
  // copy the adjacency list from the vertex that is going away
  
  for (const AdjacentVertex& a : this->adj[v_away]) {
    this->adj[v_keep].push_back(a);
  }
  this->adj.erase(v_away);
  this->num_vertices--;

}

void Graph::renameInEdgesMapOnContraction(int v_keep, int v_away) {
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

}

void Graph::removeSelfLoopsAfterContraction(int v_keep, int v_away) {

  int cycles_removed = 0;
  for (AdjMapIterator ami = this->adj.begin(); ami != this->adj.end(); ami++) {
    
    int v = ami->first;
    list<AdjacentVertex>& v_adj = ami->second;
    
    // rename
    for (AdjacentVertex& a : v_adj) {
      if (a.w == v_away) {
        a.w = v_keep;
      }
    }
    
    // remove self-loop
    for (list<AdjacentVertex>::iterator ptr_w = v_adj.begin(); ptr_w != v_adj.end(); /* No increment */) {
      
      int w = ptr_w->w;
      
      if (w == v) {
        
        int edge_index_to_remove = ptr_w->edgeIndex;
        if (this->edgeExists(edge_index_to_remove)) {
          this->edges.erase(edge_index_to_remove);
        }
        
        ptr_w = v_adj.erase(ptr_w);
        
        cycles_removed++;
      } else {
        ptr_w++;
      }
    }
    
  }
  
  this->num_edges -= (cycles_removed / 2);

}
