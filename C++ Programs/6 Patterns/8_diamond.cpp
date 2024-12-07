/*
   *
  ***
 *****
*******
*******
 *****
  ***
   *
*/
#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Rows = ";
    cin>>rows;

    // //Outer loop -> for Upper-part
    // for(int i=1; i<=rows; i++){
    //     //Spaces
    //     for(int j=rows-i; j>=1; j--){
    //         cout<<" ";
    //     }

    //     //Stars
    //     for(int j=1; j<=i; j++){
    //         cout<<"*";
    //     }

    //     //Spaces
    //     for(int j=1; j<=i-1; j++){
    //         cout<<"*";
    //     }

    //     cout<<endl;
    // }

    // //Outer loop -> for Down-part
    // for(int i=1; i<=rows; i++){
    //     //Spaces
    //     for(int j=1; j<i; j++){
    //         cout<<" ";
    //     }

    //     //Stars
    //     for(int j=rows-i+1; j>0; j--){
    //         cout<<"*";
    //     }

    //     //Spaces
    //     for(int j=rows-i; j>0; j--){
    //         cout<<"*";
    //     }

    //     cout<<endl;
    // }


    //Alternate Method
    //Upper Pyramid
    for(int i=1; i<=rows; i++){
        //Spaes
        for(int j=1; j<=rows-i; j++)
            cout<<" ";

        //Starts
        for(int j=1; j<=2*i-1; j++){
            cout<<"*";
        }

        cout<<endl;
    }

    //Down (inverted) pyramid
    for(int i=rows; i>=1; i--){
        //Spaes
        for(int j=1; j<=rows-i; j++)
            cout<<" ";

        //Starts
        for(int j=1; j<=2*i-1; j++){
            cout<<"*";
        }

        cout<<endl;
    }


    return 0;
}