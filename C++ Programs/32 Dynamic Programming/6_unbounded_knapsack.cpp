#include<iostream>
#include<vector>
using namespace std;

/**
 * Time-Complexity :- O(3^n)
 */
int unboundedKnapsackRecursion(vector<int> val, vector<int> wt, int W, int n) {
    if(n == 0 || W == 0)    return 0;

    int itemWt = wt[n-1];
    int itemVal = val[n-1];
    
    // Condition check if valid item.
    if(itemWt <= W) {
        // Include and stay here
        int ans1 = itemVal + unboundedKnapsackRecursion(val, wt, W-itemWt, n);

        // // Include and move forward
        // int ans2 = itemVal + unboundedKnapsackRecursion(val, wt, W-itemWt, n-1);

        //Exclude this item
        int ans2 = unboundedKnapsackRecursion(val, wt, W, n-1);

        return max(ans1, ans2);
    } else {
        return unboundedKnapsackRecursion(val, wt, W, n-1);
    }
}

/**
 * Time-Complexity :- O(n*W)
 */
int unboundedKnapsackMemoization(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>>& dp) {
    if(n == 0 || W == 0)    return 0;

    if(dp[n-1][W] != -1)    return dp[n-1][W];

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W) {
        int ans1 = itemVal + unboundedKnapsackRecursion(val, wt, W-itemWt, n);

        int ans2 = unboundedKnapsackRecursion(val, wt, W, n-1);

        dp[n-1][W] = max(ans1, ans2);
    } else {
        dp[n-1][W] = unboundedKnapsackRecursion(val, wt, W, n-1);
    }

    return dp[n-1][W];
}

/**
 * Time-Complexity :- O(n*W)
 */
int unboundedKnapsackTabulation(vector<int> val, vector<int> wt, int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j) {
                dp[i][j] = max(itemVal + dp[i][j-itemWt], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;

    // cout<<unboundedKnapsackRecursion(val, wt, W, n)<<endl;

    // vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    // cout<<unboundedKnapsackMemoization(val, wt, W, n, dp)<<endl;

    cout<<unboundedKnapsackTabulation(val, wt, W, n);

    return 0;
}