/*WAP to make a Income Tax Calculator??

Since we are going to have the percentage value in points therefore there's a need for storing
it inside the floating point data type.*/
#include<iostream>
using namespace std;
int main(){
    float income;
    cout<<"income=";
    cin>>income;
    
    if(income<500000){
        cout<<"0'%' tax";
    }
    else if(income>=500000 && income<1000000){
        cout<<"20'%' tax"<<endl;
        cout<<"Paying amount = "<<((20.0/100.0)*income);
    }
    else{
        cout<<"30'%' tax"<<endl;
        cout<<"Paying amount = "<<((30.0/100.0)*income);
    }

    return 0;
}