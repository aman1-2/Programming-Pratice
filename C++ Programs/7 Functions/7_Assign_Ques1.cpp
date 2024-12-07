/*
Question 1 : Write a function to check if a number is a palindrome in C++. 
(121 is a palindrome, 321 is not)
A number is called a palindrome if the number is equal to the reverse of a number.
Eg : 121 is a palindrome because the reverse of 121 is 121 itself. On the other hand, 321
is not a palindrome because the reverse of 321 is 123, which is not equal to 321.
*/
#include<iostream>
using namespace std;

bool isPalindrome(int num){
    int temp = num, sum=0;

    while(temp>0){
        int last_digit = temp % 10;
        sum = sum*10 + last_digit;
        temp /= 10;
    }

    if(sum == num)  return true;
    else    return false;

}

int main(){
    int num;
    cout<<"Num = ";
    cin>>num;

    if(isPalindrome(num))   cout<<"Is Palindrome";
    else    cout<<"Not a Palindrome";

    return 0;
}