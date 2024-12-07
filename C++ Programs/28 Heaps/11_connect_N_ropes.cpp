#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectNRopes(vector<int> ropes) {
    //STEP 1: Is to build a Priority Queue from the given length of ropes. We need to build the Queue here itself by passing the vector values as doing it one by one will give the time complexity of O(n log n).
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end()); //And this will build the min heap with O(n) time complexity only.

    int cost = 0; //This is the answer variable which will hold the min cost value.

    //STEP 2: Is we need to run a loop until the size of our Priority Queue is 1 Because till the time we have 2 elements in the queue we can find the min 1 and min 2 value.
    while(pq.size() > 1) {
        //STEP 3: Extracting the min1 and min2 value fromt the Queue.
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        //STEP 4: Updating the connecting cost of the rope.
        cost += min1 + min2;

        //STEP 5: Adding the new min1+min2 value back in the queue.
        pq.push(min1 + min2);
    }

    return cost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};
    cout<<"Min cost = "<<connectNRopes(ropes);
    
    return 0;
}