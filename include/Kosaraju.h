#ifndef KOSARAJU_H
#define KOSARAJU_H

#include "DFS.h"
#include "Digraph.h"
#include <map>

void kosarajuComputeFinishingTimes(Digraph* g, Digraph* resG, map<int, int>& f);

class DFSKosarajuFinishingTimes : public DFSDirected {

public:

    DFSKosarajuFinishingTimes(Digraph* g, map<int, int>& f) : DFSDirected(g), t(0), finishingTimes(f) { }

    map<int, int>& getFinishingTimes() { return this->finishingTimes; }

protected:

    virtual void onExit(int startVertex) {
        this->finishingTimes[startVertex] = ++(this->t);
    }

private:

    int t;
    map<int, int>& finishingTimes;

};


#endif
