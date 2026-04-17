/**
 * For Two string return minimum number of operation to convert one string into another
 */
#include<iostream>
#include<vector>
using namespace std;

/**
 * Time-Complexity - O(n*m)
 */
int editDistance(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    // STEP-1: Create a Storage
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    // STEP-2: Initializing the dp : At each of the cell we will be storing the minimum number of operation taken to convert that str1 to str2.
    /* If any one of the string is empty the smallest problem for any string then to convert 
    it into that string we would either need to insert that number of character into our 
    string or remove that number of character from the string depending upon the stituation 
    that which string has become empty.*/

    /* i and j are going to be length of the strings respectively.
    Where if our str1 = "" and have some character in str2 = "abc" to make str1 = str2 we need 
    to attach same number of chracters in string 1 so the number of operation will come out 
    to be length of string 2.*/
    for(int j=0; j<m+1; j++) {
        dp[0][j] = j;
    }

    // Whereas if str1 = "abc" and str2 = "", then need to remove the characters from str1 
    // to makr equal to str2 and the same number of character that we have in str1 need to 
    // removed so number of operation will be length of the string 1.
    for(int i=0; i<n+1; i++) {
        dp[i][0] = i;
    }

    // STEP-3: Says to Solve the problem from smallest to the largest problem.
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            /* If last character of both the strings are equal then we need not to perform 
            any operation and move forward because they are already same.*/
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // No operation needed for this character but the here we will store the answer for the minimum operation for the rest of the string formed.
            } else {
                /* But if the character is not same then need to perform an 
                operation to make them same by perfoming any operation from insert, delete 
                and replace and will choose the minimum number of operation formed by them 
                overall.*/

                // One operation will always be formed to make it equal which will be either insert, delete or replace operation and
                // after performing any one operation we will look which operation gives the minimum number of operation overall to
                // make the strings equal.
                // insertion -> When a character is inserted the str1 size will have no change because a character is inserted but str2 size reduce because got a matched character.
                // deletion -> When a character is deleted the str1 size is reduced because it tried to match the characters of str2 with its rest of the string and str2 size remains same because no character matched.
                // replace -> When a character of str1 is replaced with the character of str2 both of the character become equal and we reduce the size of both of them.
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }

    return dp[n][m];
}

int main() {
    string str1 = "horse";
    string str2 = "ros";

    cout<<editDistance(str1, str2)<<endl; // 3

    return 0;
}