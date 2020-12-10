/**
 * @file BFS.h
 * Implements the Breadth - First Search Algorithm on a graph.
 */

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

/**
 * Implements the BFS algorithm.
 */
class BFS {
    private:
        Graph graph; /** The graph we are using to traverse using BFS algorithm */
        map<Vertex, bool> map; /** Map of vertex as key and bool as its value. We use this map to check if the vertex is visited*/
        queue<Vertex> adjacent; /** Queue of vertex which stores the potential successor vertices while traversing through a vertex*/

        /**
         * Helper function for search() where we traverse the graph using BFS algorithm.
         * @param vertex - the first vertex in the graph used for traversal
         */
        void search(Vertex vertex);

    public:
        /**
         * Constructor
         * Initializes graph and get all the vertices in the graph
         * @param g - Initialized for graph 
         */
        BFS(Graph g);

        /**
         * This function calls the helper function to perform the traversal using BFS algorithm.
         */
        void search();

        vector<Vertex> destinations; /** Vector of vertex which stores the path taken to traverse. This is used to extract the output for BFS algorithm.*/
};