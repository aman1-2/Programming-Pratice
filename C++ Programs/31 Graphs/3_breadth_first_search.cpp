#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int vertices;
    vector<list<int>> l;
public:
    Graph(int v) {
        this->vertices = v;
        l.resize(this->vertices);
    }

    void addEdge(int vertex1, int vertex2) {
        l[vertex1].push_back(vertex2);
        l[vertex2].push_back(vertex1);
    }

    void print() {
        for(int i=0; i<l.size(); i++) {
            list<int> neighbour = l[i];
            cout<<i<<"->";
            for(int vertex:neighbour) {
                cout<<vertex<<" ";
            }
            cout<<endl;
        }
        return;
    }

    void bfs() { //Time complexity: O(V + E). Which means in worst case we would be travelling v vertices and e edges.
        //Step 1: Create a Queue to store the indices of the vertex.
        queue<int> qu;
        //Step 2: Created a vector to track which vertex we have visited.
        vector<bool> visited(this->vertices, false);
        // Start BFS from the first vertex (assuming it's vertex 0)
        qu.push(0);
        visited[0] = true;

        //Step 3: Till the time our queue is not empty till that time we need to get the front element and check its neighbours.
        while(!qu.empty()) {
            int currVertex = qu.front(); //Extracting the first vertex.
            qu.pop(); //Removing it from the queue.
            cout<<currVertex<<" "; //Printing the current vertex.

            //Step 4: Traverse neighbors of the current vertex
            list<int> neighbours = l[currVertex];
            for(int v: neighbours) {
                if(visited[v] == false) { //If any of the neighbour is not visited add it in queue and mark it visited.
                    qu.push(v);
                    visited[v] = true;
                } //And if the neighbour is already visited need not to do anything.
            }
        }
        cout<<endl;

        return;
    }
};

int main() {
    int vertices;
    cin>>vertices;
    Graph graph(vertices);
    //Adding the edges in our graph.
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(4, 2);
    graph.addEdge(5, 6);
    //Printing all the neighbours value for our graph.
    graph.print();
    //Printing the BFS traversal order.
    graph.bfs();
    return 0;
}