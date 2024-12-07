#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> slidingWindowMax(vector<int> &vec, int k) {
    vector<int> res;
    //STEP 1: Is to create our max heap priority queue for the k elements.
    //We will store the values in priority queue as the vector value which will go in the queue and the index position in which that value is present.
    priority_queue<pair<int,int>> pq;
    //pq.top() -> sliding window we store (arr[i], index) index for checking if the element is part of the queue or not.
    for(int i=0; i<k; i++) { //1st window
        pq.push(make_pair(vec[i], i));
    }

    res.push_back(pq.top().first);

    //STEP 2: Keep on increasing the window size by 1.
    for(int i=k; i<vec.size(); i++) {
        //Firstly we need to remove the element.
        while(!pq.empty() && pq.top().second <= (i-k)) { //Outside window
            pq.pop();
        }
        pq.push(make_pair(vec[i], i));

        res.push_back(pq.top().first);
    }
    
    return res;
}

int main() {
    vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> res = slidingWindowMax(vec, k);
    for(int ele: res) {
        cout<<ele<<" ";
    }

    return 0;
}