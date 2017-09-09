#ifndef KOSARAJU_H
#define KOSARAJU_H

#include "DFS.h"
#include "Digraph.h"
#include <map>

class DFSKosarajuFinishingTimes : public DFSDirected {

public:

    DFSKosarajuFinishingTimes(Digraph* g, int* t, map<int, int>& f) : DFSDirected(g), tPtr(t), finishingTimes(f) { }

    map<int, int>& getFinishingTimes() { return this->finishingTimes; }

protected:

    virtual void onExit(int startVertex) {
        this->finishingTimes[startVertex] = ++(*(this->tPtr));
    }

private:

    int* tPtr;
    map<int, int>& finishingTimes;

};


#endif
