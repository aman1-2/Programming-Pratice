/**
 * Hard Problem
 * Statement - Find Min Cost to multiply all matrices. Cost is No. of Operations for Multiplication.
 * Example - arr[n] = {1,2,3,4,3}
 * 
 * Variation - Egg Dropping
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/**
 * Time-Complexity - O()
 */

// In the recursion function we will pass the parameter as vector then the start point of vector and end point of vector.
int mcmRecursion(vector<int>& arr, int i, int j) { // We are going to return the minimum cost of operation to multiply the matrcies.
    // Base Case : At any point of time our start in equal to end then we have just one matrix left and we can't mulitply no matrix therefore the cost of operation in that case would come out to be 0.
    if(i == j) {
        return 0;
    }

    int ans = INT_MAX;

    // We can have k number of ways to seperate the matrix vector. Where if the size of matrix is n then there are k = n-1 ways of partition.
    for(int k=i; k<j; k++) {
        // First Group -> (i, k)
        int cost1 = mcmRecursion(arr, i, k);

        // Second Group -> (k+1, j)
        int cost2 = mcmRecursion(arr, k+1, j);

        // This is the total cost for the current partition.
        int currPartitionCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currPartitionCost);
    }

    return ans;
}

/**
 * Time-Complexity - O()
 */

/* Since we have two variables i and j which are changing inside our function therefor a dp 
matrix for i and j will be formed. Where we are going to store all the possible answers for i and j.
Where the value of i can go from 1 to n-1 and similary j can go from 1 to n-1.

Here each cell will store the minimum cost of multiplication chain that goes from i to j.
*/
int mcmMemoization(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    // Base-Case : If we just have a single matrix then the multiplication for that single matrix will come out to be 0 number of operation.
    if(i == j)  return 0;

    // If already calculated for this multiplcation range. Use it.
    if(dp[i][j] != -1)  return dp[i][j];

    int ans = INT_MAX;

    // Totak k number of seperations which n-1 for n number of matrice size.
    for(int k=i; k<j; k++) {
        int cost1 = mcmMemoization(arr, i, k, dp);
        int cost2 = mcmMemoization(arr, k+1, j, dp);

        int currPartitonCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);

        ans = min(ans, currPartitonCost);
    }

    return (dp[i][j] = ans);
}

/**
 * Time-Complexity - O(n^3)
 */
/**
Inside Tabulation - First thing going to see the type of storage to use which variable will affect 
the storage and its the start and end value which we pass for our matrice size.

The value of the start and end can go from 1 to n-1.

Meaning -> At each of the cell we are going to store the min cost of operation two multiply two matrice.
 */
int mcmTabulation(vector<int>& arr) {
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    /* We are never going to use the first row where the matrix size is going to be 0 so no answer is going to be stored at that place.
    Initialization Step ->  Smallest problem will be when we have the single matrix. Which occurs when i=j.*/
    // for(int i=1; i<n; i++){ // We have started from 1 because i and j can never be 0.
    //     dp[i][i] = 0; // We are filling the places where i=j with 0 because there we have single matrix and multiplication operation on single matrix comes out to be 0.
    // }

    /* Here we don't have to fill our dp row-wise here we need to fill our dp diagonal wise because the first 1 length matrix exists in diagonal fashion for which we have 0 number of operation 
    In a similar fashion we will now be filling the matrix for length 2.*/
    for(int len=2; len<n; len++) {
        // For each of the lenth we can calculate the value of i. Where each of the diagonal are starting from i=1.
        for(int i=1; i<=n-len; i++) {
            // Now from row-number we can calculate the column number each time.
            int j = i + len - 1;

            dp[i][j] = INT_MAX; //Since we have initialized all the cells with 0 therefore not to have 0 at eact step as min therefore intialized with max value.

            // For this we need to decide if we are moving from i to j then where are we going to have the partition. So a new variable will be needed K.
            for(int k=i; k<j; k++) {
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];

                int currPartitonCost = cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]);

                dp[i][j] = min(dp[i][j], currPartitonCost);
            }
        }
    }

    return dp[1][n-1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3}; // If size is n then we have n-1 matrices for us From 1 to n-1.
    int n = arr.size();

    cout<<mcmRecursion(arr, 1 ,n-1)<<endl; // 30

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<mcmMemoization(arr, 1, n-1, dp)<<endl; // 30

    cout<<mcmTabulation(arr);

    return 0;
}