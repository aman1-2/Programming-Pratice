/*
Question 3 : We are given a string S, we need to find the count of all contiguous
substrings starting and ending with the same character. [Leetcode Premium Qs]

Sample Input 1 : S = "abcab"
Sample Output 1 : 7

There are 15 substrings of "abcab" : a, ab, abc, abca, abcab, b, bc, bca, bcab, c, ca, cab, a,
ab, b

Out of the above substrings, there are 7 substrings : a, abca, b, bcab, c, a and b. So, only
7 contiguous substrings start and end with the same character.

Sample Input 2 : S = "aba"
Sample Output 2 : 4

The substrings are a, b, a and aba
*/

#include<iostream>
using namespace std;

int allContiguousSubstring(string str, int stIdx, int endIdx, int size){
    if(size == 1 || size == 0)   return size;

    int res = allContiguousSubstring(str, stIdx + 1, endIdx, size - 1) + allContiguousSubstring(str, stIdx, endIdx - 1, size - 1) - allContiguousSubstring(str, stIdx + 1, endIdx - 1, size - 2);

    if(str[stIdx] == str[endIdx])   res++;

    return res;
}

int main(){
    cout<<allContiguousSubstring("abcab", 0, 5, 5)<<"\n";
    return 0;
}