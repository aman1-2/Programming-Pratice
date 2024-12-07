/*
Question 3 : Print the Palindromic Pattern with Numbers. 
For n = 5
    1
   212
  32123
 4321234
543212345
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
            cout<<" ";
        
        //Backward counting
        for(int j=i; j>=1; j--)
            cout<<j;
        
        //Forward Counting
        for(int j=2; j<=i; j++)
            cout<<j;

        cout<<endl;
    }

    return 0;
}