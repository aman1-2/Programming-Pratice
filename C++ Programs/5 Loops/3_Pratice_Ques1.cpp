/*WAP to print the Square pattern using the for loop?*/
#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"rows=";
    cin>>rows;

    for(int i=0; i<rows; i++){
        for(int i=0; i<rows; i++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }

    return 0;
}