#pragma once

#include "graphs.h"
#include <map>
using std::map;

struct comparison {
    /**
     * 
     * @param lhs - 
     * @param rhs - 
     * @return 
     */
    bool operator()(const pair<int, Vertex> &lhs, const pair<int, Vertex> &rhs) const
    {
        return lhs < rhs;
    }
};

/**
 * 
 * @param graph - the graph containing airports and flight routes
 * @param source - departure airport
 * @param destination - destination airport
 * @return shortest path from source to destination
 */
vector<Vertex> Dijkstra(Graph graph, Vertex source, Vertex destination);

/**
 * @param previous - a map from all vertices to their predecessors
 * @param source - departure airport
 * @param destination - adestination airport
 * @return the path from source to destination
 */
vector<Vertex> getPath(map<Vertex, Vertex> previous, Vertex source, Vertex destination);