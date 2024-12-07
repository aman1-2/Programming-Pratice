#include<iostream>
#include<vector>
using namespace std;

/**
 * Space Complexity -> 1
 * Time Complexxity -> O(n log n) [Average]
 * Time Complexxity -> O(n^2) [Worst]
 */

int partition(vector<int> &v, int st_idx, int ed_idx){
    int i = st_idx-1;
    int pivot = v[ed_idx];

    for(int j=st_idx; j<ed_idx; j++){
        if(v[j] <= pivot){
            i++;
            swap(v[i], v[j]);
        }
    }

    i++;
    swap(v[i], v[ed_idx]);

    return i; //pivot Index is i.
}

void quickSort(vector<int> &v, int st_idx, int ed_idx){
    if(st_idx >= ed_idx)    return;

    int pivot_idx = partition(v, st_idx, ed_idx);

    quickSort(v, st_idx, pivot_idx-1);
    quickSort(v, pivot_idx+1, ed_idx);
}

int main(){
    vector<int> v = {3, 5, 4, 2, 1};
    quickSort(v, 0, v.size()-1);
    for(int i=0; i<v.size(); i++)   cout<<v[i]<<" ";
    return 0;
}