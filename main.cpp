#include <iostream>
#include <vector>
#include "graphs.h"
#include "Dijkstra.hpp"
#include "Landmark.hpp"
#include "BFS.h"
#include <fstream>
using std::vector;
using std::string;
using std::ofstream;

int main() {
    /*
     * This writes the the shortest path from one airport to 
	 * another to "dijkstraOutput.txt" inside the "outputs" folder
     */
	ofstream write("outputs/dijkstraOutput.txt");
	Graph g = Graph("airports.txt", "routes.txt");
	vector<Vertex> output = Dijkstra(g, "SIN", "CMI"); 
	//feel free to change the source and destination to check the shortest route between two locations
	for (Vertex v : output) {
		write << v << "\n";
	}
	write.close();
	
	write.open("outputs/bfsOutput.txt");
	BFS bfs = BFS(g);
	bfs.search();
	for (Vertex v : bfs.destinations) {
		write << v << "\n";
	}
	write.close();

	write.open("outputs/landmarkOutput.txt");
	vector<Vertex> destinations;
	destinations.push_back("CMI");
	destinations.push_back("LAX");
	destinations.push_back("LHR");
	destinations.push_back("DXB");
	destinations.push_back("SIN");
	destinations.push_back("MAA");
    destinations.push_back("SZG");
    destinations.push_back("JFK");
	vector<Vertex> landmark = Landmark(g,"ORD", destinations);
	//feel free to change the source and destinations to check the shortest route for the whole journey around the world
	for (Vertex v : landmark) {
		write << v << "\n";
	}
	write.close();
	return 0;
}
