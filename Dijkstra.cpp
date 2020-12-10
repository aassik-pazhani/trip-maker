#include <map>
#include <algorithm>
#include "Dijkstra.hpp"

using std::pair;
using std::map;

vector<Vertex> Dijkstra(Graph* graph, Vertex source, Vertex destination) {
    map<Vertex, int> label;
    map<Vertex, bool> visited;
    map<Vertex, Vertex> previous;
    for (Vertex v : graph->getVertices()) {
        previous.insert(pair<Vertex, Vertex> (v, NULL));
        visited.insert(pair<Vertex, bool>(v, false));
        label.insert(pair<Vertex, int> (v, INT_MAX));
    }
    label[source] = 0;
    //vector of pairs with Vertex and its distance (intially infinity)
    vector<pair<int, Vertex>> distancePair;
    for (Vertex V : graph->getVertices()) {
        if (V == source) {
            distancePair.push_back(pair<int, Vertex> (0, V));    
        } else {
            distancePair.push_back(pair<int, Vertex> (INT_MAX, V)); 
        }
    }
    heap<pair<int, Vertex>>* minHeap = new heap<pair<int, Vertex>>(distancePair);
    
    while (!minHeap->empty()) {
        pair<int, Vertex> temp = minHeap->pop();
        Vertex current = temp.second;
        visited.find(current)->second = true;
        //int distU = temp.first();
        for (Vertex adjacent : graph->getAdjacent(current)) {
            if (visited.find(adjacent)->second == true) {
                continue;
            }
            if ((graph->getEdgeWeight(current, adjacent) + label[current] < label[adjacent])) {
                label.find(adjacent)->second = graph->getEdgeWeight(current, adjacent) + label.find(current)->second;
                minHeap->push(pair<int, Vertex>(label[adjacent],adjacent));
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
    path.push_back(destination);
    if (destination == source) {
        return path;
    }
    path = getPath(previous, source, previous[destination]);
    return path;
}
