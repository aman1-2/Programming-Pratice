#include<iostream>
#include<vector>
using namespace std;

int ways(int n) {
    if(n == 0 || n == 1)    return 1;
    if(n == 2)  return 2;

    return (ways(n-1) + ways(n-2) + ways(n-3));
}

int memoWays(int n, vector<int>& dp) { // O(n)
    if(n == 0 || n == 1)    return 1;
    if(n == 2)  return 2;

    if(dp[n] != -1)     return dp[n];

    return dp[n] = (memoWays(n-1, dp) + memoWays(n-2, dp) + memoWays(n-3, dp));
}

int tablWays(int n) { // O(n)
    vector<int> dp(n+1, -1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main() {
    int n = 5; // 7
    // cout<<ways(n);

    // vector<int> dp(n+1, -1);
    // cout<<memoWays(n, dp);

    cout<<tablWays(n);
    
    return 0;
}