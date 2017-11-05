#ifndef RANDCONTRACT_H
#define RANDCONTRACT_H

#include "ContractableGraph.h"
#include <set>

class RandomContraction {

public:
    RandomContraction(ContractableGraph *g);

    ~RandomContraction();

    int doContraction();


private:
    ContractableGraph *originalGraph;

    void copyGraph(ContractableGraph *targetGraph);

};


#endif
