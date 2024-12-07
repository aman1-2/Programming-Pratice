/*WAP to check whether the given number is prime or not.*/
#include<iostream>
using namespace std;
int main(){
    int num;
    bool flag = true;
    cout<<"Num = ";
    cin>>num;

    for(int i=2; i<num; i++){
        if(num % i == 0){
            flag = false;
            break;
        }
    }

    if(flag){
        cout<<"Its a Prime Number";
    } else{
        cout<<"Not a Prime Number";
    }

    return 0;
}