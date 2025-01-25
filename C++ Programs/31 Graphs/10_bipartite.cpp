#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int vertices;
    vector<list<int>> l;
    bool isDirected;
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

    bool isBipartitie() {
        //Step 1: Create a Queue for tracking the neighbour node in level wise.
        queue<int> qu;
        //Step 2: Create a boolean visited and color vector where the visited has initally false stored in it and color has initally -1 stored as its value.
        // vector<bool> visited(this->vertices, false);
        vector<int> color(this->vertices, -1);
        //Here instead of having two vectors we can have one itself.

        //Step 3: We have sourceVertex as 0 from where the traversal will start.
        int sourceVertex = 0;
        //Step 4: Pushing the source vertex in the queue.
        qu.push(sourceVertex);
        //Step 5: Giving a color to the source vertex.
        color[0] = 0;
        //Step 6: Since source vertex is added in queue it means it has been visited therefore updated the value of source vertex in the visited vector.
        // visited[sourceVertex] = true;

        //Step 7: Till the time or queue is not empty we will keep on checking the following condition.
        while(!qu.empty()) {
            //Step 8: Extracting the front most element from the queue.
            int currNode = qu.front();
            //Step 9: Once extracted the top element not removing that element out.
            qu.pop();

            //Step 10: Looping over the neighbours of the current Nodes.
            list<int> node = this->l[currNode];
            for(int neighbour: node) {
                //Step 11: If the neighbour is not visited then make the neighbour visited by pushing it in the queue and save the color of the neighbour (the neighbour color should be different from parent node).
                if(color[neighbour] == -1) {
                    qu.push(neighbour);
                    // visited[neighbour] = true;
                    color[neighbour] = !color[currNode]; //Here !0=1 and !1=0
                } else { //Step: If the neighbour is already visited then match if the color of the neighbour is same as the color of the currNode then return the false
                    if(color[neighbour] == color[currNode]) return false; //Because in this case we have no-bipartite existing.
                }
            }
        }
        
        //Step 12: If none of the above condition evaluates to false then it means a Bipartite exists therefore return a true value.
        return true;
    }
};

int main() {
    int v;
    cin>>v;
    //Undirected graph
    Graph graph(v);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(0,3); //This edge connection will make it a non-bipartite.

    cout<<graph.isBipartitie();

    return 0;
}