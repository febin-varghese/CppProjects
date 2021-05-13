/*
Implementation of a graph using adjacency list
Graph:
0-----1
|    /|\
|  /  | 2
|/    |/
4-----3
*/

#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int> adj[], int src, int des);
void printGraph(vector<int> adj[], int nodes);


int main()
{
    int vertices = 5;
    vector<int> adj[vertices];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, vertices);
    return 0;
}

void addEdge(vector<int> adj[], int src, int des)
{
    adj[src].push_back(des);
    adj[des].push_back(src);
}

void printGraph(vector<int> adj[], int nodes)
{
    cout << "Adjacency list representation of the graph with " << nodes << " nodes" << endl;
    for(int n=0; n<nodes; ++n)
    {
        cout << n;
        for(auto x: adj[n])
            cout << " -> " << x;
        cout << endl;
    }
}