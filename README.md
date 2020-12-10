# Final Project

## Project Goal

The primary aim of this project is to identify the shortest route between two given airport destinations by using Dijkstra's and Landmark Algorithms. If there exists a *direct* route between the two airport destinations, Dijkstra's algorithm will be used. If a direct route does not exist, the shortest route accounting layover flights will be identified using the Landmark algorithm.

### Datasets and Traversals

This project will use the [OpenFlights](https://openflights.org/data.html/) dataset. The unique IATA identifier code will be used thoughout the project when referring to airports. Our project uses BFS when traversing the tree.

### Running The Program

To run our program, open `main.cpp` and scroll down to the `outputs` vector. It will look similar to this:

```
vector<Vertex> output = Dijkstra(g, "ORD", "LAX"); 
```
Here, you can insert any two IATA codes of your choosing. In your terminal, run `make` followed by `./finalproj`. If everything goes smoothly, nothing will happen (in the terminal)!

Next, locate the `outputs` folder in the workspace and navigate to `dijkstraOutput.txt`. Here, you will see a list of airports by IATA code. This sorted list is the shortest path between the two airports listed.

**Note:** To make your own tests, navigate to `tests.cpp` and create your own tests. To run tests, go into your terminal, type `make test` followed by `./test`.
