#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Edge {
public:

    int destination;
    int weight;

    Edge(int v, int wt) {
        this->destination = v;
        this->weight = wt;
    }
};

// Time-Complexity : O(V*E)
void bellmanFord(vector<vector<Edge>> graph, int V, int src) {
    vector<int> dist(V, INT_MAX); // Initializing the distance vector.
    dist[src] = 0;

    for(int i=0; i<V-1; i++) { // Outer loop is running on an average V times.
        // For traversing every single Edge.
        for(int u=0; u<V; u++) { // Inner loop is running total number of edges we have times
            for(Edge neighbour: graph[u]) {
                //Edge-Relaxation Step - You must check that dist[u] is reachable first.
                if(dist[u] != INT_MAX && dist[neighbour.destination] > dist[u] + neighbour.weight) {
                    dist[neighbour.destination] = dist[u] + neighbour.weight;
                }
            }
        }
    }

    for(int d: dist)    cout<<d<<" ";
    cout<<endl;

    return;
}

int main() {
    int vertices = 5;
    vector<vector<Edge>> graph(vertices);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, -4));

    graph[2].push_back(Edge(3, 2));

    graph[3].push_back(Edge(4, 4));

    graph[4].push_back(Edge(1, -1));

    bellmanFord(graph, vertices, 4);

    return 0;
}