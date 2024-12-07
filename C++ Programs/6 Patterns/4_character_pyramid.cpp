/*
A 
B C 
D E F 
G H I J 
K L M N O 
*/
#include<iostream>
using namespace std;
int main(){
    int rows;
    char ch = 'A';
    cout<<"Rows = ";
    cin>>rows;

    for(int i=0; i<rows; i++){
        for(int j=0; j<=i; j++){
            cout<<ch++<<" ";
        }
        cout<<endl;
    }

    return 0;
}