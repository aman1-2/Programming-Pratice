/*Question 4 : For a positive N , WAP that prints all the prime numbers from 2 to N.
(Assume N >= 2)*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int num;
    bool flag = true;
    cout<<"Num = ";
    cin>>num;

    for(int i=2; i<=num; i++){
        for(int j=2; j<=sqrt(i); j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<i<<" "<<endl;
        } else{
            flag = true;
        }
    }

    return 0;
}