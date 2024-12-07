/*WAP to convert the given binary number into the decimal form? */

#include<iostream>
#include<cmath>
using namespace std;

int binaryDecimal(int bin_num){
    int power=0, sum=0;
    while(bin_num>0){
        int last_digit = bin_num % 10;
        sum += last_digit * pow(2,power++);
        bin_num /= 10;
    }

    //We can to do without the use of pow function from cmath.
    int powers=1; //currently this one shows 2^0 then we will multiple 2 in it which will increase the power by 1.
    while(bin_num>0){
        int last_digit = bin_num % 10;
        sum += last_digit * powers;
        powers *= 2;
        bin_num /= 10;
    }

    return sum; //This sum at the end is only our Decimal Number.
}
int main(){
    int num;
    cout<<"Enter the Binary number: ";
    cin>>num;

    cout<<"The Decimal form is: "<<binaryDecimal(num);

    return 0;
}