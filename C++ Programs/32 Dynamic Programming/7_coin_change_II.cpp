/**
 * Leetcode - 518 Coin Change II [Medium]

 518. Coin Change II
You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that 
amount of money cannot be made up by any combination of the coins, 
return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10]
Output: 1
 
Constraints:
-> 1 <= coins.length <= 300
-> 1 <= coins[i] <= 5000
-> All the values of coins are unique.
-> 0 <= amount <= 5000
*/





// class Solution {
// public:
//     /**
//     * Time-Complexity - O(2^n)
//     */
//     int helperRecursion(vector<int> coins, int amount, int idx) {
//         if(amount == 0) return 1;
//         if(idx == coins.size())     return 0;

//         int coin = coins[idx];

//         int include = 0;
//         if(coin <= amount) {
//             // Include the coin and stay here - Here we will be at this position itself because we need to find out number of times i.e. combinatio not the permutation where for us order matters.
//             include += helperRecursion(coins, amount-coin, idx);
//         }
//         // Exclude the coin
//         int exclude = helperRecursion(coins, amount, idx+1);

//         return include + exclude;
//     }

//     int dp[301][5001];

//     int helperMemoization(vector<int> coins, int amount, int idx) {
//         if(amount == 0)     return 1;
//         if(idx == coins.size())     return 0;

//         if(dp[idx][amount] != -1)   return dp[idx][amount];

//         int coin = coins[idx];
//         int include = 0;
//         // Checking the valid condition if the coin is valid or not.
//         if(coin <= amount) {
//             // Include the coin and stay at the same position itself.
//             include = helperMemoization(coins, amount-coin, idx);
//         }
//         // Exclude the coin
//         int exclude = helperMemoization(coins, amount, idx+1);

//         return dp[idx][amount] = include + exclude;
//     }

//     int helperTabulation(vector<int> coins, int amount) {
//         // STEP-1: Storage Choice
//         // STEP-2: Initializing the DP matrix with value and these intialization are done on the basis of base case itself.
//         int n = coins.size();
//         vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

//         // Base Case
//         for(int i = 0; i <= n; i++) {
//             dp[i][0] = 1;
//         }

//         // STEP-3: Solving part while going to each position of the dp matrix.
//         for(int i=1; i<n+1; i++) {
//             for(int j=1; j<amount+1; j++) {
                
//                 // Check Condition if valid or not
//                 int coin = coins[i-1];
//                 if(coin <= j) {
//                     // Include the coin 
//                     dp[i][j] = dp[i][j-coin] + dp[i-1][j]; // Max out of the inclusion and exclusion condition check.
//                 } else {
//                     // Exclude the coin case
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }

//         return dp[n][amount];
//     }

//     int change(int amount, vector<int>& coins) {
//         // return helperRecursion(coins, amount, 0);

//         // memset(dp, -1, sizeof(dp));
//         // return helperMemoization(coins, amount, 0);

//         return helperTabulation(coins, amount);
//     }
// };