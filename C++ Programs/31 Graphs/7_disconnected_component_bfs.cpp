#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int vertices;
    vector<list<int>> arr;

    void bfsHelper(int sourceVertex, vector<bool> &visited) {
        queue<int> qu;
        qu.push(sourceVertex);
        visited[sourceVertex] = true;

        while(!qu.empty()) {
            int node = qu.front();
            cout<<node<<" ";
            qu.pop();

            list<int> vertex = this->arr[node];
            for(int neighbours: vertex) {
                if(!visited[neighbours]){
                    qu.push(neighbours);
                    visited[neighbours] = true;
                }
            }
        }

        return;
    }
public:
    Graph(int v) {
        this->vertices = v;
        arr.resize(this->vertices);
    }

    void addEdge(int vertex1, int vertex2) {
        arr[vertex1].push_back(vertex2);
        arr[vertex2].push_back(vertex1);
        return;
    }

    void bfs() {
        vector<bool> visited(this->vertices, false);
        for(int i=0; i<this->vertices; i++) {
            if(!visited[i]) {
                bfsHelper(i, visited);
            }
        }
        return;
    }
};

int main() {
    int vertices;
    cin>>vertices;

    Graph graph(vertices);

    graph.addEdge(1,6);
    graph.addEdge(6,4);
    graph.addEdge(4,3);
    graph.addEdge(4,9);
    graph.addEdge(3,8);
    graph.addEdge(3,7);
    graph.addEdge(2,5);
    graph.addEdge(2,0);

    graph.bfs();

    return 0;
}