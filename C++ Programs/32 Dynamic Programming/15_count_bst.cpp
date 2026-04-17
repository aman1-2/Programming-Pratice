#include<iostream>
#include<vector>
using namespace std;

/* Direct variation of catlan number where,
if we have 0 node then by adding none node we are having 1 possibility of making it
if we have 1 node then by adding that single node we are making 1 possibility of making that node. 
if we have 2 node then we have 2 ways to arrange these nodes. */ 
int countBST(int n) { // 1 2 3 // O(n^2)
    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<n+1; i++) {
        for(int j=0; j<i; j++) {
            dp[i] += dp[j]*dp[i-j-1];
        }
    }

    return dp[n];
}

int main() {
    for(int i=0; i<5; i++) {
        cout<<countBST(i)<<endl;
    }

    return 0;
}