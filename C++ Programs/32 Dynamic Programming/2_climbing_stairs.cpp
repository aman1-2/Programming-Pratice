#include<iostream>
#include<vector>
using namespace std;

// 1. Made a Recursion Function 
// Recurrence Relation -> ways(n) = ways(n-1) + ways(n-2)
int ways(int n) { // Time- Complexity for this problem is  — O(2^n)
    /* If we don't have to go anywhere in that case we will stand at 
    the same and standing at the same place is to a solution in our 
    case. */
    if(n == 0 || n == 1)  return 1;

    // if(n == 2 || n == 3)    return n;
    
    return (ways(n-1) + ways(n-2));
}

// Memoization
int memoWays(int n, vector<int> &dp) { // Time-Complexity - O(n)
    if(n == 0 || n == 1)    return 1;

    if(dp[n] != -1) return dp[n];

    return dp[n] = memoWays(n-1, dp) + memoWays(n-2, dp);
}

int tabulWays(int n) { // Time-Complexity - O(n)
    vector<int> dp(n+1, -1);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n = 6;

    // cout<<ways(n); // 8

    // vector<int> dp(n+1, -1);

    // cout<<memoWays(n, dp); // 8

    cout<<tabulWays(n); // 8

    return 0;
}