/**
 * Find the element that appears more than n/3 times in the collection
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void majorElement(vector<int> &vec) { //T.C. - O(n)
    //STEP 1: Map creation for storing the (element and frequency) in the map.
    unordered_map<int, int> um;
    int n = vec.size(), countThreshold = n/3;

    //STEP 2: Traversing on each element of the vector and storing that element and its frequency in the unordered map.
    for(int i=0; i<n; i++) {
        //If the element is encountered entering that element and storing its frequency as 1.
        // if(!um.count(vec[i]))   um[vec[i]] = 1;
        // else    um[vec[i]]++; //If its an already stored element just increase its frequency count. 

        um[vec[i]]++; //We can too directly used use this statement
        
        //STEP 3: Making a check that if the current elements frequency is more than count make a comparison with
        //current max freq element and update accordingly.
        if(um[vec[i]] > countThreshold) {
            cout<<vec[i]<<" ";
        }
    }

    return;
}

int main() {
    vector<int> vec = {1,3,2,5,1,3,1,5,1};
    // vector<int> vec = {1,2};
    majorElement(vec);
    return 0;
}