#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph {
    int vertices;
    list<int>* l;
    bool isDirected;

    //Time complexity is O(v+e)
    void dfshelper(int sourceVertex, int parent, vector<int> &dt, vector<int> &low, vector<bool> &visited, int time, vector<bool> &ap) {
        visited[sourceVertex] = true;
        dt[sourceVertex] = low[sourceVertex] = ++time;

        int child = 0; //Here we are going to track the value of our children where in starting the valu of children is going to be equal to 0.

        list<int> node = this->l[sourceVertex];
        for(int neighbour: node) {
            //Case 1: When neighbour and parent are equal
            if(neighbour == parent) continue; //if parent and neighbour are equal just ignore
            else if(visited[neighbour]) { //case 2: Already visited
                low[sourceVertex] = min(low[sourceVertex], dt[neighbour]);
            } else { //case 3: Not visited
                this->dfshelper(neighbour, sourceVertex, dt, low, visited, time, ap);
                low[sourceVertex] = min(low[sourceVertex], low[neighbour]);
                //now making a check for our Articulation Point condition.
                if(parent != -1 && dt[sourceVertex] <= low[neighbour]) {
                    ap[sourceVertex] = true;
                }
                child++;
            }
        }

        if(parent == -1 && child > 1)   ap[sourceVertex] = true;

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

    void articulationTarjan() {
        //Step 1: Created two array's of Discovery time and Lowest Discovery time.
        vector<int> dt(this->vertices); //Discovery time
        vector<int> low(this->vertices); //Lowest Discovery time

        //Step 2: Create a time variable with its initiale value with t=0 and every time this time value keep on increasing each time we visit a new vertex.
        int time = 0;

        //Step 3: Create a Visited vector to track which nodes we have visited.
        vector<bool> visited(this->vertices, false);

        //Step 4: To track the articulation points we create this vector so that it shouldn't happen that one node coming more than one time as AP.
        vector<bool> ap(this->vertices  );

        //Step 5: We make a call for our dfs if the node is not visited.
        for(int i=0; i<this->vertices; i++) {
            if(!visited[i]) {
                this->dfshelper(i, -1, dt, low, visited, time, ap);
            }
        }

        //Step 6: Printing all the articulation points
        for(int i=0; i<this->vertices; i++) {
            if(ap[i]) {
                cout<<"Articulation Point: "<<i<<endl;
            }
        }
    }
};

int main() {
    int vertices = 6;
    Graph graph(vertices, true);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 1);
    graph.addEdge(3, 0);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 3);

    graph.articulationTarjan();

    // graph.addEdge(4, 5);
    // graph.addEdge(5, 3);
    // graph.addEdge(5, 4);

    
    return 0;
}