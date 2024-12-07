#include<iostream>
#include<queue>
using namespace std;

struct ComparePair { //This is too a operator overloading only
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second; //Right now it is creating a max heap but lets say we change the sign then it will start creating a min heap.
    }
};

int main() {
    //By default if we try to create a priority queue with the help of pairs then it will form a max heap only.
    //And this max heap of pairs will be created on the basis of the first property of pair.
    // priority_queue<pair<string, int>> pq;
    // //Here a max heap of string property by default will be created.
    // pq.push(make_pair("aman", 65));
    // pq.push(make_pair("aditya", 95));
    // pq.push(make_pair("anjali", 85));

    // while(!pq.empty()) {
    //     cout<<pq.top().first<<", "<<pq.top().second<<endl;
    //     pq.pop();
    // }

    /**
     * But lets say we need to make a max heap but on the basis of second property of the pair then how to define that logic.
     */

    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;
    pq.push(make_pair("aman", 65));
    pq.push(make_pair("aditya", 95));
    pq.push(make_pair("anjali", 85));

    while(!pq.empty()) {
        cout<<pq.top().first<<", "<<pq.top().second<<endl;
        pq.pop();
    }

    return 0;
}