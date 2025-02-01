#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph {
    int vertices;
    list<int>* l;
    bool isDirected;

    void topoSortHelper(int sourceVertex, vector<bool> &visited, stack<int> &st) {
        visited[sourceVertex] = true;
        
        list<int> node = this->l[sourceVertex];
        for(int neighbours: node) {
            if(!visited[neighbours])    topoSortHelper(neighbours, visited, st);
        }

        st.push(sourceVertex);
        return;
    }

    void dfsHelper(int sourceVertex, vector<bool> &visited) {
        visited[sourceVertex] = true;
        cout<<sourceVertex<<" ";

        list<int> node = this->l[sourceVertex];
        for(int neighbour: node) {
            if(!visited[neighbour]) {
                dfsHelper(neighbour, visited);
            }
        }

        return;
    }

public:
    Graph(int vert, bool isDir = false) {
        this->vertices = vert;
        this->l = new list<int> [this->vertices];
        this->isDirected = isDir;
    }

    void addEdge(int vertex1, int vertex2) {
        this->l[vertex1].push_back(vertex2);
        if(!this->isDirected)   this->l[vertex2].push_back(vertex1);
        return;
    }

    void print() {
        for(int i=0; i<this->vertices; i++) {
            cout<<i<<"-> ";
            list<int> node = this->l[i];
            for(int neighbours: node) {
                cout<<neighbours<<" ";
            }
            cout<<endl;
        }
        return;
    }

    void topoSort() {
        vector<bool> visited(this->vertices, false);
        stack<int> st;
        for(int i=0; i<visited.size(); i++) {
            if(!visited[i])
                topoSortHelper(i, visited, st);
        }

        while(!st.empty()) {
            cout<<st.top()<<" ";
            st.pop();
        }

        return;
    }

    void kosaraju() { //Time complexity -> O(v+e)
    
        //Step 1: In this step we need to perform a topological sort and store each element in topological order with in the stack.
        stack<int> st;
        vector<bool> visited(this->vertices, false);
        
        for(int i=0; i<this->vertices; i++) {
            if(!visited[i]) this->topoSortHelper(i, visited, st);
        }

        //At the end of this loop we will have our topological order stored in the stack.

        //Step 2: Now we need to create a Transpose Graph from the original Graph.
        //Just like we use to create a normal graph in similar way we can create our transpose graph.
        Graph transpose(this->vertices, true);
        //Now we need that this transpose graph must have same number of vertices which we have in the original graph just the direction of the edge must be different.
        //Therefore first we need to find each edge of the original graph.
        for(int i=0; i<this->vertices; i++) {
            visited[i] = false; //we need to use this visited array again therefore just re-initialized it here.

            //Firstly we will extract each vertex and then for each vertex we will be find out there edges.
            list<int> node = this->l[i];
            for(int neighbour: node) {
                transpose.addEdge(neighbour, i); //Here we have reversed our edge.
            }
        }


        //Step 3: Now this step says that we need to perform our DFS logic on the transpose graph according to the node order of stack.
        while(!st.empty()) {
            int curr = st.top();
            st.pop();
            if(!visited[curr]) {
                cout<<"SCC -> ";
                transpose.dfsHelper(curr, visited); //This will help us to print our strongly connected component.
                cout<<endl;
            }
        }
        return;
    }
};

int main() {
    int vertices = 5;
    Graph graph(vertices, true);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 0);
    graph.addEdge(2, 1);
    graph.addEdge(3, 4);

    graph.kosaraju();
    return 0;
}