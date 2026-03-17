#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge {
public:

    int source;
    int destination;
    int weight;

    Edge(int u, int v, int wt) {
        this-> source = u;
        this->destination = v;
        this->weight = wt;
    }
};

class Graph {
public:

    int vertices;
    vector<Edge> edgeList;

    vector<int> parent;
    vector<int> rank;

    Graph(int v) {
        this->vertices = v;

        parent.resize(this->vertices);
        rank.resize(this->vertices, 0);

        for(int i=0; i<this->vertices; i++) {
            parent[i] = i;
        }
    }

    void addEdge(int u, int v, int wt) {
        edgeList.push_back(Edge(u, v, wt));
    }

    int find(int ele) {
        if(parent[ele] == ele)  return ele;
        return parent[ele] = find(parent[ele]);
    }

    void unionByRank(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);

        if(rank[parentU] == rank[parentV]) {
            parent[parentV] = parentU;
            rank[parentU]++;
        } else if(rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        } else {
            parent[parentU] = parentV;
        }
    }

    //Time-Complexity - O(e log e), where e is the edges
    void kruskals() {
        int minCost = 0;
        int count = 0;

        // STEP 1: sorting the Edge's Vector. Time-Complexity - O(e log e)
        sort(edgeList.begin(), edgeList.end(), [](Edge &a, Edge &b){ return (a.weight < b.weight); });

        // STEP 2: Loop on the smallest Weight till the time we have no cycle. if we have cycle skip the edge.
        for(int i=0; i<edgeList.size() && count<this->vertices-1; i++) {
            Edge e = edgeList[i];
            // We are extracting parents to identify if there is any cycle passing throug this edge.
            int parentU = find(e.source);
            int parentV = find(e.destination);
            // If parentU = parentV then it means a cycle exists.
            if(parentU != parentV) { // No cycle edge
                unionByRank(parentU, parentV);
                minCost += e.weight;
                count++;
            }
        }

        cout<<"Minimum Cost of the MST: "<<minCost<<endl;

        return;
    }

}; 

int main() {
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    graph.kruskals();

    return 0;
}