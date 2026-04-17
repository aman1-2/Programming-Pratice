#include<iostream>
#include<vector>
using namespace std;

/**
 * Time-Complexity - O(2^n)
 */
int knapsack0_1_recursion(vector<int> val, vector<int> wt, int W, int n) {
    if(W == 0 || n == 0)    return 0;

    //STEP 1: To check if our item is a valid item or not.
    int itemWt = wt[n-1];
    int itemVal = val[n-1];
    if(itemWt <= W) { // If the itemWt is less than or equal to knapsack capacity then only we have two choices with us.
        // Valid wt condition.
        // First-Choice we need to include
        int ans1 = knapsack0_1_recursion(val, wt, W - itemWt, n-1) + itemVal;

        // Second-Choice we need to exclude
        int ans2 = knapsack0_1_recursion(val, wt, W, n-1);

        return max(ans1, ans2);
    } else { // Invalid wt condition.
        // Then here we have just one choice of excluding the item.
        // Here we just have one choice to make therefore whatever answer we get in this situation we return that answer.
        return knapsack0_1_recursion(val, wt, W, n-1);
    }
}

/**
 * Time-Complexity - O(n*w)
 */
int knapsack0_1_memoization(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>>& dp) {
    if(n == 0 || W == 0)    return 0;

    if(dp[n][W] != -1)    return dp[n][W];

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W) { // Valid move
        // Include
        int ans1 = knapsack0_1_memoization(val, wt, W-itemWt, n-1, dp) + itemVal;

        // Exclude
        int ans2 = knapsack0_1_memoization(val, wt, W, n-1, dp);

        dp[n][W] = max(ans1, ans2);
    } else {
        // Exclude
        dp[n][W] = knapsack0_1_memoization(val, wt, W, n-1, dp);
    }

    return dp[n][W];
}

/**
 * Time-Complexity - O(n*w)
 */
int knapsack0_1_tabulation(vector<int> val, vector<int> wt, int W, int n) {
    // Storage Data-structure choicing step with right parameters.
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Initialization step.
    // for(int j=0; j<W; j++)  dp[0][j] = 0;
    // for(int i=0; i<n; i++)  dp[i][0] = 0;
    /* We can either write this step or have our complete matrix be created 
    with 0 values which will automatically fill the first row and first 
    column with the 0 values in it.*/

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            int itemWt = wt[i-1]; // This i-1 has become with the same logic which we took for n-1 in the memoization.
            int itemVal = val[i-1];

            // Valid condition 
            if(itemWt <= j) {
                dp[i][j] = max(itemVal +dp[i-1][j-itemWt], dp[i-1][j]); // MAX out of include and exclude 
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

    // cout<<knapsack0_1_recursion(val, wt, W, n);

    // vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    // cout<<knapsack0_1_memoization(val, wt, W, n, dp);

    cout<<knapsack0_1_tabulation(val, wt, W, n);

    return 0;
}