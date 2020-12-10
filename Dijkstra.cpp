#include <map>
#include <algorithm>
#include <queue>
#include "Dijkstra.hpp"

using std::pair;
using std::map;
using std::priority_queue;


vector<Vertex> Dijkstra(Graph graph, Vertex source, Vertex destination) {
    map<Vertex, int> distance; //distance from source
    map<Vertex, bool> visited; //stores the visited vertex as true, else false
    map<Vertex, Vertex> previous; //stores the previously visited vertex for all the vertices. Source has " ".
    for (Vertex v : graph.getVertices()) {
        previous.insert(pair<Vertex, Vertex> (v, ""));
        visited.insert(pair<Vertex, bool>(v, false));
        distance.insert(pair<Vertex, int> (v, INT_MAX));
    }
    distance[source] = 0;
    //vector of pairs with Vertex and its distance (intially infinity)
    vector<pair<int, Vertex>> distancePair; //pairs of vertices and their distance from source.
    for (Vertex V : graph.getVertices()) {
        if (V == source) {
            distancePair.push_back(pair<int, Vertex> (0, V));    
        } else {
            distancePair.push_back(pair<int, Vertex> (INT_MAX, V)); 
        }
    }
    priority_queue<pair<int, Vertex>, vector<pair<int, Vertex>>, comparison> minHeap; //minheap priority queue to get the lowest distance.
    minHeap.push({0, source});
    
    while (!minHeap.empty()) {
        pair<int, Vertex> temp = minHeap.top();
        minHeap.pop();
        Vertex current = temp.second;
        visited.find(current)->second = true;
        for (Vertex adjacent : graph.getAdjacent(current)) {
            if (visited.find(adjacent)->second == true) {
                continue;
            }
            if ((graph.getEdgeWeight(current, adjacent) + distance[current] < distance[adjacent])) {
                distance.find(adjacent)->second = graph.getEdgeWeight(current, adjacent) + distance.find(current)->second;
                minHeap.push(pair<int, Vertex>(distance[adjacent],adjacent));
                previous.find(adjacent)->second = current;
            }  
        }
    }
    vector<Vertex> path = getPath(previous, source, destination);
    std::reverse(path.begin(),path.end());
    return path;
}

vector<Vertex> getPath(map<Vertex, Vertex> previous, Vertex source, Vertex destination) {
    vector<Vertex> path;
    while (destination != source) {
        path.push_back(destination);
        destination = previous[destination];
    }
    path.push_back(source);
    return path;
}
