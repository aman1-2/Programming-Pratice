#include<iostream>
#include<vector>
using namespace std;

int targetSumSubset(vector<int> nums, int target, int i) {
    // Counting the number of valid subset in here where we have subset sum as target = 7.
    if(target == 0) return 1; // Found a valid set.
    if(i == nums.size()) return 0; // No element left.
 
    int ele = nums[i];
    int include = 0;
    if(ele <= target) {
        // Include the element in the subset
        include = targetSumSubset(nums, target-nums[i], i+1);
    }
    int exclude = targetSumSubset(nums, target, i+1);

    return include + exclude;
}

bool targetSumSubsetTabulation(vector<int> nums, int target) {
    int n = nums.size();
    //Step-1: Storage creating and Step-2: Initialization of DP.
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<target+1; j++) {
            int val = nums[i-1];

            // Valid Condition
            if(val <= j) {
                dp[i][j] = max(val + dp[i-1][j-val], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return (dp[n][target] == target);
}

int main() {
    vector<int> nums = {4, 2, 7, 1, 3};
    int target = 25;

    cout<<targetSumSubsetTabulation(nums, target);
}