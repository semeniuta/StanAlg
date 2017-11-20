#ifndef DFS_H
#define DFS_H

#include "Graph.h"
#include "Digraph.h"
#include <map>
#include <iostream>

class DFS {

public:

    DFS() = delete;

    explicit DFS(Graph *g);

    virtual void searchFrom(int startVertex);

    bool isExplored(int v);

protected:

    Graph *graph;
    map<int, bool> explored;

    virtual void onEntry(int startVertex) {}

    virtual void onExit(int startVertex) {}

};

class DFSDirected : public DFS {

public:

    DFSDirected() = delete;

    explicit DFSDirected(Digraph *g) : DFS(g) {}

    virtual void reverseSearchFrom(int startVertex);

};


#endif
