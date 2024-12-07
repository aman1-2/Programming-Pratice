/*WAP to print the subarrays of an array?
Subarray -> is the continuous part of the array.*/

#include<iostream>
using namespace std;
void printSubarray(int arr[], int size){}
int main(){
    int arr[] = {1, 2, 3, 4, 5};

    for(int i=0; i<5; i++){
        cout<<"Start = "<<i<<"  Ending points = ";
        for(int j=i; j<5; j++){
            cout<<j<<", ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0; i<5; i++){
        for(int j=i; j<5; j++){
            cout<<"Subarray -> [";
            for(int k=i; k<=j; k++){
                cout<<arr[k]<<", ";
            }
            cout<<"]";
            cout<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}