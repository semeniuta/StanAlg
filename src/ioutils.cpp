
#include <sstream>

#include "ioutils.h"

void readGraphFromFile(FileReader *fr, Graph *g) {

    string current_str;
    while (!fr->eof()) {

        vector<int> lst;

        current_str = fr->readLine();
        if (current_str.empty()) {
            break;
        }

        std::istringstream iss(current_str);
        std::string token;
        while (std::getline(iss, token, '\t')) {
            if (token != "\r") {
                lst.push_back(std::stoi(token));
            }
        }

        int v = lst[0];
        for (int i = 1; i < lst.size(); i++) {
            int w = lst[i];
            g->addEdge(v, w);
        }

    }

}

void readDigraphFromFile(FileReader *fr, Digraph *g) {

    string current_str;
    while (!fr->eof()) {

        int v;
        int w;

        current_str = fr->readLine();
        if (current_str.empty()) {
            break;
        }

        std::istringstream iss(current_str);
        std::string token;

        std::getline(iss, token, ' ');
        v = std::stoi(token);

        std::getline(iss, token);
        w = std::stoi(token);

        g->addEdge(v, w);

    }

}
