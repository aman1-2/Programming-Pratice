/*WAP to search an element from the array using the binary search?*/
#include<iostream>
using namespace std;
int main(){
    int size, search;
    cout<<"Size: ";
    cin>>size;
    cout<<"Search: ";
    cin>>search;
    
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    int start = 0, end = size-1;
    bool flag=false;
    while(start<=end){
        int mid = (start+end)/2;
        if(search == arr[mid]){
            flag=true;
            cout<<"The element is present at index: "<<mid;
            break;
        }
        else if(arr[mid] > search){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    if(!flag)   cout<<"The element is not present in the array.";

    return 0;
}