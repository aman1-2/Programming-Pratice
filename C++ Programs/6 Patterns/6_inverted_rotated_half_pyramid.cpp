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

    for(int i=1; i<=rows; i++){
        //Spaces
        for(int j=rows-i; j>=1; j--){
            cout<<"  ";
        }

        //Stars 
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        cout<<endl;
    }

    return 0;
}