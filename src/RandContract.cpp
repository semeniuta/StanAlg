#include "RandContract.h"
#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

RandomContraction::RandomContraction(Graph* g) {
  
  this->originalGraph = g;
  this->contractedGraph = Graph();
  
  this->copyGraph();
  
  srand(time(nullptr));
  while(this->contractedGraph.countVertices() > 2) {
    
    int num_edges = contractedGraph.countEdges();
    int random_number = rand() % num_edges;
    
    auto edge_itr = next(this->contractedGraph.edgesMapBegin(), random_number);
    int edge_to_contract_index = edge_itr->first;
    
    this->contractedGraph.contractEdge(edge_to_contract_index);
  }
  
  cout << "# edges: " << this->contractedGraph.countEdges() << endl;
  
  return;
  
}

RandomContraction::~RandomContraction() { }

void RandomContraction::copyGraph() {
  
  for (int i = 0; i < this->originalGraph->countEdges(); i++) {
    pair<int, int> endpoints = this->originalGraph->edgeEndpoints(i);
    this->contractedGraph.addEdge(endpoints.first, endpoints.second);
  }
  
}

