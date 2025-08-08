#include<iostream>
using namespace std;

string decimalToBinary(int num) {
    string result = "";

    while(num > 0) {
        if(num % 2 == 0)    result = '0' + result;
        else    result = '1' + result;
        num = num >> 1; // or num /= 2;
        //we are right shifting 1 because we need to remove LSB and then work on the rest of the bits.   
    }

    return result;
}

int main() {
    int num = 5;
    cout<<decimalToBinary(num)<<endl;

    int num1 = 7;
    cout<<decimalToBinary(num1)<<endl;

    int num2 = 8;
    cout<<decimalToBinary(num2)<<endl;
    return 0;
}