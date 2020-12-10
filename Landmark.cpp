#include "Landmark.hpp"

//destinations appear twice (intentional to mark destinations)
vector<Vertex> Landmark(Graph graph, Vertex source, vector<Vertex> destinations) {
    vector<Vertex> path;
    vector<Vertex> shortpath;
    Vertex last = source;
    while (destinations.size() != 0) {
        shortpath = Dijkstra(graph, last, destinations.front());    
        path.insert(path.end(), shortpath.begin(), shortpath.end());
        last = destinations.front();
        destinations.erase(destinations.begin());
    }
    return path;
}