#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compareFun(pair<int, int> p1, pair<int, int> p2) { //This compare function will tell on what basis the sorting should take place.
    return p1.second < p2.second; //ascending order based on second element of the pair.
}

int main() {
    vector<int> start = {0, 1, 3};
    vector<int> end = {9, 2, 4};
    vector<pair<int, int>> activites;

    for(int i=0; i<start.size(); i++) {
        activites.push_back(make_pair(start[i],end[i]));
    }

    sort(activites.begin(), activites.end(), compareFun);

    for(int i=0; i<activites.size(); i++) {
        cout<<"A"<<i<<" : ("<<activites[i].first<<", "<<activites[i].second<<")"<<endl;
    }

    return 0;
}