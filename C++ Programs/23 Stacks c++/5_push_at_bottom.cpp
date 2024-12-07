#include<iostream>
#include<stack>
using namespace std;

template<class T>
void pushAtBottom(stack<T> &s, T value) {
    if(s.empty()) {
        s.push(value);
        return;
    }
    T temp = s.top();
    s.pop();
    pushAtBottom(s, value);
    s.push(temp);
}

int main() {
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);

    pushAtBottom(s, 1);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}