/*This Question is Important as it has been asked in Companies like Amazon and Google.*/

#include<iostream>
using namespace std;

int countSetBits(int num){
    int sum = 0;
    while(num>0){
        sum += num % 2;
        num /= 2;
    }

    return sum;
}

int method2(int num){
    int count = 0;

    while(num>0){
        int last_dig = (num & 1);
        count += last_dig;

        num = num>>1;
    }

    return count;
}

int main(){
    cout<<method2(15);
    
    return 0;
}