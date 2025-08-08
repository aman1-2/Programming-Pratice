#include<iostream>
#include<vector>
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

    return 0;
}