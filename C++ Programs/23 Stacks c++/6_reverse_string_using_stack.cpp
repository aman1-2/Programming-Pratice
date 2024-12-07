#include<iostream>
#include<stack>
using namespace std;

string reverseStr(string str) { //O(n) -> Time and space
    stack<char> s;
    for(char ele:str) {
        s.push(ele);
    }

    string rev_string = "";
    
    while(!s.empty()) {
        rev_string = rev_string + s.top();
        s.pop();
    }

    return rev_string;
}

int main() {
    string str = "Aman";
    cout<<reverseStr(str);
    return 0;
}