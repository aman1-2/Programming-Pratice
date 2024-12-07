#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template <class T>
void reversalRecursively(queue<T> &qu) { //O(n) is time complexity in same queue
    if(qu.empty())    return;

    T temp = qu.front();
    qu.pop();
    reversalRecursively(qu);
    qu.push(temp);
}

template <class T>
void stackReversal(queue<T> &qu) {
    stack<T> st;
    while(!qu.empty()) {
        st.push(qu.front());
        qu.pop();
    }

    while(!st.empty()) {
        qu.push(st.top());
        st.pop();
    }
}

int main() {
    queue<int> qu;
    for(int i=1; i<=5; i++) {
        qu.push(i);
    }

    stackReversal(qu);

    while(!qu.empty()) {
        cout<<qu.front();
        qu.pop();
    }

    return 0;
}