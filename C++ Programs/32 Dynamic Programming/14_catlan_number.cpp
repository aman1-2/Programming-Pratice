#include<iostream>
#include<vector>
using namespace std;

/**
 * Time-Complexity - O(4^n)
 */
int catlanRecursion(int n) { // Similar Fibonaci number
    // Base-Case : The catlan number for which we know our answer.
    if(n == 0 || n == 1)    return 1;

    // Self-work :
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += catlanRecursion(i) * catlanRecursion(n-i-1);
    }

    return ans;
}

/**
 * Time-Complexity - O(n^2) // Becaue in each call we are running a loop of n.
 */
int catlanMemo(int n, vector<int>& dp) { 
    if(n == 0 || n == 1)    return 1;

    if(dp[n] != -1)     return dp[n];

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += catlanMemo(i, dp) * catlanMemo(n-i-1, dp);
    }

    return (dp[n] = ans);
}

/**
 * Time-Complexity - O(n^2) Because in each section we are running a loop of n to calculate catlan.
 */
int catlanTabulation(int n) { // 1 1 2 5 14 42
    vector<int> dp(n+1, 0);

    dp[0] = dp[1] = 1;

    // At each of the cell we are trying to store the ith catalan value.
    for(int i=2; i<n+1; i++) {
        for(int j=0; j<i; j++) {
            dp[i] += dp[j]*dp[i-j-1];
        } 
    }

    return dp[n];
}

int main() {
    for(int i=0; i<5; i++) {
        cout<<catlanRecursion(i)<<endl;
    }

    cout<<endl;

    for(int i=0; i<5; i++) {
        vector<int> dp(i+1, -1);
        cout<<catlanMemo(i, dp)<<endl;
    }

    cout<<endl;

    for(int i=0; i<5; i++) {
        cout<<catlanTabulation(i)<<endl;
    }

    return 0;
}