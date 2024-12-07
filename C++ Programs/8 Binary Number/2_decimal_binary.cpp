/*WAP for converting a Decimal Number to the Binary Number*/
#include<iostream>
using namespace std;

int decimalBinary(int deci_num){
    int sum=0, power=1;
    while(deci_num>0){
        int remainder = deci_num % 2;
        sum += remainder*power;
        deci_num /= 2;
        power *= 10;
    }

    return sum;
}
int main(){
    int num;
    cout<<"Enter the Decimal Number: ";
    cin>>num;

    cout<<"Binary form is: "<<decimalBinary(num);

    return 0;
}