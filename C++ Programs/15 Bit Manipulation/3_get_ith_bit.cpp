#include<iostream>
using namespace std;

int getIthBit(int num, int ith_bit){
    int form_mask = 1<<ith_bit;

    if((num & form_mask))   return 1;
    else    return 0;
}
int main(){
    int num;
    cin>>num;
    
    int ith_bit;
    cin>>ith_bit;

    cout<<"The ith bit is: "<<getIthBit(num, ith_bit);

    return 0;
}