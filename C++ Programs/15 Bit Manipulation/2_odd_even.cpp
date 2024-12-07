#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter a number which you want to check is odd or even: ";
    cin>>num;

    int res = (num & 1);
    // cout<<(num & 1)<<endl;
    if(res == 1)    cout<<"It's a Odd Number.";
    else cout<<"It's a even number.";

    return 0;
}