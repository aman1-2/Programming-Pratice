#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int vertices;
    vector<list<int>> l;

    void dfsHelper(int sourceVertex, vector<bool> &visited) {
        visited[sourceVertex] = true; //Marked the passed vertex as visited in the visited vector.
        cout<<sourceVertex<<" "; //Printed it as marked visited
        
        list<int> vertex = l[sourceVertex]; //Storing the head's value for that vertex linked list
        for(int neighbour:vertex) { //Make a traversal on the neighbours of that vertex.
            if(!visited[neighbour]) { //If a particular neighbour of the vertex is marked unvisited then pass it into dfs to travel it.
                dfsHelper(neighbour, visited);
            }
        }

        return;
    }
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
        for(int i=0; i<this->vertices; i++) {
            cout<<i<<"->";
            list<int> vertex = l[i];
            for(int neighbour:vertex) {
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
        return;
    }

    void dfs() { //Time complexity: O(v + e)
        //Step 1: Created a vector to track which vertex we have visited.
        vector<bool> visited(this->vertices, false);
        //Step 2: Start BFS from the first vertex (assuming it's vertex 0)
        int sourceVertex = 0;
        //Step 3: Made a call to dfsHelper which has actual logic of DFS running.
        dfsHelper(sourceVertex, visited);
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
    //dfs traversing
    graph.dfs();

    return 0;
}   