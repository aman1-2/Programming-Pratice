#include<iostream>
#include<vector>
using namespace std;

/**
 * Time-Complexity - O(2^n+m)
 */
int longestCommonSubsequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    // Base-Case : This means we have either travelled any one string completely or both of them.
    if(n==0 || m==0)    return 0;
    
    if(str1[n-1] == str2[m-1]) {
        // We got a matching character therefore both the characters will be removed.
        return (1 + longestCommonSubsequence(str1.substr(0, n-1), str2.substr(0, m-1)));
    } else {
        // remove the unmatch character from string str1 and then compare it with the rest of the string.
        int ans1 = longestCommonSubsequence(str1.substr(0, n-1), str2);

        // remove the unmatch character from the string str2 and then compare it with the rest of the string.
        int ans2 = longestCommonSubsequence(str1, str2.substr(0, m-1));

        return max(ans1, ans2); // 4
    }
}

/**
 * Time-Complexity - O(n*m)
 */
int lcsMemoization(string str1, string str2, vector<vector<int>>& dp) {
    int n = str1.size();
    int m = str2.size();

    if(n == 0 || m == 0)    return 0;

    if(dp[n][m] != -1)  return dp[n][m];

    if(str1[n-1] == str2[m-1]) {
        // Character same found one count of subsequence character
        dp[n][m] = 1 + lcsMemoization(str1.substr(0, n-1), str2.substr(0, m-1), dp);
    } else {
        // If character is mis-match
        // Find the max by once removing the unmatch character of str1 then str2 then compare it with the rest of the string.
        dp[n][m] = max(
            lcsMemoization(str1.substr(0, n-1), str2, dp), 
            lcsMemoization(str1, str2.substr(0, m-1), dp)
        );
    }

    return dp[n][m];
}

/**
 * Time-Complexity - O(n*m)
 */
int lcsTabulation(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    // STEP-1: Chosing the storage
    // STEP-2: Initializin the DP ususally the base-case value filling where if any of the string goes empty the answer will be 0.
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // STEP-3: Solve the problem from smallest to largest
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";

    // cout<<longestCommonSubsequence(str1, str2);

    // vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, -1));
    // cout<<lcsMemoization(str1, str2, dp);

    cout<<lcsTabulation(str1, str2)<<endl;

    return 0;
}