/*
Count Total ways to tile a floor (2 x n) with a tile (2 x 1).
*/

#include<iostream>
using namespace std;

int waysTiling(int num){
    return (num == 0 || num == 1)?(1):waysTiling(num-1) + waysTiling(num-2);
}

int main(){
    cout<<waysTiling(5);
    return 0;
}