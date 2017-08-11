#include "RandContract.h"
#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>
#include <vector>

using namespace std;

RandomContraction::RandomContraction(Graph* g) {
  
  this->originalGraph = g;

}

RandomContraction::~RandomContraction() { }

int RandomContraction::doContraction() {
  
  Graph cg;
  
  this->copyGraph(&cg);
  
  while(cg.countVertices() > 2) {
    
    int num_edges = cg.countEdges();
    int random_number = rand() % num_edges;
    
    auto edge_itr = next(cg.edgesMapBegin(), random_number);
    int edge_to_contract_index = edge_itr->first;
    
    cg.contractEdge(edge_to_contract_index);
  }

  // can be useful; works correctly, but doesn't get returned
  vector<pair<int, int>> original_edges;
  for (EdgesMapIterator e_ptr = cg.edgesMapBegin(); e_ptr != cg.edgesMapEnd(); e_ptr++) {
    int edge_index = e_ptr->first;
    original_edges.push_back(this->originalGraph->edgeEndpoints(edge_index));
  }
  
  return cg.countEdges();
  
  
}

void RandomContraction::copyGraph(Graph* targetGraph) {
  
  for (int i = 0; i < this->originalGraph->countEdges(); i++) {
    pair<int, int> endpoints = this->originalGraph->edgeEndpoints(i);
    targetGraph->addEdge(endpoints.first, endpoints.second);
  }
  
}

