#include "../catch/catch.hpp"
#include "../readFromFile.hpp"
#include "../xytodistance.hpp"
#include "../Dijkstra.hpp"
#include "../Landmark.hpp"
#include "../graphs.h"
#include "../BFS.h"

#include <string>
#include <vector>

TEST_CASE("Testing Dijkstra") {
    //std::string airport_file = "small_set_airports.txt";
    //std::string route_file = "small_set_routes.txt";
	std::string airport_file = "airports.txt";
    std::string route_file = "routes.txt";
    Graph g = Graph(airport_file, route_file);
    vector<Vertex> path = Dijkstra(g, "CMI", "LAX");
	REQUIRE(path[0] == "CMI");
	REQUIRE(path[1] == "DFW");
	REQUIRE(path[2] == "LAX");
}

TEST_CASE("Testing LandMark") {
    //std::string airport_file = "small_set_airports.txt";
    //std::string route_file = "small_set_routes.txt";
	std::string airport_file = "airports.txt";
    std::string route_file = "routes.txt";
    Graph g = Graph(airport_file, route_file);
	vector<Vertex> destinations;
	destinations.push_back("ORD");
	destinations.push_back("LAX");

    vector<Vertex> path = Landmark(g, "CMI", destinations);
	REQUIRE(path[0] == "CMI");
	REQUIRE(path[1] == "ORD");
	REQUIRE(path[2] == "ORD");
	REQUIRE(path[3] == "LAX");
}

TEST_CASE("getDistance") {
	double distance = getDistance(pair<double, double>(12,12), pair<double, double>(-12,-12));
	int dis = round(distance);
    REQUIRE(dis == 3760);
}

TEST_CASE("Test Graph Constructor") {
	//std::string airport_file = "small_set_airports.txt";
	//std::string route_file = "small_set_routes.txt";
	std::string airport_file = "airports.txt";
    std::string route_file = "routes.txt";
	Graph g = Graph(airport_file, route_file);
	vector<Edge> edges = g.getEdges();
	
	REQUIRE(g.vertexExists("ORD"));
	REQUIRE(g.vertexExists("STL"));
	REQUIRE(g.vertexExists("BRL"));

	REQUIRE(g.edgeExists("CMI", "ORD"));
	REQUIRE(g.edgeExists("BRL", "STL"));
}

TEST_CASE("Testing coordinates") {
    vector<pair<double, double>> coord = getCoordinates("small_set_airports.txt");
	REQUIRE(coord[0].first == 41.9786);
	REQUIRE(coord[0].second == -87.9048);
}

TEST_CASE("Testing BFS") {
	std::string airport_file = "small_set_airports.txt";
	std::string route_file = "small_set_routes.txt";
	//std::string airport_file = "airports.txt";
    //std::string route_file = "routes.txt";
	Graph g = Graph(airport_file, route_file);
	BFS bfs = BFS(g);
	bfs.search();

	vector<Vertex> dest = {"ORD", "STL", "BRL"};
	for (Vertex v : dest) {
		REQUIRE(std::find(bfs.destinations.begin(), bfs.destinations.end(), v) != bfs.destinations.end());
	}
}
