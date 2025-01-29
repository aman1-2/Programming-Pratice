#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph {
    int vertices;
    list<int>* l;
    bool isDir;
public:
    Graph(int v, bool isdir = false) {
        this->vertices = v;
        l = new list<int> [this->vertices];
        this->isDir=isdir;
    }
    
    void addEdge(int vertex1, int vertex2) {
        this->l[vertex1].push_back(vertex2);
        if(!isDir)   this->l[vertex2].push_back(vertex1);
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

    void calculateIndegree(vector<int> &indegree) {
        //Step 1: Looping on each vertex of the graph.
        for(int i=0; i<this->vertices; i++) {
            list<int> node = this->l[i]; //Looping on the neighbour of the vertex.
            for(int neighbour: node) { //The number of times a node has become some other nodes neighbour its indegree will increase.
                indegree[neighbour]++;
            }
        }
        return;
    }

    void topologicalSort() { //Kahn's Algorithm.
        //Step 1: Created a Indegree vector. Where we will store the indegree value for each node.
        vector<int> indegree(this->vertices, 0);
        //Step 2: Calling a Function which we give us the indegree of the nodes.
        calculateIndegree(indegree);
        //Step 3: Created a Queue like in BFS we use to do to have the correct topological sort order.
        queue<int> qu;

        //Step 4: Traversing on each vertex and checking which so ever vertex will have its indegree value those all vertices will become the starting nodes for the graph.
        for(int i=0; i<this->vertices; i++) {
            if(indegree[i] == 0) {
                //if the indegree of a node comes out to be 0 then push it inside the queue.
                qu.push(i);
            }
        }

        //Now the BFS logic
        //Step 5: Till the time Queue is not empty loop on the queue and check.
        while(!qu.empty()) {
            //For the current vertex.
            int curr = qu.front();
            qu.pop();
            cout<<curr<<" ";
            //Step 6: Loop over the neighbours of the current node.
            list<int> node = this->l[curr];
            for(int neighbour: node) {
                //Step 7: And reduce the indegree count of its neighbour as one of its dependency has been already processed.
                indegree[neighbour]--;
                //Step 8: Then Check if any of the neighbours indegree has become 0 or not if it has become 0 then add it inside the queue.
                if(indegree[neighbour] == 0) { //No pending dependencies
                    //Only those nodes will be pushed in the Queue whose neighbours indegree is 0.
                    qu.push(neighbour);
                }
            }
        }
        cout<<endl;
    }
};

int main() {
    int v;
    cin>>v;
    Graph graph(v,true);

    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topologicalSort();

    return 0;
}