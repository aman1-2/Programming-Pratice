#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int vertices;
    list<int>* l;

    bool undirectedCycleHelper(int sourceVertex, vector<bool> &visited, int parent) { //T.C -> O(V + E).
        //This is same as our DFS logic with a little difference in it.
        //Step 1: Mark the Source vertex as visited.
        visited[sourceVertex] = true;

        //Step 2: Extracting the information of the node which has information of its neighbour vertex.
        list<int> node = this->l[sourceVertex];
        //Step 3: Looping on each neighbour of the node.
        for(int neighbour:node) {
            //Step 4: If the neighbour is not visited then make a visit.
            if(!visited[neighbour]) {
                //We make a call to visit our neighbour with the parent value as the current node's value which is source node's value.
                if(undirectedCycleHelper(neighbour, visited, sourceVertex)) { //If here it returns a True value. Then we to need to return a true value for our function.
                    return true;
                }
            } else { //Suppose the neighbour is already visited in that case the check if the neighbour is equal to parent or not. If not equal to parent then to return true. This indicate a cycle is detected.
                if(neighbour != parent) return true;
            }
        }

        //Step 5: If none of the above condition is true this means there is not cycle in the graph and we need to return a false value.
        return false;
    }
public:
    Graph(int v) {
        this->vertices = v;
        l = new list<int> [this->vertices];
    }

    void addEdge(int vertex1, int vertex2) {
        l[vertex1].push_back(vertex2);
        l[vertex2].push_back(vertex1);
        return;
    }

    void print() {
        for(int i=0; i<this->vertices; i++) {
            cout<<i<<"-> ";
            list<int> vertex = l[i];
            for(int neighbour: vertex) {
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
        return;
    }

    bool isCycleUndirected() {
        //Here we have assumed we are getting a connected graph and there is no disconnected component in it.
        //Step 1: Created a Vector visited of boolean to track which node we have visited which not.
        vector<bool> visited(this->vertices, false);
        int sourceVertex = 0;
        //Step 2: Making a call to our helper function for detecting its value and whatsoever will be the output of undirectedHepler will be our answer.
        return undirectedCycleHelper(sourceVertex, visited, -1); //We called the helper with three parameters as the source vertex on which dfs is made, visited vector, parent node.
    }
};

int main() {
    int v;
    cin>>v;
    
    Graph graph(v);
    //Undirected Graph
    graph.addEdge(0,1);
    // graph.addEdge(0,2); // this edge was making a cycle
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(3,4);

    cout<<graph.isCycleUndirected();

    return 0;
}