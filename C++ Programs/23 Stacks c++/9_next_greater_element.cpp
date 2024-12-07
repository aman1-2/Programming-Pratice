//Similar to stock span the only change here is - we need to traverse the array here in backward direction from right to left.
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &vec) { //O(n)
    vector<int> ans(vec.size());
    stack<int> st;
    int n = vec.size();
    st.push(vec[n - 1]);
    ans[n - 1] = -1;

    for(int idx = n-2; idx >= 0; idx--) {
        while(st.top() < vec[idx]) {
            st.pop();
        }
        if(!st.empty()){
            ans[idx] = st.top();
            st.push(vec[idx]);
        } else {
            ans[idx] = -1;
            st.push(vec[idx]);
        }
    }

    return ans;
}

int main() {
    vector<int> vec = {6, 8, 0, 1, 3};
    cout<<"Vector input:-";
    for(int ele:vec) {
        cout<<ele<<" ";
    }
    cout<<endl;

    vector<int> ans = nextGreaterElement(vec);
    cout<<"Answer vector storing next greater element:- ";
    for(int ele:ans) {
        cout<<ele<<" ";
    }

    return 0;
}