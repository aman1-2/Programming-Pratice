/*
* * * * * 
* * * * 
* * * 
* * 
*
*/
#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Rows = ";
    cin>>rows;

    // for(int i=rows; i>0; i--){
    //     for(int j=i; j>0; j--){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    //Alternate method
    //Formula -> rows - i + 1 (why used it as we are moving down the rows the characters 
    //with the rows goes on decreasing that's why i with negative sign)

    for(int i=1; i<=rows; i++){
        for(int j=rows-i+1; j>0; j--){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}