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

template<class T>
void reverseSt(stack<T> &s) {
    if(s.empty()) {
        return;
    }

    T temp = s.top();
    s.pop();
    reverseSt(s);
    pushAtBottom(s, temp);
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    reverseSt(s);

    while(!s.empty()) {
        cout<<s.top();
        s.pop();
    }

    return 0;
}

/*
Stack -> 1 2 3
1 2 3
3 2 1
reverse -> 3 2 1*/