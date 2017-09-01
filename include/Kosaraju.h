#ifndef KOSARAJU_H
#define KOSARAJU_H

#include "DFS.h"

class KosarajuDFS : public DFS {

public:
    KosarajuDFS(Graph* g) : DFS(g) { }
    //void searchFromWithLeader(int startVertex, int leaderVertex);

protected:
    virtual void onEntry(int startVertex) { /*TODO */ }
    virtual void onExit(int startVertex) { /*TODO */ }

private:
    map<int, int> leader;

};


#endif
