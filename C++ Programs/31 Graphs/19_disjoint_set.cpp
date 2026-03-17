#include<iostream>
#include<vector>
using namespace std;

// Time-Complexity -> Very Optimized data structure has time-complexity of O(alpha) which is almost O(1) with path compression
class DisjointSet {
    int elements;
    vector<int> parent;
    vector<int> rank;

public:

    DisjointSet(int ele) {
        this->elements = ele;
        parent.resize(this->elements);
        rank.resize(this->elements, 0);

        for(int i=0; i<this->elements; i++) {
            parent[i] = i;
        }
    }

    // T.C -> O(1) when used path compression
    int find(int ele) { 
        if(parent[ele] == ele)  return ele;
        return parent[ele] = find(parent[ele]); // path compression - When we find the parent of element we keep of assigning the value of element.
    }

    // T.C -> O(1)
    void unionByRank(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);

        if(rank[parentA] == rank[parentB]) {
            parent[parentB] = parentA;
            rank[parentA]++;
        } else if(rank[parentA] > rank[parentB]) {
            parent[parentB] = parentA;
        } else {
            parent[parentA] = parentB;
        }
    }

    void getInfo() {
        cout<<"Parent of elements:-"<<endl;
        for(int i=0; i<this->elements; i++) {
            cout<<i<<"->"<<parent[i]<<endl;
        }
        cout<<"Rank of elements:-"<<endl;
        for(int i=0; i<this->elements; i++) {
            cout<<i<<"->"<<rank[i]<<endl;
        }
    }
};

int main() {
    DisjointSet dj(6);

    dj.unionByRank(0, 2);
    cout<<dj.find(2)<<endl;
    dj.unionByRank(1, 3);
    cout<<dj.find(3)<<endl;
    dj.unionByRank(2, 5);
    dj.unionByRank(0, 3);
    cout<<dj.find(2)<<endl;
    dj.unionByRank(0, 4);
    cout<<dj.find(3)<<endl;

    dj.getInfo();
    return 0;
}