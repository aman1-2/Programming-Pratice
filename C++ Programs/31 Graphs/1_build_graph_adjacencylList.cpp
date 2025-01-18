#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {//The graph class internally stores the total number of vertices and edges in it.
    int vertices; //Number of vertices
    list<int>* l; //Dynamic array of list<int> type which we hold the heads of each vertices linked list.
    //Basically in the list we will store the neighbours of the vertex through which we will get our edges.
public:
    Graph(int v) {
        this->vertices = v;
        l = new list<int> [v]; //Providing the size our dynamic array.
    }

    //This function will hepl us to add a new edge in our Graph. Basically we will add each individual edges in it.
    void addEdge(int vertex1, int vertex2) { //For adding a edge we should get two vertex to show between which vertex an edge should come up.
        //We are creating an undirected and unweighted graph.
        l[vertex1].push_back(vertex2); //Therefore in the list of vertex1 we added the vertex2 as its neighbour.
        l[vertex2].push_back(vertex1); //And same in the list of vertex2 we added the vertex1 as its neighbour.
        return;
    }

    void print() { //This prints that which vertex has which all neighbours associated with them.
        //So we will loop through our dynamic array once and then at each index position of the dynamic array we will loop again on the list to see all the neighbour values of that particualr vertex
        for(int i=0; i<this->vertices; i++){
            list<int> neighbours = l[i];
            cout<<i<<"->";
            for(int vertex: neighbours) {
                cout<<vertex<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int vertices;
    cin>>vertices;

    Graph graph(vertices);
    //Adding the edges in our graph.
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    //Printing all the neighbours value for our graph.
    graph.print();

    return 0;
}