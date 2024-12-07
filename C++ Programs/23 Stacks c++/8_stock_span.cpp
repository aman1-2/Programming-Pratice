#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stockSpan(vector<int> stock) {
    vector<int> span;
    stack<int> st;
    span.push_back(1);
    st.push(0);

    for(int idx=1; idx<stock.size(); idx++) {
        //Finding previous high value.
        while(!st.empty() && stock[idx] >= stock[st.top()]) {
            st.pop();
        }

        if(st.empty()) {
            span.push_back(idx+1);
        } else {
            span.push_back(idx - st.top());
            st.push(idx);
        }
    }

    return span;
}

int main() {
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> ans = stockSpan(stock);
    for(int ele:ans) {
        cout<<ele<<" ";
    }
    return 0;
}