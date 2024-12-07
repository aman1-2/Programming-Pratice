/*
Question 2 : For a given integer array of size N. You have to find all the occurrences
(indices) of a given element (Key) and print them.
Use a recursive function to solve this problem.

Sample Input : arr[ ] = {3, 2, 4, 5, 6, 2, 7, 2, 2}, key = 2
Sample Output : 1 5 7 8
*/

#include<iostream>
#include<vector>
using namespace std;

void allIndices(vector<int> v, int target, int idx){
    if(idx == v.size()) return;
    if(v[idx] == target)    cout<<idx<<" ";
    allIndices(v, target, ++idx);
}

int main(){
    vector<int> v = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    allIndices(v, 2, 0);

    return 0;
}