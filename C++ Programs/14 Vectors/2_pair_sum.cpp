/*
WAP where you are given a target sum and you have to find a pair whose sum is equal to target sum??
And the array provided will be sorted?
inp[] = {2,7,11,15}  target -> 9
output (0,1)

LEETCODE -> 167 PROBLEM NUMBER*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> bruteForcePairSum(vector<int> &v, int target) { //Time Complexity - O(n^2)
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(v[i] + v[j] == target){
                return {i, j};
            }
        }
    }

    return {-1,-1};
}

vector<int> optimizePairSum(vector<int> &v, int target) { //Time Complexity - O(n)
    int start_ptr = 0, end_ptr = v.size()-1;

    while(start_ptr < end_ptr){
        if(v[start_ptr] + v[end_ptr] == target){
            return {start_ptr, end_ptr};
        } else if(v[start_ptr] + v[end_ptr] > target){
            end_ptr--;
        } else{
            start_ptr++;
        }
    }

    return {-1,-1};
}

int main(){
    vector<int> v = {2,7,11,15};
    int target = 22;
    vector<int> out = optimizePairSum(v, target);
    for(int ele : out){
        cout<<ele<<" ";
    }
    return 0;
}