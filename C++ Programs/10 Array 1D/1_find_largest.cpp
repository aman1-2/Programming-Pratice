/*WAP to find the largest among all of these.*/
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int size,largest=INT_MIN;
    cin>>size;
    int arr[size];

    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    for(int i=0; i<size; i++){
        if(arr[i]>largest)  largest = arr[i];
    }

    cout<<"The largest element is: "<<largest;

    return 0;
}