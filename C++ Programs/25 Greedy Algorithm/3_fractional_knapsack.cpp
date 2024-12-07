#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

//Time complexity is - O(nlogn)
int knapsack(vector<int> &value, vector<int> &weight, int totalWeight) {
    vector<pair<int, int>> ratio; //Vector for storing the ratio pair with the value/weight ratio and index the items
    //Pair's first value is provided the value of the ratio and the second value is provided the index of the item.
    for(int idx=0; idx<value.size(); idx++) {
        ratio.push_back(make_pair(value[idx]/weight[idx], idx));
    }
    sort(ratio.begin(), ratio.end(), compare); //Sorting the ratio vector with the custom compare function.

    int ans = 0; //Variable for holding the maximum value cost.
    for(int i=0; i<ratio.size(); i++) {
        int idx = ratio[i].second;
        if(weight[idx] < totalWeight){ //If the weight of the item is less then total weight then add the complete item
            ans += value[idx]; //Adding its value
            totalWeight -= weight[idx]; //Reducing the total weight from the items weight.
        } else { //On the last item adding a fraction part only its the last value being added int the bag or knapsack.
            ans += ratio[i].first * totalWeight;
            totalWeight = 0;
        }
    }

    return ans;
}

int main() {
    vector<int> weight = {100, 60, 120};
    vector<int> value = {20, 10, 30};
    int totalWeight = 50;
    
    cout<<knapsack(weight, value, totalWeight);

    return 0;
}