#ifndef IOUTILS_H
#define IOUTILS_H

#include "Graph.h"
#include "Digraph.h"
#include "WeightedDigraph.h"
#include "FileReader.h"

void readGraphFromFile(FileReader *fr, Graph *g);
void readDigraphFromFile(FileReader *fr, Digraph *g);
void readWeightedGraphFromFile(FileReader *fr, WeightedDigraph *g);



#endif
