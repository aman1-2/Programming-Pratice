/*
Question 1 : Print the 0-1 Triangle Pattern. 
For n = 5
1
01
101
0101
10101
*/
#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Rows = ";
    cin>>rows;
    

    for(int i=1; i<=rows; i++){
        //When row is even
        if(i%2 == 0){
            for(int j=1; j<=i; j++){
                //when column is even
                if(j%2 == 0)
                    cout<<"1 ";
                else 
                    cout<<"0 ";
            }
        } else{ //when row is Odd
            for(int j=1; j<=i; j++){
                //when volum is even
                if(j%2 == 0)
                    cout<<"0 ";
                else
                    cout<<"1 ";
            }
        }

        cout<<endl;
    }

    // for(int i=1; i<=rows; i++){
    //     for(int j=1; j<=i; j++){
    //         cout<<val<<" ";
    //         val = !val;
    //     }
    //     cout<<endl;
    // } This method has error.

    return 0;
}