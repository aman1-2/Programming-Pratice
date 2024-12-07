/*For any 3 digit number check whether it’s an Armstrong number or not. 
Armstrong number is a number that is equal to the sum of cubes of its digits.
Eg : 371 is an armstrong number. 
3*3*3 + 7*7*7 + 1*1*1 = 371 */
#include<iostream>
using namespace std;
int main(){
    int num, temp, sum = 0;
    cout<<"num=";
    cin>>num;

    temp = num;

    while(temp > 0){
        int last_digit;
        last_digit = temp % 10;
        sum += (last_digit*last_digit*last_digit);
        temp = temp / 10;
    }
    if(sum == num){
        cout<<"It is an Armstrong Number.";
    } else{
        cout<<"It is not an Armstrong Number.";
    }

    return 0;
}