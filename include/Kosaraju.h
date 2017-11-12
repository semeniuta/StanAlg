#ifndef KOSARAJU_H
#define KOSARAJU_H

#include "DFS.h"
#include "Digraph.h"
#include <map>

std::map<int, std::vector<int>> kosarajuSCC(Digraph& g);

void kosarajuComputeFinishingTimes(Digraph *g, Digraph *resG, map<int, int>& f);

void kosarajuDetermineLeaders(Digraph *graphF, map<int, int>& leaderMap);

class DFSKosarajuFinishingTimes : public DFSDirected {

public:

    DFSKosarajuFinishingTimes(Digraph *g, map<int, int>& f) : DFSDirected(g), t(0), finishingTimes(f) {}

protected:

    void onExit(int startVertex) override {
        this->finishingTimes[startVertex] = ++(this->t);
    }

private:

    int t;
    map<int, int>& finishingTimes;

};

class DFSKosarajuLeaders : public DFSDirected {

public:

    DFSKosarajuLeaders(Digraph *g, int *s, map<int, int>& leaderMap) : DFSDirected(g), sPtr(s), leader(leaderMap) {}

protected:

    void onEntry(int startVertex) override {
        this->leader[startVertex] = *sPtr;
    }

private:

    int *sPtr;
    map<int, int>& leader;

};


#endif
