#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int num;
    bool flag = true;
    cout<<"Num = ";
    cin>>num;

    for(int i=2; i<sqrt(num); i++){
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