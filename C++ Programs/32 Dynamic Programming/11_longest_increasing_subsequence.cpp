#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

// T.C - O(n*m) where n = nums1.size() and m = nums2.size()
int longestCommonSubsequence(vector<int> nums1, vector<int> nums2) {
    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(nums1[i-1] == nums2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

/**
 * Time-Complexity - O(n^2)
 */
int longestIncreasingSubsequence(vector<int>& nums) {
    // Extracting the unique element from the nums array as we need increasing element to form increasing subsequence
    unordered_set<int> s(nums.begin(), nums.end());
    vector<int> numsSet(s.begin(), s.end()); // Converted set into vector

    // Once we have got the unique elements just sort the set.
    sort(numsSet.begin(), numsSet.end()); // O(log n) Ascending Order

    // Now just apply the Longest Common Sub-sequence logic over here because that will only be the Longest Increasing Subsequence
    return longestCommonSubsequence(nums, numsSet);
}

int main() {
    vector<int> nums = {50, 3, 10, 7, 40, 80};
    cout<<longestIncreasingSubsequence(nums);
    return 0;
}