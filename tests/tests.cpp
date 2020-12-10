#include "../catch/catch.hpp"
#include "../readFromFile.hpp"
#include "../xytodistance.hpp"
#include "../Dijkstra.hpp"
#include "../graphs.h"
#include "../BFS.h"

#include <string>
#include <vector>

TEST_CASE("Test Graph Constructor") {
	std::string airport_file = "small_set_airports.txt";
	std::string route_file = "small_set_routes.txt";
	Graph g = Graph(airport_file, route_file);
	vector<Edge> edges = g.getEdges();
	
	REQUIRE(g.vertexExists("ORD"));
	REQUIRE(g.vertexExists("STL"));
	REQUIRE(g.vertexExists("BRL"));

	REQUIRE(g.edgeExists("ORD", "BRL"));
	REQUIRE(g.edgeExists("BRL", "STL"));
}

TEST_CASE("Testing BFS") {
	std::string airport_file = "small_set_airports.txt";
	std::string route_file = "small_set_routes.txt";
	Graph g = Graph(airport_file, route_file);
	BFS bfs = BFS(g);
	bfs.search();

	vector<Vertex> dest = {"ORD", "STL", "BRL"};
	for (Vertex v : dest) {
		REQUIRE(std::find(bfs.destinations.begin(), bfs.destinations.end(), v) != bfs.destinations.end());
	}
}
