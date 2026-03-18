#include<iostream>
#include<vector>
using namespace std;

int fibonaaci(int n) { // Simple Recurssion - Time-Complexity : O(2^n)
    if(n == 0 || n == 1)    return n;
    return fibonaaci(n-1) + fibonaaci(n-2);
}

int fibonaaciDP(int n, vector<int> &dp) { // Time-Complexity : O(n)
    if(n == 0 || n == 1)    return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibonaaciDP(n-1, dp) + fibonaaciDP(n-2,dp); // Storing the answer.
}

int fibonacciTabulation(int n) {
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n = 6;
    vector<int> dp(n+1, -1);

    cout<<fibonaaci(n)<<endl;
    cout<<fibonaaciDP(n, dp)<<endl;
    cout<<fibonacciTabulation(n)<<endl;
    return 0;
}