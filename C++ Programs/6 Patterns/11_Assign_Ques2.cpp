/*
Question 2 : Print the Rhombus Pattern. 
For n = 5
    *****
   *****
  *****
 *****
*****
*/

#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Rows = ";
    cin>>rows;

    for(int i=1; i<=rows; i++){
        //Spaces
        for(int j=1; j<=rows-i; j++)
            cout<<"  ";

        //Stars
        for(int j=1; j<=rows; j++)
            cout<<"* ";

        cout<<endl;
    }

    return 0;
}