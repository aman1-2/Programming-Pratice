/**
 * PROBLEM STATEMENT :- Given an integer n, Find the maximum power of two that is smaller than n.
*/

#include<iostream>
using namespace std;

int max_2_power(int num) {
    int ans = -1;

    while(num > 0) {
        ans = num;
        num = (num & num-1);
    }

    return 2*ans; //Multiplication with 2 will give you just greater power of 2.
}

int main() {
    int num = 100;
    cout<<max_2_power(num)<<endl;

    int num1 = 90;
    cout<<max_2_power(num1)<<endl;

    int num2 = 30;
    cout<<max_2_power(num2)<<endl;

    return 0;
}