#include "graphs.h"
#include "heap.h"
#include <map>
using std::map;
vector<Vertex> Dijkstra(Graph* graph, Vertex source, Vertex destination);
vector<Vertex> getPath(map<Vertex, Vertex> previous, Vertex source, Vertex destination);