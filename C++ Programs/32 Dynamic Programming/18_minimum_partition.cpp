#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int getMinDiff(vector<int> &arr) {
    int n = arr.size();

    int totalSum = 0; 
    for(int ele: arr) {
        totalSum += ele;
    }

    int W = totalSum/2;

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            if(arr[i-1] <= j) {
                // Include - Exclude Choose
                dp[i][j] = max((arr[i-1] + dp[i-1][j-arr[i-1]]), dp[i-1][j]);
            } else {
                // Invalid Exclude case
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int grp1Sum = dp[n][W];
    int grp2Sum = totalSum - grp1Sum;

    return  abs(grp1Sum - grp2Sum);
}

int main() {
    vector<int> arr = {1, 6, 11, 5};

    cout<<getMinDiff(arr);

    return 0;
}