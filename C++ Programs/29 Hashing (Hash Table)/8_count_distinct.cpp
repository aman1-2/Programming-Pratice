#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int countDistinct(vector<int> &vec) {
    unordered_set<int> uns;
    //Inserting the elements from array into the set.
    for(int i=0; i<vec.size(); i++) {
        uns.insert(vec[i]);
    }
    //Printing the elements from set.
    for(auto ele: uns) {
        cout<<ele<<" ";
    }

    return uns.size();
}

int another(vector<int> &vec) {
    //Inserting the elements from array into the set.
    unordered_set<int> uns(vec.begin(), vec.end());

    //Printing the elements from set.
    for(auto ele: uns) {
        cout<<ele<<" ";
    }

    return uns.size();
}

int main() {
    vector<int> vec = {4,3,2,5,6,7,3,4,2,1};
    cout<<"\n"<<countDistinct(vec)<<endl;
    cout<<"\n"<<another(vec);
    return 0;
}