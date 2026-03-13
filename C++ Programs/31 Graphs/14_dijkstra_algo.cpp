#include<iostream>
#include<vector>
#include<queue>
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

// Time-Complexity - O((V+E) log V)
// Prameters - source node, graph, no. of vertices
void dijkstra(int src, vector<vector<Edge>> graph, int V) {
    // pair(distance, vertex) - because sorting performed on first passed value.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq; // min-heap

    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src)); //Pushing the first node-0
    dist[src] = 0; //distance from node-0 to node-0 is 0.

    //Bfs algorithm
    while(!pq.empty()) {
        int u = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        // check whether a node was already processed with a smaller distance.
        if(currDist > dist[u]) continue;

        // graph[u] will have all the edges coming out from u. In short-neighbours

        vector<Edge> edges = graph[u];
        for(Edge e: edges) {
            // Edge-Relaxation step
            if(dist[e.destination] > dist[u] + e.weight) {
                dist[e.destination] = dist[u] + e.weight;
                pq.push(make_pair(dist[e.destination], e.destination));
            }
        }
    }

    for(int d: dist) {
        cout<<d<<" ";
    }
    cout<<endl;
}

int main() {
    int vertices = 6;
    vector<vector<Edge>> graph(vertices);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(2, 5));

    dijkstra(1, graph, vertices);

    return 0;
}