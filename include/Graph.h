#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <map>
#include <utility>

using namespace std;

struct AdjacentVertex {
  int w;
  int edgeIndex;
};

typedef map<int, list<AdjacentVertex>>::iterator AdjMapIterator;

class Graph {

  public:
    Graph();
    ~Graph();
    void addVertex(int v);
    int addEdge(int v, int w);
    list<AdjacentVertex>::iterator adjacentEdges(int v);
    pair<int, int> edgeEndpoints(int edgeIndex);
    int countVertices();
    int countEdges();
    int contractEdge(int edgeIndex);
    void printGraph();
    void printEdges();
 
  private:
    map<int, list<AdjacentVertex>> adj;
    map<int, pair<int, int>> edges;
    int num_vertices;
    int num_edges;
    bool vertexExists(int v);
    bool edgeExists(int edgeIndex);
    void shrinkAdjOnContraction(int v_keep, int v_away);
    void renameInEdgesMapOnContraction(int v_keep, int v_away);
    void removeSelfLoopsAfterContraction(int v_keep, int v_away);
};

#endif
