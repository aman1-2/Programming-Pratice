#include<iostream>
#include<vector>
using namespace std;

/**
 * Space Complexity -> O(n)
 * Time Complexxity -> O(n log n)
 */

void merge(vector<int> &v, int st_idx, int mid, int ed_idx){
    vector<int> temp;
    int i = st_idx, j = mid+1;
    while(i<=mid and j<=ed_idx){
        if(v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        } else{
            temp.push_back(v[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(v[i]);
        i++;
    }

    while(j<=ed_idx){
        temp.push_back(v[j]);
        j++;
    }

    for(int i=0, idx=st_idx; idx<=ed_idx; i++, idx++)    v[idx] = temp[i];

    return;
}

void mergeSort(vector<int> &v, int st_idx, int ed_idx){
    if(st_idx >= ed_idx)    return;
    int mid = st_idx + (ed_idx - st_idx) / 2;
    mergeSort(v, st_idx, mid);
    mergeSort(v, mid+1, ed_idx);
    merge(v, st_idx, mid, ed_idx);
}

int main(){
    vector<int> v = {3, 5, 4, 2, 1};
    mergeSort(v, 0, v.size()-1);
    for(int i=0; i<v.size(); i++)   cout<<v[i]<<" ";
    return 0;
}