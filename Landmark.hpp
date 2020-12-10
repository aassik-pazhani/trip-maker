/**
 * @file Landmark.hpp
 * Implements the Landmark Function
 */

#include "Dijkstra.hpp"
#include<vector>
using std::vector;

/**
 * Function to run the Landmark algorithm and output the results as a txt file
 * Every destination appears twice in the final path
 * @param graph - the graph containing airports and flight routes
 * @param source - departure airport
 * @param destinations - a vector of destination airports
 * @return a vector of the airports that must be traveled to
 */
vector<Vertex> Landmark(Graph graph, Vertex source, vector<Vertex> destinations);