#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <utility>

using namespace std;

typedef map<int, vector<int>>::iterator AdjMapIterator;
typedef map<int, pair<int, int>>::iterator EdgesMapIterator;

class Graph {

  public:
    Graph();
    ~Graph();
    void addVertex(int v);
    int addEdge(int v, int w);
    vector<int>::iterator adjacentEdges(int v);
    pair<int, int> edgeEndpoints(int edgeIndex);
    int countVerticess();
    int countEdges();

  private:
    map<int, vector<int>> adj;
    map<int, pair<int, int>> edges;
    int num_vertices;
    int num_edges;
    bool vertexExists(int v);

};

#endif
