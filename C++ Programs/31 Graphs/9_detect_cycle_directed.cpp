#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int vertices;
    vector<list<int>> l;
    bool isUndirectd;

    bool cycleHelper(int sourceVertex, vector<bool> &visited, vector<bool> &recursionPath) {
        //Step 1: Mark the source vertex visited in the visited vector
        visited[sourceVertex] = true;
        //Step 2: Mark the source vertex as its current path part.
        recursionPath[sourceVertex] = true;

        //Step 3: Need to look for the neighbours of the source vertex.
        list<int> node = this->l[sourceVertex];
        //Step 4: Traversing on each neighbour
        for(int neighbour: node) {
            //Step 5: If the neighbour is not visited.
            if(!visited[neighbour]) {
                //Then call the helper function and make it visit and at any point the helper function returns a true value then we to need to return a true value.
                if(cycleHelper(neighbour, visited, recursionPath)) {
                    return true;
                }
            } else { //Lets say the neighbour was already visited in that case check if the neighbour is already the part of the recursion path if yes then return true because a cycle is detected.
                if(recursionPath[neighbour]) {
                    return true;
                }
            }
        }

        //Step 6: While backtracking from the cycle we need to remove the node from the recursion path as well.
        recursionPath[sourceVertex] = false;

        //Step 7: If none of the above conditions are true then return a false showing that no cycle exists.
        return false;
    }
public:
    Graph(int v, bool isUndir = true) {
        this->vertices = v;
        this->l.resize(this->vertices);
        this->isUndirectd = isUndir;
    }

    void addEdge(int vertex1, int vertex2) {
        this->l[vertex1].push_back(vertex2);
        if(isUndirectd) {
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

    bool isCycleDirectedGraph() {
        //Step 1: Need to create a visited and recursion path vector where the visited will track the nodes visited and recursion path is for tracking current recursion path.
        vector<bool> visited(this->vertices, false);
        vector<bool> recursionPath(this->vertices, false);

        int sourceVertex = 0;
        for(int i=0; i<this->vertices; i++) { //This loop is showing that we are traving on each compoent of graph if we have disconnected component.
            //Step 2: If any node or vertex is not visited then call the helper function of cycle detection for that vertex.
            if(!visited[i]) {
                //Step 3: If any point the helper function returns a true value then we too need to return a true value.
                if(cycleHelper(i, visited, recursionPath)) {
                    return true; //Indicating that a cycle exists
                }
            }
        }

        //Step 5: If none of the above condition evaluates try means there is no cycle in the graph.
        return false;
    }
};

int main() {
    int v;
    cin>>v;

    Graph graph(v, false);
    //Directed Graph
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    // graph.addEdge(3,0); // This is the edge which give rise to cycle in the graph.
    graph.addEdge(1,0);

    cout<<graph.isCycleDirectedGraph();

    return 0;
}