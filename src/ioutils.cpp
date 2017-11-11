#include "Graph.h"
#include "FileReader.h"
#include <sstream>

#include "ioutils.h"

void readGraphFromFile(FileReader *fr, Graph *g) {

    string current_str;
    while (!fr->eof()) {

        vector<int> lst;

        current_str = fr->readLine();
        if (current_str.size() == 0) {
            break;
        }

        std::istringstream iss(current_str);
        std::string token;
        while (std::getline(iss, token, '\t')) {
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
