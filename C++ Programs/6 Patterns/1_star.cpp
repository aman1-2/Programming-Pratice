/*
* 
* *
* * *
* * * *
* * * * *
*/

#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Rows = ";
    cin>>rows;

    for(int i=0; i<rows; i++){
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}