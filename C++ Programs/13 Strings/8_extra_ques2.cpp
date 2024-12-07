/*
LEETCODE - Problem Number 20.

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1.) Open brackets must be closed by the same type of brackets.
2.) Open brackets must be closed in the correct order.
3.) Every close bracket has a corresponding open bracket of the same type.
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
 

Constraints:
(.) 1 <= s.length <= 104
(.) s consists of parentheses only '()[]{}'.
*/

#include<iostream>
#include<vector>
using namespace std;

bool isValid(string s){
    //STEP-1 -> Checking the lenght of the string if its less than 2 then it cann't have both the opening and closing bracket.
    if(s.length() == 0 || s.length() == 1)  return false;

    vector<char>v;
    for(char ch:s){
        //If its a Opening bracket then push it inside the vector.
        if (ch == '(' || ch == '{' || ch == '[') {
            v.push_back(ch);
        } else{
            //Check if the vector is empty or not.
            if (v.empty()) {
                return false;
            }
            char top = v.back(); //Extracting the top most element
            //If the last element of vector and the current element of ch is opening and closing then remove that element from the vector.
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                v.pop_back();
            } else { //Otherwise a false
                return false;
            }
        }
    }
    return v.empty(); //At the end just check if the vector is empty or not it must not have any brackets left every bracket must have a closing bracket.
}

int main(){
    cout<<isValid("((");
    return 0;
}