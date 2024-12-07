#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(string str) { //O(n)
    stack<char> st; // will store the opening brackets
    for(int i=0; i<str.size(); i++) {

        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        } else {
            if(st.empty()) return false; //If stack is empty and we have a closing bracket.

            char top = st.top();
            if((str[i] == '}' && top == '{') ||
             (str[i] == ')' && top == '(') || 
             (str[i] == ']' && top == '[')) 
            {
                st.pop();
            } else{
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string str = "([{}]())";
    cout<<isValidParenthesis(str);
    return 0;
}