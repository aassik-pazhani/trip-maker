#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../readFromFile.hpp"
#include "../graphs.h"
#include "../BFS.h"

TEST_CASE("Test Graph Constructor") {
	Graph g = Graph("small_set_airports.txt", "small_set_routes.txt");
	vector<Edge> edges = g.getEdges();

	REQUIRE(g.vertexExists("ORD"));
	REQUIRE(g.vertexExists("STL"));
	REQUIRE(g.vertexExists("BRL"));

	REQUIRE(g.edgeExists("ORD", "BRL"));
	REQUIRE(g.edgeExists("BRL", "STL"));
}

TEST_CASE("Testing BFS") {
	Graph g = Graph("small_set_airports.txt", "small_set_routes.txt");
	BFS bfs = BFS(g);
	bfs.search();

	vector<Vertex> dest = {"ORD", "STL", "BRL"};
	for (Vertex v : dest) {
		REQUIRE(std::find(bfs.destinations.begin(), bfs.destinations.end(), v) != bfs.destinations.end());
	}
}
