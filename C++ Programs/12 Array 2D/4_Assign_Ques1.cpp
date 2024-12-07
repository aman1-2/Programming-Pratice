/*
Question 1 : Print the number of all 7’s that are in the 2d array.
Example :
Input - int arr[ ][ ] = { {4,7,8}, {8,8,7} }; n = 2, m = 3
Output - 2
*/

#include<iostream>
#include<vector>
using namespace std;

int countNum(vector<vector<int>>nums, int search){
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums[i].size(); j++){
            if(nums[i][j] == search)    count++;
        }
    }

    return count;
}

int main(){
    vector<vector<int>> nums = { {4,7,8}, {8,8,7} };
    int res = countNum(nums,7);
    cout<<"The count of 7 in nums matrix is: "<<res;
    
    return 0;
}