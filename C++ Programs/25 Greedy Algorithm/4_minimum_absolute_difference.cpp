#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minAbsDiff(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int absAns = 0;

    for(int i=0; i<a.size(); i++) {
        absAns += abs(a[i] - b[i]);
    }

    return absAns;
}

int main() {
    vector<int> a = {4, 1, 8, 7};
    vector<int> b = {2, 3, 6, 5};

    cout<<minAbsDiff(a, b);
    return 0;
}