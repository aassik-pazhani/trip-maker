#pragma once

#include <vector>
#include <queue>
#include <iterator>
#include <iostream>
#include <map>

#include "graphs.h"

using std::vector;
using std::string;
using std::queue;
using std::map;

class BFS {
    private:
        Graph graph;
        map<Vertex, bool> map;
        queue<Vertex> adjacent;
        void search(Vertex vertex);

    public:
        BFS(Graph g);
        void search();
        vector<Vertex> destinations;
};