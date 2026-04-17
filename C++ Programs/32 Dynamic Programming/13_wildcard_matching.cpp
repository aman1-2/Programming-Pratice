#include<iostream>
#include<vector>
using namespace std;

/**
 * Time-Complexity : O(n*m)
 */
bool wildCardMatching(string& text, string& pattern) {
    int n = text.size();
    int m = pattern.size();

    // STEP-1: Create the Storage
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    // STEP-2: Initialization of the DP : At each cell of the DP we will be storing whether 
    // it is possible to convert pattern j into string i or not.
    // The value of dp[0][0] is going to true as empty pattern can be converted into empty string.
    dp[0][0] = true;

    for(int j=1; j<m+1; j++) { // When our string is empty and we have some character present in the pattern.
        if(pattern[j-1] == '*') { // If pattern has asterik as its last character
            dp[0][j] = dp[0][j-1]; // Then we will store the answer if rest of the characters are to '*' then true and if any other character then false.
        } else {
            dp[0][j] = false; // If any other character or Question mark then its false because in that case pattern can't be formed an empty string as ? -> is replaced by any single character not emptiness.
        }
    }
    // for(int i=1; i<n+1; i++) { // When our pattern is empty and some characters are present in the string.
    //     dp[i][0] = false;
    // } Instead of this we can intialize our complete DP with false value.


    // STEP-3: Solving from the smaller to larger problem
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            // First-Case : When we have the characters same inside the pattern and character 
            // or if the pattern has ? then to we can match it with a single character of string
            if(text[i-1] == pattern[j-1] || pattern[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1]; // Current character matches or made matched check for the rest of the string.
            } else if(pattern[j-1] == '*') { // Here we have two logics
                /* First : When we match the '*' with a character and reduce the string size but asterik can be used for other character to match therefore pattern size is remaind same.
                Second : When we match the '*' with empty character
                Now we will perform both the operation which so ever will give us true will be considered*/
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]); // In first the string got reduced character matched with '*' (i-1), second one '*' matched with empty pattern reduced (j-1).
            } else { // If other then asterik then false value.
                dp[0][j]= false;
            } 
        }
    }

    return dp[n][m];
}

int main() {
    string text = "aa", pattern = "a";

    cout<<wildCardMatching(text, pattern);

    return 0;
}