/*
* * * * * * 
*         * 
*         * 
*         * 
* * * * * * 
*/
#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Rows = ";
    cin>>rows;

    for(int i=0; i<rows; i++){
        for(int j=0; j<=rows; j++){
            if(i==0 || j==0 || i==rows-1 || j==rows){
                cout<<"* ";
            } else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }

    return 0;
}