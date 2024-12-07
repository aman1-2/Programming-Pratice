/*Given a balanced expression that can contain opening and closing parenthesis, check if it contains
any duplicate parenthesis or not.

Input: ((x+y) + z)
Outuput: true
Explanation: Duplicate () found in sub-expression (x+y)

Input: (x+y)
Output: false
Explanation: No duplicate () found

Input: ((x+y) +((z)))
Output: true
Explanation: Duplicate () found in sub-expression ((z))*/

#include<iostream>
#include<stack>
using namespace std;

bool isDuplicateParenthesis(string str) { //O(n)
    stack<char> st;
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        if(ch != ')') { //non-closing characters
            st.push(ch);
        } else {
            if(st.top() == '(') { //Duplicate condition
                return true;
            }
            while(st.top() != '('){
                st.pop();
            }
            st.pop();
        }
    }

    return false;
}

int main() {
    string str = "(a+b)";
    cout<<isDuplicateParenthesis(str);
    return 0;
}