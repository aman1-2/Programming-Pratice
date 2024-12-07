#include<iostream>
using namespace std;

int fastExponentiation(int num, int power){
    int ans = 1;

    while(power > 0){
        int last_digit = power & 1;

        if(last_digit)  ans = ans * num;

        num *= num;
        power = power >> 1;
    }

    return ans;
}

int main(){
    cout<<fastExponentiation(2, 4);
    
    return 0;
}