/*WAP to reverse an array with using an extra space.*/
#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Size: ";
    cin>>size;

    int arr[size];

    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    for(int i=0,j=size-1; i<=size/2,j>=size/2; i++,j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        // cout<<"arr[i]"<<"="<<arr[i]<<endl;
        // cout<<"arr[j]"<<"="<<arr[j]<<endl;
    }

    cout<<"Reversed array is:-"<<endl;
    for(int ele : arr){
        cout<<ele<<" ";
    }

    return 0;
}