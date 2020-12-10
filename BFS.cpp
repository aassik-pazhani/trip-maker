#include "BFS.h"

BFS::BFS(Graph g)  {
    graph = g;
    for (Vertex v : graph.getVertices()) {
        map.insert({v, false});
    }
}

void BFS::search() {
    for (auto it = map.begin(); it != map.end(); it++) {
        if (!it->second) {
            search(it->first);
        }
    }
}

void BFS::search(Vertex v) {
    adjacent.push(v);
    while (!adjacent.empty()) {
        v = adjacent.front();
        destinations.push_back(v);
        adjacent.pop();
        for (Vertex adj : graph.getAdjacent(v)) {
            if (!map.find(adj)->second) {
                map.find(adj)->second = true;
                adjacent.push(adj);
            }
        }
    }
}