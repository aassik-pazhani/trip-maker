#include "graphs.h"
//#include "heap.h"
#include <map>
using std::map;
struct comparison {
    bool operator()(const pair<int, Vertex> &lhs, const pair<int, Vertex> &rhs) const
    {
        return lhs < rhs;
    }
};
vector<Vertex> Dijkstra(Graph* graph, Vertex source, Vertex destination);
vector<Vertex> getPath(map<Vertex, Vertex> previous, Vertex source, Vertex destination);