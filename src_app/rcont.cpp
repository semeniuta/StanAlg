#include <iostream>
#include <vector>
#include <sstream>
#include "Graph.h"
#include "RandContract.h"
#include "FileReader.h"
#include "argtools.h"

using namespace std;

void read_graph_from_file(FileReader* fr, Graph* g) {
  
  string current_str;
  while (!fr->eof()) {
    
    vector<int> lst;
    
    current_str = fr->readLine();
    if (current_str.size() == 0) {
      break;
    }
    
    std::istringstream iss(current_str);
    std::string token;
    while (std::getline(iss, token, '\t'))
    {
      if (token != "\r") {
        lst.push_back(atoi(token.c_str()));
      }
    }
    
    int v = lst[0];
    for (int i = 1; i < lst.size(); i++) {
      int w = lst[i];
      g->addEdge(v, w);
    }
    
  }

}

int main(int argc, char *argv[]) {
  
  srand(time(nullptr));

  ContractableGraph g;
  
  if (argc == 3) {
  
    if (getArg(argc, argv, 1) == "-f") {
      
      FileReader fr;
      string fname = getArg(argc, argv, 2);
      fr.open(fname);
      
      read_graph_from_file(&fr, &g);
    }
    
  } else {
    
    vector<pair<int, int>> edges = {
      pair<int, int>(0, 1),
      pair<int, int>(1, 2),
      pair<int, int>(2, 0),
      pair<int, int>(1, 3),
      pair<int, int>(3, 4),
      pair<int, int>(3, 7),
      pair<int, int>(4, 5),
      pair<int, int>(5, 6),
      pair<int, int>(6, 7),
      pair<int, int>(4, 6),
      pair<int, int>(7, 5),
      pair<int, int>(8, 1),
      pair<int, int>(8, 0),
      pair<int, int>(8, 2)
    };
    
    for (const pair<int, int>& p : edges) {
      g.addEdge(p.first, p.second);
    }
    
  }
  
  RandomContraction rc(&g);
  
  int nc;
  int nc_min = g.countEdges();
  for (int i = 0; i < 200; i++) {
    cout << nc << " ";
    nc = rc.doContraction();
    if (nc < nc_min) {
      nc_min = nc;
    }
  }
  
  cout << "\nMin cut size: " << nc_min << endl;

  return 0;
}
