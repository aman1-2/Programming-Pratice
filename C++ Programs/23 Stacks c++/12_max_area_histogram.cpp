/*Given an array of integers heights representing the histogram's bar height where the width of 
each bar is 1, return the area of the largest rectangle in the histogram.

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is, which has an area = 10 units.

Input: heights = [2,4]
Output: 4

Constraints:

* 1 <= heights.length <= 105
* 0 <= heights[i] <= 104

Here when we want to find the next smallest element in the left side -> We should have the 
knowledge of elements present before that -> Hence we traverse the array from left to right.

And when we want to find the next smallest element in the right side -> we traverse the array from
right to left.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maxAreaHistogram(vector<int> heights) { //O(n)
    int n = heights.size();

    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> st;

    //Next smallest left calculation
    nsl[0] = -1;
    st.push(0);

    for(int i=1; i<heights.size(); i++) {
        while(!st.empty() && heights[i] <= heights[st.top()]) {
            st.pop();
        }
        if(st.empty()) {
            nsl[i] = -1;
            st.push(i);
        } else {
            nsl[i] = st.top();
            st.push(i);
        }
    }

    //Empty the stack before using it again
    while(!st.empty()) {
        st.pop();
    }

    //Next smallest right calculation
    nsr[n-1] = n;
    st.push(n-1);

    for(int i=n-2; i>=0; i--) {
        while(!st.empty() && heights[i] <= heights[st.top()]) {
            st.pop();
        }
        if(st.empty()) {
            nsr[i] = n;
            st.push(i);
        } else {
            nsr[i] = st.top();
            st.push(i);
        }
    }

    int maxArea = 0;
    for(int i=0; i<n; i++) {
        int ht = heights[i];
        int wd = nsr[i] - nsl[i] - 1;
        int area = ht * wd;
        maxArea = max(area, maxArea);
    }

    return maxArea;
}

int main() {
    vector<int> vec = {2,1,5,6,2,3};
    cout<<maxAreaHistogram(vec);
    return 0;
}