/*
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
*/
#include<iostream>
using namespace std;
int main(){
    int rows, count=1;
    cout<<"Rows = ";
    cin>>rows;

    for(int i=0; i<rows; i++){
        for(int j=0; j<=i; j++){
            cout<<count++<<" ";
        }
        cout<<endl;
    }

    return 0;
}