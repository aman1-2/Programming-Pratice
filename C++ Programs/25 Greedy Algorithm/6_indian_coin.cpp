#include<iostream>
#include<vector>
using namespace std;

int canonicalApproach(vector<int> coin, int value) { //Time complexity -> O(n), n is number of coins.
//But let's say if there was a need of sorting the array in that case our time complexity would be of O(nlogn).
    int n = coin.size()-1;
    int ans = 0;
    for(int i=n; i>=0 && value > 0; i--) {
        if(value >= coin[i]) {
            ans += (value / coin[i]);
            value %= coin[i]; 
        }
    }

    return ans;
}

int main() {
    vector<int> coin = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int value = 1099;
    cout<<canonicalApproach(coin, value);
    return 0;
}