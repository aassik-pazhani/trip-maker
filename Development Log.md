Week 1-Nov 21st

This week, our team decided on our project goals and and completed our team contract. 
We also set up our workspace, which included cloning the provided demo repo and started brainstorming
on how to implement graphs. We discussed the basic methods of how to implement a graph, such as creating 
a graph with the nodes as the airports and the edges as the direct flights/routes between airports. 
For next week, we will study implementation of graphs and start implementing it this week.

Week 2-Nov 28th

This week, our team implemented a basic graph class. We added all necessary functions in a standard graph 
class, along with the constructor of the graph class. Our constructor is able to read in a .txt file of 
airports written in IATA code format as well as a .txt file containing routes between two airpots in IATA 
to create a basic graph consisting of nodes as airports and edges as routes between two designated airports.
We also added a list of all airports by IATA code along with two smaller .txt files containing 3 airports and 
2 routes for easy testing. For next week, we will continue to improve upon other functions in the our graph class.

Week 3-Dec 5th

This week, our team fixed some issues concerning our constructor not being able to insert edges between two
verticies. We also created a Makefile to easily compile and test our code, as well as added test cases to test 
out our creation of a simple graph consisting of 2 routes between 3 airports. We also implemented a BFS traversal 
that contains search functionalities that allow us to add to our destinations list as well as mark airports that 
have been visited. Next week, we will add weights to our graphs (likely by assigning each node their respective 
coordinates) and implement the two shortest path algorithms - Dijkstra’s Algorithm and Landmark Path Algorithm. 
