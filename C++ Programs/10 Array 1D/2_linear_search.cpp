/*WAP to search an element for the Array using linear search?*/
#include<iostream>
using namespace std;
int main(){
    int size, search;
    cout<<"Size: ";
    cin>>size;
    cout<<"Search: ";
    cin>>search;

    int arr[size];
    bool flag = false;

    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    for(int i=0; i<size; i++){
        if(arr[i] == search){
            flag = true;
            cout<<"The search element is present at the index: "<<i;
            break;
        }
    }

    if(!flag)   cout<<"The search element is not present in the array.";

    return 0;
}