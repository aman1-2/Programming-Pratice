/*
*        *
**      **
***    ***
****  ****
**********
**********
****  ****
***    ***
**      **
*        *
*/
#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Rows = ";
    cin>>rows;

    //Upper Part
    for(int i=1; i<=rows; i++){
        //Stars
        for(int j=1; j<=i; j++)
            cout<<"*";

        //Spaces
        for(int j=1; j<=2*(rows-i); j++)
            cout<<" ";

        //Stars
        for(int j=1; j<=i; j++)
            cout<<"*";
        
        cout<<endl;
    }

    //Down (inverted) Pattern
    for(int i=rows; i>0; i--){
        //Stars
        for(int j=1; j<=i; j++)
            cout<<"*";
        
        //Spaces
        for(int j=1; j<=2*(rows-i); j++)
            cout<<" ";
        
        //Stars
        for(int j=1; j<=i; j++)
            cout<<"*";
        
        cout<<endl;
    }

    return 0;
}