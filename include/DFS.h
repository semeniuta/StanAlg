#ifndef DFS_H
#define DFS_H

#include "Graph.h"
#include "Digraph.h"
#include <map>
#include <iostream>

class DFS {

public:

    DFS(Graph* g);
    virtual void searchFrom(int startVertex);

protected:

    Graph* graph;
    map<int, bool> explored;

    virtual void onEntry(int startVertex) { }
    virtual void onExit(int startVertex) { }

};

class DFSDirected : public DFS {

public:

    DFSDirected(Digraph* g) : DFS(g) { }
    virtual void reverseSearchFrom(int startVertex);

protected:

    Digraph* graph;

};


class DFSOnEntryPrinter : public DFS {

public:

    DFSOnEntryPrinter(Graph* g) : DFS(g) { }

protected:

    virtual void onEntry(int startVertex) {
        std::cout << startVertex << std::endl;
    }
};


class DFSOnExitPrinter : public DFS {

public:

    DFSOnExitPrinter(Graph* g) : DFS(g) { }

protected:

    virtual void onExit(int startVertex) {
        std::cout << startVertex << std::endl;
    }
};


#endif
