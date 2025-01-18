#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph {
    int vertices;
    vector<list<int>> l;

    bool dfsPathHelper(int srcVertex, int &destVertex, vector<bool> &visited) {
        //Step 1: Checking if the source vertex is equal to the destination vertex then return true there only.
        if(srcVertex == destVertex) return true;
        //Step 2: If the source and destination are not equal then mark the source visited in the vector.
        visited[srcVertex] = true;
        //Step 3: Find the hedd of the linked list for the source position.
        list<int> neighbours = l[srcVertex];
        for(int neighbour:neighbours) { //Traversing the neighbour
            if(!visited[neighbour]) { //If the neighbour is not yet visited then 
                if(dfsPathHelper(neighbour, destVertex, visited)){ //Just make a recursive call with the unvisited neighbour to mark it visited and see if its neighbour has a path.
                    return true; //If this recursive call somehow give us value true then we too need to return true in that case.
                }
            } //Else if neighbours are visited doesn't need to do anything.
        }

        return false; //At the end will return false value showing that there is no path that exists between our source and destination.
    }

    bool bfsPathHepler(int srcVertex, int destVertex) { //For bfs implementation we have passed just the source and destination vertex.
        //Step 1: Created a Queue to store the index position of the elements.
        queue<int> qu;
        //Step 2: Created a vector for tracking which all nodes we have visited.
        vector<bool> visited(this->vertices, false);
        qu.push(srcVertex); //Pushing the first element in the queue with the index position as 0.
        visited[srcVertex] = true; //Then we need to mark that position visited in the queue.

        while(!qu.empty()) { //Untill whole queue is not empty we need to run this loop.
            int currVertex = qu.front(); //Extracting the top element or say front element from queue.
            if(currVertex == destVertex)    return true; //If both the front element of the queue and destination vertex are equal then it means a path exists.
            qu.pop();
            //Step 3: Otherwise make a traversal to its neighbour nodes.
            list<int> neighbours = l[currVertex];
            for(int neighbour:neighbours) {
                if(!visited[neighbour]) { //If any of the neighbour is not visited.
                    qu.push(neighbour); //Then add that node in the queue.
                    visited[neighbour] = true; //And mark it visited in the vector.
                }
            } 
        }
        return false; //Otherwise at the end return a false value showing that the path doesn't exits.
    }
public:
    Graph(int v) {
        this->vertices = v;
        l.resize(v);
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

    bool hasPath(int srcVertex, int destVertex) { //Time Complexity as O(v+ e) as internally it using the dfs traversal logic only.
        vector<bool> visited(this->vertices, false);
        return bfsPathHepler(srcVertex, destVertex);
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
    // graph.print();
    //dfs traversing
    cout<<graph.hasPath(0, 5)<<endl;
    cout<<graph.hasPath(6, 7)<<endl;


    return 0;
}