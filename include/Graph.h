#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <map>
#include <vector>
#include <utility>

using namespace std;

struct AdjacentVertex {
    int w;
    int edgeIndex;
};

typedef map<int, list<AdjacentVertex>>::iterator AdjMapIterator;
typedef map<int, pair<int, int>>::iterator EdgesMapIterator;

class Graph {

public:
    Graph();

    ~Graph();

    void addVertex(int v);

    int addEdge(int v, int w);

    AdjMapIterator adjMapBegin();

    AdjMapIterator adjMapEnd();

    EdgesMapIterator edgesMapBegin();

    EdgesMapIterator edgesMapEnd();

    void getVerticesVector(vector<int>& vertices, bool ascending = true);

    list<AdjacentVertex>& getListofAdjacentVertices(int v);

    pair<int, int>& edgeEndpoints(int edgeIndex);

    int countVertices();

    int countEdges();

    void printGraph();

    void printEdges();

protected:
    map<int, list<AdjacentVertex>> adj;

    map<int, pair<int, int>> edges;

    virtual void addAdjacencyInfo(int v, int w, int edgeIndex);

    int num_vertices;

    int num_edges;

    bool vertexExists(int v);

    bool edgeExists(int edgeIndex);

    bool edgeExists(int v, int w);

    void printAdj(map<int, list<AdjacentVertex>>& adj_map);

};

#endif
