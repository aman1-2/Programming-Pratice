#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrome(char str[], int size){
    int st_ptr = 0, en_ptr = size-1;
    while(st_ptr < en_ptr){
        if(str[st_ptr] != str[en_ptr])  return false;
        st_ptr++, en_ptr--;
    }

    return true;
}

int main(){
    char str[] = "ma'am";

    cout<<isPalindrome(str, strlen(str));

    return 0;
}