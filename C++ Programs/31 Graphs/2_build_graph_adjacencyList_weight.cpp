#include<iostream>
#include<list>
using namespace std;

class Graph { //Graph is collection of vertices and edges(which is the neighbours collection in this case).
    int vertices;
    list<pair<int, int>>* l; //Dynamic array
public:
    Graph(int v) {
        this->vertices = v;
        l = new list<pair<int, int>> [this->vertices]; //Given the size.
    }

    void addEdge(int vertex1, int vertex2, int weight) {
        //Created an Undirected and Weighted graph
        l[vertex1].push_back(make_pair(vertex2, weight)); //In the neighbour of vertex1 stored the vertex2 with the weight associated with it.
        l[vertex2].push_back(make_pair(vertex1, weight)); //In the neighbour of vertex2 stored the vertex1 with the weight associated with it
        return;
    }

    void print() {
        for(int i=0; i<this->vertices; i++) {
            list<pair<int, int>> neighbour = l[i];
            cout<<i<<"->[";
            for(pair<int, int> vertex: neighbour) {
                cout<<"("<<vertex.first<<", "<<vertex.second<<"), ";
            }
            cout<<"]"<<endl;
        }
    }
};

int main() {
    int vertices;
    cin>>vertices;

    Graph graph(vertices);
    //Adding edges
    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 2);
    //Printing graph
    graph.print();

    return 0;
}