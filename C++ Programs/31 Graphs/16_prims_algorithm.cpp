#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* l; 
    bool isUndir;
    int weight;

public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        l = new list<pair<int, int>> [V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v, int wt) {
        l[u].push_back(make_pair(v, wt));
        if(isUndir) {
            l[v].push_back(make_pair(u, wt));
        }
    }

    void primsAlgo(int src) {
        // Initialized an empty Priority-Queue.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq; //We need the sorting based on weight therefore store weight in the first position in the pair.
        // Initialized an empty set of MST which is actually a visited vector with false value.
        vector<bool> mst(this->V,  false);

        // Storing the information of the edge existing between two vertex.
        vector<int> parent(this->V,-1); // The index position is the parent vertex and the data stored inside is the child vertex.
        // This vector stores the weight associated with the edges.
        vector<int> key(this->V, INT_MAX);

        //Pushing source vertex and its weight in the queue.
        pq.push(make_pair(0, src));
        key[src] = 0;

        int cost = 0; // Initialized a cost variable to find the total sum of all the edges of the MST.

        while(!pq.empty()) {
            int u = pq.top().second;
            int wt = pq.top().first;

            pq.pop();

            if(!mst[u]) {
                mst[u] = true;
                cost += wt;

                for(pair<int,int> neighbour: this->l[u]) {
                    if(!mst[neighbour.first] && key[neighbour.first]) {
                        key[neighbour.first] = neighbour.second;
                        parent[neighbour.first] = u; 
                        pq.push(make_pair(neighbour.second, neighbour.first));
                    }
                }
            }

        }

        cout<<"Final Cost of MST is: "<<cost<<endl;

        cout<<"Edges in MST:\n";
        for(int i=0;i<V;i++) {
            if(parent[i] != -1) {
                cout<<parent[i]<<" - "<<i<<" : "<<key[i]<<endl;
            }
        }
    }
};

int main() {
    // Prim's Algo Graph
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);

    graph.addEdge(1, 3, 40);

    graph.addEdge(2, 3, 50);

    graph.primsAlgo(3);

    return 0;
}