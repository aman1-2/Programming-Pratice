#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int vertices;
    vector<list<int>> arr;

    void dfsHelper(int sourceVertex, vector<bool> &visited) {
        visited[sourceVertex] = true; //Marking it visited
        cout<<sourceVertex<<" "; //Printing the vertex.

        list<int> vertex = this->arr[sourceVertex]; //Storing the head's value for that vertex linked list
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
        arr.resize(this->vertices);
    }

    void addEdge(int vertex1, int vertex2) {
        arr[vertex1].push_back(vertex2);
        arr[vertex2].push_back(vertex1);
        return;
    }

    void print() {
        for(int i=0; i<this->vertices; i++) {
            cout<<i<<"-> ";
            list<int> vertex = arr[i];
            for(int neighbours: vertex) {
                cout<<neighbours<<" ";
            }
            cout<<endl;
        }
    }

    void dfs() { //Time complexity: O(v + e)
        //Step 1: Created a vector to track which vertex we have visited.
        vector<bool> visited(this->vertices, false);
        //Step 2: Looping and checkin on the visited vector that if we have visited all the vertex of the Graph or not.
        for(int i=0; i<this->vertices; i++) {
        //Step 3: If any vertex we have not visited then we will call the dfs method for that vertex.
            if(!visited[i]) {
                dfsHelper(i, visited);
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

    graph.dfs();

    return 0;
}