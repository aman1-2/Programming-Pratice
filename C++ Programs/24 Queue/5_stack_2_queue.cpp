#include<iostream>
#include<queue>
using namespace std;

class List {
    queue<int> qu1;
    queue<int> qu2;

public:
    void push(int data) {
        if(qu1.empty()) {
            qu1.push(data);
            return;
        }

        while(!qu1.empty()) {
            qu2.push(qu1.front());
            qu1.pop();
        }

        qu1.push(data);

        while(!qu2.empty()) {
            qu1.push(qu2.front());
            qu2.pop();
        }

        return;
    }

    void pop() {
        if(qu1.empty()) return;
        qu1.pop();
        return;
    }

    int top() {
        if(qu1.empty()) return -1;
        return qu1.front();
    }

    bool empty() {
        return qu1.empty();
    }
};

int main() {
    List st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}