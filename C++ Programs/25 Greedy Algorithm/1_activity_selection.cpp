/*Selecting the maximun number of activity that a person can perform.*/

#include<iostream>
#include<vector>
using namespace std;

int maxActivity(vector<int> start, vector<int> end) {
    //STEP 1 -> Sorting it on some bases.
    int count = 1; //Selected the first activity as the first activity will always end first because sorted in that way.

    int endTime = end[0];

    //Making a comparison and increasing the activity count.
    for(int i=1; i<start.size(); i++) {
        if(start[i] >= endTime) { //Non-overlapping
            endTime = end[i];
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout<<maxActivity(start,end);

    return 0;
}