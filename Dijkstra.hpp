/**
 * @file Dijkstra.h
 * This file implements the shortest path - Dijkstra's Algorithm on a graph.
 */
#pragma once

#include "graphs.h"
#include <map>
using std::map;
/**
 * Used for comparison of pairs
 */
struct comparison {
    /**
     * @param lhs - first term to compare
     * @param rhs - second term to compare
     * @return -true, if int of lhs is smaller
     *         -false, if int of rhs is smaller
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