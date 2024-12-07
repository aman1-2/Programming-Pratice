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

    for(int i=1; i<=rows; i++){
        //Spaces
        for(int j=1; j<i; j++){
            cout<<"  ";
        }

        //Stars 
        for(int j=rows-i+1; j>0; j--){
            cout<<"* ";
        }

        cout<<endl;
    }

    return 0;
}