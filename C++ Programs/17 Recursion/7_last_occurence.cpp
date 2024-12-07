/*
WAP to create a function which resurcively find the last occurence of the element in the vector.
*/

#include<iostream>
#include<vector>
using namespace std;

int lastOccurence(vector<int> vec, int target, int i){
    if(i == 0)  return -1;

    if(vec[i] == target)    return i;

    return lastOccurence(vec, target, i-1);
}

int main(){
    vector<int> vec = {1,2,3,3,3,4};
    cout<<lastOccurence(vec, 2, 6);
    return 0;
}