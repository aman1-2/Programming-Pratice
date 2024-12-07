/*
Question 2 : Keypad Combinations

Given a string containing digits from 2-9 inclusive, print all possible letter combinations that 
the number could represent. You can print the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 
does not map to any letters.

Sample Input 1 : digits = "23"
Sample Output 1 : "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"

Sample Input 2 : digits = "2"
Sample Output 2 : "a", "b", "c"

Sample Input 3 : digits = ""
Sample Output 3 : ””
*/

#include<iostream>
#include<vector>
using namespace std;

vector<string> v = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> ans;

void keypadCombination(string digits, int idx, string output) {
    if(idx >= digits.length()) {
        cout<< output<<" ";
        return;
    }

    for(int i=0; i<v[digits[idx] - '0'].length(); i++){
        output += v[digits[idx] - '0'][i];
        keypadCombination(digits, idx+1, output);
        output.pop_back();
    }

}

int main(){
    string digits = "34";
    if(digits == ""){
        cout<<"";
        return 0;
    }
    keypadCombination(digits, 0, "");

    return 0;
}