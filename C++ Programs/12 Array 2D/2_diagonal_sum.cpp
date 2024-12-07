#include<iostream>
#include<vector>
using namespace std;

int diagonalSum(vector<vector<int>> &nums){
    int primary_dig_sum = 0, secondary_dig_sum = 0;

    for(int i=0; i<nums.size(); i++){
        primary_dig_sum += nums[i][i];
        
        if(i != nums.size()-i-1)
            secondary_dig_sum += nums[i][nums.size()-i-1];
    }

    return (primary_dig_sum + secondary_dig_sum);
}

int main(){
    vector<vector<int>>nums1 = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    cout<<diagonalSum(nums1)<<endl;

    vector<vector<int>>nums2 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout<<diagonalSum(nums2);

    return 0;
}