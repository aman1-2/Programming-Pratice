#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}