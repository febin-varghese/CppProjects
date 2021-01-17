/*
Coursera course: C++ For C Programmers, Part A 
Implement a Monte Carlo simulation that calculates the average shortest path in a graph.
The program contains 3 classes: Graph, PriorityQueue and ShortestPath
All classes are written in the same file.
*/

#include<iostream>
#include<vector>
#include <exception>

using namespace std;

/*
Undirected graph
*/
class Graph
{
	int vertices;
	int edges;
	vector <vector <double>> adjacency_matrix;  // 2D matrix
	
	public:
		Graph(int v);
		int V();
		int E();
		void print_adj_matrix();
		bool adjacent(int x, int y);
		vector <int> neighbors(int x);
		void add(int x, int y);
		void delete_edge(int x, int y);
		//double get_node_value(int x);
		//void set_node_value(int x, double a);
		double get_edge_value(int x, int y);
		void set_edge_value(int x, int y, double v);
		
		
		
};

// function definitions

Graph::Graph(int v):vertices(v), edges(0), adjacency_matrix(v, vector<double>(v, 0))
{
	cout << "Graph initialized with " << v << " nodes" << endl;
}

Graph::V()
{
	return vertices;
}

Graph::E()
{
	return edges;
}

void Graph::print_adj_matrix()
{
	for(int i = 0; i < adjacency_matrix.size(); i++)
	{
		for (int j = 0; j < adjacency_matrix[i].size(); j++)
			cout << adjacency_matrix[i][j] << " ";
		cout << endl;
	}
}

bool Graph::adjacent(int x, int y)
{	
	return adjacency_matrix[x][y] > 0;
}

vector<int> Graph::neighbors(int x)
{
	vector<unsigned int> neighbor_nodes;
	for(int i=0; i < adjacency_matrix[x].size(); i++)
		if (adjacency_matrix[x][i] > 0)
			neighbor_nodes.push_back(i);
	return neighbor_nodes;
}

void Graph::add(int x, int y, double weight)
{
	if (weight <= 0)
		throw invalid_argument("Weight of an edge should be greater than zero.");
	if (adjacency_matrix[x][y] == 0)
	{
		adjacency_matrix[x][y] = weight;
		edges++;
	}
}

void Graph::delete_edge(int x, int y)
{
	if (adjacency_matrix[x][y] > 0)
	{
		adjacency_matrix[x][y] = 0;
		edges--;
	}
}

double Graph::get_edge_value(int x, int y)
{
	return adjacency_matrix[x][y];
}

void Graph::set_edge_value(int x, int y, double v)
{
	if (weight <= 0)
		throw invalid_argument("Weight of an edge should be greater than zero. Use delete to remove an edge");
	if (adjacency_matrix[x][y] == 0)
		edges++;
	adjacency_matrix[x][y] = v;
}
		

/*
Priority queue
*/
class PriorityQueue
{
	vector<int> pq;
	
	public:
	PriorityQueue();
    void chgPriority(NodeInfo n);
    void minPriority();
    bool contains(NodeInfo n);
    void insert(NodeInfo n);
    int size();
};

PriorityQueue::PriorityQueue(){}


/*
Monte Carlo simulation to create graph
*/
class MonteCarloSimulation
{
	int total_nodes;
	double density;
	double min_distance;
	double max_distance;
	
	public:
	MonteCarloSimulation(int n, double d, double min_d, double max_d);
}

MonteCarloSimulation::MonteCarloSimulation(int n=50, double d=0.2, double min_d=1.0, double max_d=10.0):
total_nodes(n), density(d), min_distance(min_d), max_distance(max_d){}

int main()
{
	Graph graph_obj(3);
	cout<< graph_obj.V() << endl << graph_obj.E() << endl;
	graph_obj.print_adj_matrix();
	if (graph_obj.adjacent(0, 0))
		cout << "0 is connected with 0";
	else
		cout << "There is no connection between node 0 and 0";
	
	
	return 0;
}

