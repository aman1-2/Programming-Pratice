#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void unionSet(vector<int> vec1, vector<int> vec2) {
    unordered_set<int> set;
    for(int i=0; i<vec1.size(); i++)    set.insert(vec1[i]);
    for(int i=0; i<vec2.size(); i++)    set.insert(vec2[i]);
    
    for(auto ele:set)   cout<<ele<<" ";

    return;
}

void intersectionSet(vector<int> vec1, vector<int> vec2) {
    unordered_set<int> set1(vec1.begin(), vec1.end());
    
    for(int i=0; i<vec2.size(); i++) {
        if(set1.find(vec2[i]) != set1.end()){ //Find function returns an iterator and if it is not equal to end then it means the element exists.
            cout<<vec2[i]<<" ";
            set1.erase(vec2[i]);
        }
    }

    return;
}

int main() {
    vector<int> vec1 = {7, 3, 9};
    vector<int> vec2 = {6, 3, 9, 2, 9, 4};
    unionSet(vec1, vec2);
    cout<<endl;
    intersectionSet(vec1, vec2);
    return 0;
}