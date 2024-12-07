#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

//Time Complexity O(nlogn)
int maxChainLength(vector<pair<int, int>> &vec) {
    sort(vec.begin(), vec.end(), compare);
    int count = 1;
    int currEnd = vec[0].second;

    for(int i=1; i<vec.size(); i++) {
        if(vec[i].first > currEnd) {
            count++;
            currEnd = vec[i].second;
        }
    }

    return count;
}

int main() {
    vector<pair<int, int>> vec = {{5, 24}, {39, 60}, {5, 28}, {27, 40}, {50, 90}};
    cout<<maxChainLength(vec);
    return 0;
}