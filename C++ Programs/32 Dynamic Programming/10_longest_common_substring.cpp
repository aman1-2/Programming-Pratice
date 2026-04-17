#include<iostream>
#include<vector>
using namespace std;

/**
 * Time-Complexity - O(n*m)
*/
int lcsTabulation(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    // STEP-1: Storage chose
    // STEP-2: Initialization of the DP - and this initialization will be based on the recursion base-case
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0;

    // STEP-3: Solve the problem from the smaller to larger problem
    // Here i and j represents the length of the string 
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            // If its a match character then it will be the part of the sub-string
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            } else { // If its not a matching character then just skip this move
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

/**
 * Time-Complexity - O(3^(n+m))
 */
int lcsRecursion(string str1, string str2, int count) {
    int n = str1.size();
    int m = str2.size();
     
    if(n == 0 || m == 0)    return count;

    if(str1[n-1] == str2[m-1]) { // If characters match
        count = lcsRecursion(str1.substr(0, n-1), str2.substr(0, m-1), count+1);
    }

    int c1 = lcsRecursion(str1.substr(0, n-1), str2, 0);
    int c2 = lcsRecursion(str1, str2.substr(0, m-1), 0);

    return max(count, max(c1, c2));
}

int main() {
    string str1 = "abcde";
    string str2 = "abgce";

    int count = 0;
    cout<<lcsRecursion(str1, str2, count)<<endl;

    cout<<lcsTabulation(str1, str2);

    return 0;
}