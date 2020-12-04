#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../readFromFile.hpp"
#include "../graphs.h"

TEST_CASE("Test Graph Constructor") {
	Graph g = Graph("small_set_airports.txt", "small_set_routes.txt");
	vector<Edge> edges = g.getEdges();

	REQUIRE(g.vertexExists("ORD"));
	REQUIRE(g.vertexExists("STL"));
	REQUIRE(g.vertexExists("BRL"));

	REQUIRE(g.edgeExists("ORD", "BRL"));
	REQUIRE(g.edgeExists("BRL", "STL"));
}
