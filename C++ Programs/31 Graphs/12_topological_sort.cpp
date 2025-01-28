#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

class Graph {
    int vertices;
    vector<list<int>> l;
    bool directed;

    void sortHelper(int sourceVertex, vector<bool> &visited, stack<int> &st) {
        //Step 1: Marked the source-vertex as true.
        visited[sourceVertex] = true;
        //Step 2: Node header.
        list<int> node = this->l[sourceVertex];
        //Step 3: Traversing on the neighbours
        for(int neighbour: node) {
            //Step 4: If neighbour is not visited then call the helper again for the neighbour.
            if(!visited[neighbour]) {
                sortHelper(neighbour, visited, st);
            }
        }
        //Step 5: While backtracking pushing the source-vertex in the stack.
        st.push(sourceVertex);
        return;
    }
public:
    Graph(int v, bool dir=false) {
        this->vertices = v;
        l.resize(this->vertices);
        this->directed = dir;
    }

    void addEdge(int vertex1, int vertex2) {
        this->l[vertex1].push_back(vertex2);
        if(!this->directed)  this->l[vertex2].push_back(vertex1);
        return;
    }

    void print() {
        for(int i=0; i<this->vertices; i++) {
            cout<<i<<"-> ";
            list<int> node = this->l[i];
            for(int neighbour: node) {
                cout<<neighbour<<" ";
            }
        }
        return;
    }

    void topologicalSort() {
        //Step 1: Created a Visited boolean vector. For tracking which nodes are visited and which not.
        vector<bool> visited(this->vertices, false);
        //Step 2: Created a stack for maintaining the topological sort order.
        stack<int> st;

        //Step 3: Looping over all the vertices and checking if a node is not visited then we will keep that node as source-vertex and call the helper function.
        for(int i=0; i<visited.size(); i++) {
            if(!visited[i]) {
                sortHelper(i, visited, st);
            }
        }

        //Step 4: Printing the stack show casing the topological order.
        while(!st.empty()) {
            int v = st.top();
            st.pop();
            cout<<v<<"->";
        }
        cout<<endl;
        return;
    }
};

int main() {
    int vertices;
    cin>>vertices;

    //DAG
    Graph graph(vertices, true);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topologicalSort();

    return 0;
}