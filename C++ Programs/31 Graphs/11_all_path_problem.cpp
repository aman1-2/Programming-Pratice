#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int vertices;
    vector<list<int>> l;
    bool isDirected;

    void pathHelper(int srcVertex, int destVertex, vector<bool> &visited, string &path) { //Time complexity - O(V + E)
        //Step 1: Base case if both the source and destination vertex are equal then print the path and return.
        if(srcVertex == destVertex) {
            cout<<path<<destVertex<<endl;
            return;
        }

        //Step 2: Otherwise mark the source vertex visited.
        visited[srcVertex] = true;
        //Step 3: Adding the source vertex into the path.
        path += to_string(srcVertex);

        //Step 4: Traversing the neighbours of the node.
        list<int> node = this->l[srcVertex];
        for(int neighbour: node) {
            //Step 5: If the neighbour is not visited then call the helper function
            if(!visited[neighbour]) {
                pathHelper(neighbour, destVertex, visited, path);
            }
        }

        //Step 6: While backtracking remove the node from path.
        path = path.substr(0, path.size()-1);
        //Step 7: While backtracking mark the visited node unvisited so that they can be used in next path formation.
        visited[srcVertex] = false;

        return;
    }
public:
    Graph(int v, bool isDir = true) {
        this->vertices = v;
        this->isDirected = isDir;
        l.resize(this->vertices);
    }

    void addEdge(int vertex1, int vertex2) {
        this->l[vertex1].push_back(vertex2);
        if(this->isDirected) {
            this->l[vertex2].push_back(vertex1);
        }

        return;
    }

    void print() {
        for(int i=0; i<this->vertices; i++) {
            cout<<i<<"-> ";
            list<int> node = this->l[i];
            for(int neighbour: node) {
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
        return;
    }

    void printAllPath(int srcVertex, int destVertex) {
        vector<bool> visited(this->vertices, false);
        string path = "";
        pathHelper(srcVertex, destVertex, visited, path);
    }

};

int main() {
    int v;
    cin>>v;
    //Undirected graph
    Graph graph(v, false);

    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1); //This edge connection will make it a non-bipartite.
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.printAllPath(5,1);

    return 0;
}