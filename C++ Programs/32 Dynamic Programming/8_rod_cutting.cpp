/**
 * Rod Cutting Problem
 Cut Rod into pieces to get maxProfit from pieces. Possible pieces are always of len 1 to n.

 price[] = {1, 5, 8, 9, 10, 17, 17, 20}
 rodLength = 8
 length[] = {1, 2, 3, 4, 5, 6, 7, 8}
*/
#include<iostream>
#include<vector>
using namespace std;

int recursion(vector<int> price, vector<int> length, int rodLength, int idx) {
    if(rodLength == 0 || idx == price.size())   return 0;

    int currRodLength = length[idx];
    int currRodPrice = price[idx];

    if(currRodLength <= rodLength) { // A valid Condition that we can make choice for this rod-length.
        // Include version - And we stay at the same position becaue multiple cuts can be made.
        int ans1 = currRodPrice + recursion(price, length, rodLength-currRodLength, idx);

        // Exclude version
        int ans2 = recursion(price, length, rodLength, idx+1);

        return max(ans1, ans2);
    } else { // Not a valid condition Just exclude
        return recursion(price, length, rodLength, idx+1);
    }
}

/**
 * Time-Complexity - O(n*rodLength), Here is the length of the rods.
 */
int rodCuttingProblem(vector<int> length, vector<int>price, int rodLength) {
    int n = length.size();
    vector<vector<int>> dp(n+1, vector<int>(rodLength+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<rodLength+1; j++) {
            int currRodLength = length[i-1];
            int currRodPrice = price[i-1];

            if(currRodLength <= j) { // If its valid condition.
                // Max out of the include and exclude case
                dp[i][j] = max(currRodPrice + dp[i][j-currRodLength], dp[i-1][j]);
            } else { // Invalid situation
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][rodLength];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int rodLength = 8;
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};

    cout<<rodCuttingProblem(length, price, rodLength)<<endl;
    cout<<recursion(price, length, rodLength, 0)<<endl;

    return 0;
}